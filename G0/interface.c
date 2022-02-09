#include <string.h>
#include <stdio.h>

void showArray (int * vector, int size)
{
    int i;
    for(i=0; i<size; i++)
        printf("%d ", vector[i]);
    putchar('\n');
}

void getMessage(char * message, int size)
{
    
    while (fgets (message, size, stdin) == NULL)
        printf("Menssagem Incorreta\n");
}

void showIndex (int key, int index)
{
    if (index != -1)
        printf("O elemento: %d encontra-se na posição: %d\n", key, index );
    else 
        printf("O elemento: %d não existe no array\n", key); 
}