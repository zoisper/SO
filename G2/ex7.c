#include<unistd.h>
#include<stdio.h>
#include<sys/wait.h>
#include<stdlib.h>
#include<time.h>
#define SIZE 5

int find(int v[], int N, int x){
	for(int i=0; i<N; i++)
		if (v[i] == x)
			return 1;
	return 0;
}

void fillMatrix(int mat[SIZE][SIZE]){
	for(int i=0; i<SIZE; i++)
		for(int j=0; j<SIZE; j++)
			mat[i][j] = rand() %10;
	}

void showMatrix(int mat[SIZE][SIZE]){
	for(int i=0; i<SIZE; i++){
		for(int j=0; j<SIZE; j++)
			printf("%d ",mat[i][j]);
		putchar('\n');
	}
}


int main(){

	srand(time(NULL));
	int i, status, toFind = rand()%10;
	int mat[SIZE][SIZE];
	
	fillMatrix(mat);
	
	for(i = 0; i<SIZE; i++){
		if(fork() == 0){
			int found = find(mat[i], SIZE, toFind);
			_exit(found);
		}
	}
	
	printf("Elemento a procurar: %d\n",toFind);
	showMatrix(mat);

	for(i=0; i<SIZE; i++){
		wait(&status);
		if(WEXITSTATUS(status) == 1)
			printf("Encontrado na linha: %d\n", i);
	}
		
	return 0;
}