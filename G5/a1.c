#include<unistd.h>
#include<stdio.h>
#include <string.h>
#define SIZE 100

//grep -v ˆ# /etc/passwd | cut -f7 -d: | uniq | wc -l


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




int main(int argc, char *argv[]){

	if (argc < 2)
		return 0;

	char *argumentos[SIZE];
	int comandos = getComandos(argv[1], argumentos);
	int fildes[comandos-1][2];
	int i;
	
	for(i=0; i<comandos; i++)
	{
		
			if(i==0 && comandos >1)
			{
				pipe(fildes[i]);
				if (fork() == 0) 
				{
					dup2(fildes[i][1],1);
					close(fildes[i][0]);
					close(fildes[i][1]);

					mysystem(argumentos[i]);
				}
				else
				{
					close(fildes[i][0]);
					close(fildes[i][1]);
				} 
			}

			else if (i == comandos-1)
			{
				pipe(fildes[i]);
				if (fork() == 0) 
				{
					dup2(fildes[i-1][0],0);
					close(fildes[i-1][0]);
					mysystem(argumentos[i]);
				}
				else
				 
					close(fildes[i-1][0]);
			}
			
			else
			{
				pipe(fildes[i]);
				if (fork() == 0) 
				{
					dup2(fildes[i-1][0],0);
					dup2(fildes[i][1],1);
					close(fildes[i][1]);
					close(fildes[i-1][0]);
					mysystem(argumentos[i]);
				}
				else 
				{
					close(fildes[i][1]);
					close(fildes[i-1][0]);
				}
			}
		


		}


	
return 0;

}