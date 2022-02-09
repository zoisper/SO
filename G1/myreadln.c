
#include<unistd.h>
#include<fcntl.h>
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#define MAXBUFFER 1000

//ex 3
ssize_t readln(int fd, char *line, ssize_t size)
{

	ssize_t res = 0;
	ssize_t i = 0;

	while((res=read(fd, &line[i], size))>0 && ( (char*) line[i] != '\n'))
		i += res;

	return i;
	
}

//ex 4
ssize_t readln2(int fd, char *line, ssize_t size)
{

	ssize_t res = 0;
	ssize_t j = 0;
	char local[MAXBUFFER];

	while((res = read(fd, local, size))>0)
	{
		for(int i=0; i<res; i++)
		{
			if((char*) local[i] != '\n')
			{
				line[j] = local[i];
				j++;
			}
			else
				return j;
		}
	}
	return j;
	
}



int main(int argc, char const *argv[])
{
	
	char buffer[MAXBUFFER];
	
	int fd1 = open(argv[1], O_RDONLY);
	ssize_t tam = (ssize_t) atoi(argv[2]);

	/*if (fd1 == -1)
	{
		perror("open:");
		return -1;
	}*/

	ssize_t result = readln2(fd1, buffer, tam);
	
	buffer[result] = '\n';
	write(1, buffer, result+1);

	close(fd1);



	return 0;
}