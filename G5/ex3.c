#include<unistd.h>
#include<stdio.h>
#include<sys/wait.h>
#include<stdlib.h>
#include<time.h>
#define SIZE 100
char buffer[SIZE];

ssize_t readln(int fildes, char *buf, size_t nbyte)
{
	ssize_t res = 0;
	int i = 0;
	while(i< nbyte && (res = read(fildes, &buf[i], 1))>0)
	{
		if(((char*)buf)[i] =='\n')
				return i +  1;
		i+= res;
	}

	return i;
}


int main(int argc, char *argv[]){


	int fildes[2];
	int res;
	
	pipe(fildes);

	
	if(fork() == 0)
	{
		close(fildes[1]);
		dup2(fildes[0],0);
		close(fildes[0]);

		execlp("wc","wc",NULL);
	
		_exit(0);

	}
	
	else
	{
		close(fildes[0]);
		
	while((res = readln(0, buffer, SIZE))>0)

		write(fildes[1], buffer, SIZE);
			
		
		close(fildes[1]);
		wait(NULL);

	}



	return 0;

}