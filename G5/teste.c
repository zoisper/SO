#include<unistd.h>
#include<stdio.h>
#include <string.h>
#define SIZE 100

//grep -v ˆ# /etc/passwd | cut -f7 -d: | uniq | wc -l.


void closePipes(int fildes[][2], int n )
{
	int i;
	for (i=0; i <n; i++)
	{
		close(fildes[i][0]);
		close(fildes[i][1]);
	}

}


int getComandos(char args[], char *argumentos[SIZE])
{

	char *token;
	int comandos = 0;


	token = strtok(args, "|");
	while(token != NULL)
	{
		
		argumentos[comandos] = token;
		token = strtok(NULL, "|");
		comandos++;
	}

	return comandos;

}

void mysystem(char arg[])
{
	char *token;
	char *argumentos[SIZE];
	int comandos = 0;
	token = strtok(arg, " ");
	while(token)
	{
		argumentos[comandos] = token;
		comandos++;
		token = strtok(NULL, " ");
	}
	argumentos[comandos] = NULL;
	execvp(argumentos[0], argumentos);
}

int main(){

	char comando[] = "grep -v ˆ# /etc/passwd | cut -f7 -d: | uniq | wc -l";
	char *argumentos[SIZE];


	int fildes[3][2];
	
	pipe(fildes[0]);
	pipe(fildes[1]);
	pipe(fildes[2]);

	int comandos = getComandos(comando, argumentos);


	if (fork() == 0)
	{

		if(fork()==0 )
		{
			
			if(fork() == 0)
			{
				
				dup2(fildes[2][1],1);
				closePipes(fildes, 3);
				mysystem(argumentos[0]);
			}
			
			else
			{

				dup2(fildes[2][0],0);
				dup2(fildes[1][1],1);
				closePipes(fildes, 3);
				mysystem(argumentos[1]);
			}
		
		}
		
		else
		{
			dup2(fildes[1][0],0);
			dup2(fildes[0][1],1);
			closePipes(fildes, 3);
			mysystem(argumentos[2]);
		}

	}
	
	else
	{
		dup2(fildes[0][0],0);
		closePipes(fildes, 3);
		mysystem(argumentos[3]);
	}




return 0;

}