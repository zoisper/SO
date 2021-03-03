#include<unistd.h>
#include<fcntl.h>
#include<stdio.h>

#define MAXBUFFER 10000

int main(int argc, char *argv[])
{

	int fd1, fd2;
	ssize_t res;
	char buff[MAXBUFFER];

	fd1 = open(argv[1], O_RDONLY);
	fd2 = open(argv[2], O_CREAT | O_WRONLY, 0600);

	if (fd1 == -1)
	{
		perror("open:");
		return -1;
	}
	

	while ((res=read(fd1, buff, MAXBUFFER)) != 0)
		write(fd2, buff, MAXBUFFER);
	

	close(fd2);
	close(fd1);
	
	return 0;



}
