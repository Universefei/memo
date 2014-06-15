#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>
#include <string.h>

#include "must/apue.h"

#define BUFFSIZE 4096

int
main(void) {
	int n,fd,k,input;
	char buf[BUFFSIZE];
	//char input[10];

	fd = open("feilunzhou.txt",O_RDWR) ;

	while ((n = read(fd,buf,BUFFSIZE)) > 0)
					if (write(STDOUT_FILENO, buf, n) != n)
									perror("write error");

	//memset(&input,'8',10);
	input=0;
	printf("please input your number and offset\n");
	scanf ("%d %d",&input,&k);

	printf("the size of your input string is %d",sizeof(input));

	lseek(fd,k,SEEK_SET);
	write(fd,&input,sizeof(input));
	if (n < 0)
					perror("read error");

	exit(0);
}
