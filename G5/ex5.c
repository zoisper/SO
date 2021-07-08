#include<unistd.h>
#include<stdio.h>

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

int main(){


	int fildes[3][2];
	
	pipe(fildes[0]);
	pipe(fildes[1]);
	pipe(fildes[2]);


	if (fork() == 0)
	{

		if(fork()==0 )
		{
			
			if(fork() == 0)
			{
				
				dup2(fildes[2][1],1);
				closePipes(fildes, 3);
				execlp("grep","grep", "-v", "ˆ#", "/etc/passwd", NULL );
			}
			
			else
			{

				dup2(fildes[2][0],0);
				dup2(fildes[1][1],1);
				closePipes(fildes, 3);
				execlp("cut", "cut", "-f7", "-d:", NULL);
			}
		
		}
		
		else
		{
			dup2(fildes[1][0],0);
			dup2(fildes[0][1],1);
			closePipes(fildes, 3);
			execlp("uniq","uniq", NULL);
		}

	}
	
	else
	{
		dup2(fildes[0][0],0);
		closePipes(fildes, 3);
		execlp("wc", "wc", "-l", NULL);
	}




return 0;

}