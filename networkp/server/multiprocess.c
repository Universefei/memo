/* web_server_process.c */
#include <sys/types.h>
#include <sys/socket.h>
#include <sys/stat.h>
#include <sys/wait.h>
#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <string.h>
#include <unistd.h>
#include <netinet/in.h>

#define BUFSIZE 1024
#define MAX_QUE_CONN_NM 10

int start_server(int portnum);
void sigchld_handler(int sig);
int process_request(char *rq, int fd);
int resp_cannot_do(int fd);
int not_exist(char *f);
int resp_do_404(char *item, int fd);
int is_a_dir(char *f);
int resp_do_ls(char *dir, int fd);
int is_a_cgi_file(char *f);
int resp_do_exec(char *prog, int fd);
int resp_do_cat(char *f, int fd);
void pack_header(FILE *fp, char *extension);
char *get_filename_extension(char *f);
void ignore_others(FILE *fp);

int main(int argc, char *argv[])
{
	int sock;
	int portnum;
	int fd;
	pid_t pid;
	FILE *fpin;
	char request[BUFSIZE];
											
	if (argc != 2) {
		fprintf(stderr, "usage: %s <portnum>\n", argv[0]);
		exit(-1);
	}

	portnum = atoi(argv[1]);
	sock = start_server(portnum);
	signal(SIGCHLD, sigchld_handler);

	while(1) {
		fd = accept(sock, NULL, NULL);

		while ((pid = fork()) == -1);

		if (pid == 0) {
		fpin = fdopen(fd, "r");
		memset(request, 0, sizeof(request));
		fgets(request, BUFSIZE, fpin);
		ignore_others(fpin);
		process_request(request, fd);
		fclose(fpin);
		exit(0);
		}
		close(fd);
	}

	close(sock);
	exit(0);
}

int start_server(int portnum)
{
	struct sockaddr_in server_sockaddr;
	int sockfd;
	int i = 1;
								
	/* create socket link */
	if ((sockfd = socket(AF_INET, SOCK_STREAM, 0)) == -1) {
		perror("socket");
		exit(-1);
	}
									
	server_sockaddr.sin_family = AF_INET;
	server_sockaddr.sin_port = htons(portnum);
	server_sockaddr.sin_addr.s_addr = INADDR_ANY;
	bzero(server_sockaddr.sin_zero, 8);
													
	setsockopt(sockfd, SOL_SOCKET, SO_REUSEADDR, &i, sizeof(i));
														
	if (bind(sockfd, (struct sockaddr *)&server_sockaddr, sizeof(struct sockaddr)) == -1) {
		perror("bind");
		exit(-1);
	}
															
	if (listen(sockfd, MAX_QUE_CONN_NM) == -1) {
		perror("listen");
		exit(-1);
	}
																
	return sockfd;
}

void sigchld_handler(int sig)
{
	while (waitpid(-1, 0, WNOHANG) > 0);
	return;
}

int process_request(char *rq, int fd)
{
	char cmd[BUFSIZE];
	char arg[BUFSIZE];

	strcpy(arg, "./");
	if (sscanf(rq, "%s %s", cmd, arg + 2) != 2) {
		return 1;
	}
									
	if (strcmp(cmd, "GET") != 0) {
		resp_cannot_do(fd);
	} else if (not_exist(arg)) {
		resp_do_404(arg, fd);
	} else if (is_a_dir(arg)) {
		resp_do_ls(arg, fd);
	} else if (is_a_cgi_file(arg)) {
		resp_do_exec(arg, fd);
	} else {
		resp_do_cat(arg, fd);
	}
										
	return 0;
}

int resp_cannot_do(int fd)
{
	FILE *fp = fdopen(fd, "w");
	fprintf(fp, "HTTP/1.1 501 Not Implemented\r\n");
	fprintf(fp, "Content-type: text/plain\r\n");
	fprintf(fp, "\r\n");
	fprintf(fp, "That command is not yet implemented\r\n");
	fclose(fp);
	return 0;
}

int not_exist(char *f)
{
	struct stat info;
	return (stat(f, &info) == -1);
}

int resp_do_404(char *item, int fd)
{
	FILE *fp = fdopen(fd, "w");
	fprintf(fp, "HTTP/1.1 404 Not Found\r\n");
	fprintf(fp, "Content-type: text/plain\r\n");
	fprintf(fp, "\r\n");
	fprintf(fp, "The item you requested: %s\r\nis not found\r\n", item);
	fclose(fp);
	return 0;
}

int is_a_dir(char *f)
{
	struct stat info;
	return (stat(f, &info) != -1 && S_ISDIR(info.st_mode));
}

int resp_do_ls(char *dir, int fd)
{
	FILE *fp = fdopen(fd, "w");
	pack_header(fp, "text/plain");
	fprintf(fp, "\r\n");
	fflush(fp);
									
	dup2(fd, 1);
	dup2(fd, 2);
	close(fd);
	execlp("ls", "ls", "-l", dir, NULL);
	perror(dir);
	return1;
}

int is_a_cgi_file(char *f)
{
					return(strcmp(get_filename_extension(f), "cgi") == 0);	
}

int resp_do_exec(char *prog, int fd)
{
	FILE *fp = fdopen(fd, "w");
	pack_header(fp, NULL);
	fflush(fp);

	dup2(fd, 1);
	dup2(fd, 2);
	close(fd);
	execl(prog, prog, NULL);
	perror(prog);
	return1;
}

int resp_do_cat(char *f, int fd)
{
	int c;
	char *extension = get_filename_extension(f);
	char *content = "text/plain";
	FILE *fpsock, *fpfile;

	if (strcmp(extension, "html") == 0) {
		content = "text/html";
	} else if (strcmp(extension, "gif") == 0) {
		content = "text/gif";
	} else if (strcmp(extension, "jpg") == 0) {
		content = "text/jpg";
	} else if (strcmp(extension, "jpeg") == 0) {
		content = "text/jpeg";
	}
										
	fpsock = fdopen(fd, "w");
	fpfile = fopen(f, "r");
	if (fpsock != NULL && fpfile != NULL) {
		pack_header(fpsock, content);
		fprintf(fpsock, "\r\n");
																						
		while ((c = getc(fpfile)) != EOF) {
			putc(c, fpsock);
		}
		fclose(fpfile);
		fclose(fpsock);
		return 0;
	}
return 1;
}

void pack_header(FILE *fp, char *extension)
{
	fprintf(fp, "HTTP/1.1 200 OK\r\n");
	if (extension)
	fprintf(fp, "Content-type: %s\r\n", extension);
}

char *get_filename_extension(char *f)
{
	return strrchr(f, '.') + 1; 
}

void ignore_others(FILE *fp)
{
	char buf[BUFSIZE];
						
	fgets(buf, BUFSIZE, fp);
	while(strcmp(buf, "\r\n")) 
		fgets(buf, BUFSIZE, fp);
return;
}
