#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <fcntl.h>
#include <unistd.h>

#include "must/apue.h"
#define BUFSZ 10

int
main(int argc, char *argv[]) {
				
				int fd,offset;
				char buf[BUFSZ];

				fd = open ("feilunzhou.txt",O_RDWR);

				printf("please input your offset!\n");
				scanf("%d",&offset);
				lseek(fd,offset,SEEK_SET);

				if(read(fd,buf,BUFSZ) != BUFSZ)
								perror("read error!");
				printf("%s\n",buf);
				return 0;
}


