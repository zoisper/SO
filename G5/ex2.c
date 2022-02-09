#include<unistd.h>
#include<stdio.h>
#include<sys/wait.h>
#include<stdlib.h>
#include<time.h>

char buffer[100];
char line[] = "Ola Mundo";

int main(){

	int fildes[2];
	
	pipe(fildes);

	
	if(fork() == 0)
	{
		close(fildes[1]);
		
		while(read(fildes[0],&buffer, sizeof(buffer)) >0)
			printf("%s\n",buffer);
		
		
		close(fildes[0]);
		_exit(0);

	}
	

	else
	{
		close(fildes[0]);
		write(fildes[1], &line, sizeof(line));
		close(fildes[1]);
		wait(NULL);

	}



	return 0;

}