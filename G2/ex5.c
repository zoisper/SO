#include<unistd.h>
#include<stdio.h>
#include<sys/wait.h>
#include<stdlib.h>


int main(){

	int i, status;
	pid_t pid;
	
	for(i = 0; i<10; i++){
		
		if(fork() != 0 ){
			pid = wait(&status);
			printf("pid: %d filho - pid: %d - ordem: %d\n",getpid(), pid, WEXITSTATUS(status));
			_exit(i-1);
		}
	}
		
	return i-1;
}