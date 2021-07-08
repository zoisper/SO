#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <stdio.h>
#include <fcntl.h>
#include <string.h>


int main(int argc , char *argv[]){

	if(argc <2)
		return 0;


	int client_server = open("fifo", O_WRONLY);
	write(client_server, argv[1], strlen(argv[1]));
	close(client_server);
	

	return 0;
}