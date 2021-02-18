#include <stdio.h>
#include <stdlib.h>
#include "array.h"
#include "interface.h"

#define MAX 50
#define BUFF_SIZE 100


int v1[MAX]; // vector armazenados numa variável global.

char buff[BUFF_SIZE];

int main()
{
    
    int * v2 = malloc (100 * sizeof(int));  // vector em memória alocada dinamicamente.
    
    
    int v3[MAX];    // vector armazenado numa variável automatica.
    for(int i=0; i<MAX; i++)
        v3[i] = i;  
    
    showArray(v3, MAX);
    printf("Digite elemento a encontrar\n");
    getMessage(buff, BUFF_SIZE);
    int key = atoi(buff);
    int index = find(v3+10, MAX-10, key);
    showIndex(key, index);

    
    

    return 0;
}