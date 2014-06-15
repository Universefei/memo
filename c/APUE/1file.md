#All are Files

##文件io

- int open(o)
- int creat()
- int close()
- off_t lseek(a)
- ssize_t read()
- ssize_t write()


### open()

int open(const char *pathname, int oflag, .../* mode_t mode */ );

- #include <fcntl.h>
- oflag (can combined by "|")
	- O_RDONLY
	- O_WRONLY
	- O_RDWR
	- O_APPEND
	- O_CREAT
	- O_EXCL
	- O_TRUNC
	- O_NOCTTY
	- O_NONBLOCK
	- O_DSYNC
	- O_RSYNC
	- O_SYNC



### creat()

int creat(const char * pathname, mode_t mode);

- #include <fcntl.h>
- mode_t mode(you might think of `chmod`command in shell ,mod)
	- S_IRUER
	- S_IWUSR
	- S_IXUSR
	- S_IRGRP
	- S_IWGRP
	- S_IXGRP
	- S_IROTH
	- S_IWOTH
	- S_IXOTH
- can be substituted by
	`open(pathname, O_RDWR | O_CREAT | O_TRUNC, mode);`



### close()

inc close(int filedes)


