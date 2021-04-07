#include<unistd.h>
#include<sys/wait.h>
#include<stdio.h>
#include<fcntl.h>
#include<string.h>

int main(int argc, char *argv[]){
	int i, ret;
	for(i=1; i<argc; i++){

		if(fork() == 0){
			ret = execlp(argv[i],argv[i],NULL);
			perror("Reached error");
			_exit(ret);
		}

	}

	for(i=1; i<argc; i++)
		wait(NULL);

	return 0;


}