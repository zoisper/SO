#include<unistd.h>
#include<sys/wait.h>
#include<stdio.h>
#include<fcntl.h>
#include<string.h>

int mysystem(char *command){
	
	char *exec_args[20];
	char *string;
	int i=0 , fork_ret, exec_ret, wait_ret, status, res;

	string = strtok(command, " ");
	
	while(string!=NULL)
	{
		exec_args[i] = string;
		string = strtok(NULL, " ");
		i++;
	}

	exec_args[i] = NULL;

	fork_ret = fork();
	
	if(fork_ret == 0)
	{
		exec_ret = execvp(exec_args[0],exec_args);	
		_exit(exec_ret);
	}
	
	else
	{	
		wait(&status);
		return WEXITSTATUS(status);

		/*if(fork_ret != -1)
		{
			wait_ret = wait(&status);
			if(WIFEXITED(status))
				res = WEXITSTATUS(status);
			
			else
				res = -1;
		}
		else
			res = -1;*/
	}

	return -1;
}


int main(){
	char comando1[] = "ls -l -a -h";
	char comando2[] = "sleep 10";
	char comando3[] = "ps";
	int ret;

	printf("a executar mysystem para %s\n", comando1);
	ret = mysystem(comando1);
	printf("ret %d\n",ret);
	printf("a executar mysystem para %s\n", comando2);
	ret = mysystem(comando2);
	printf("ret %d\n",ret);
	printf("a executar mysystem para %s\n", comando3);
	ret = mysystem(comando3);
	printf("ret %d\n",ret);

	return 0;
	
}