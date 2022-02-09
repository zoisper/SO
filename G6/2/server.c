#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <stdio.h>
#include <fcntl.h>

#define SIZE 100

int main(){

	char buffer[SIZE];
	int bytesRead = 0;

	mkfifo("fifo", 0666);
	int server_client = open("fifo", O_RDONLY);
	int client_server = open("fifo", O_WRONLY);
	int logs = open("logs.txt", O_CREAT | O_WRONLY);
	
	while((bytesRead = read(server_client, buffer, 100 ))>0)
		write(logs, buffer, bytesRead);

	close(logs);
	close(client_server);
	close(server_client);

	return 0;
}