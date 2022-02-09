#include <stdio.h>

void fill(int* vector, int size, int value)
{
    int i;
    for(i=0; i<size; i++)
        vector[i] = value;
}




int find(int* vector, int size, int value)
{
    int i;
    for(i=0; i<size && vector[i] != value; i++);

    if (i<size)
        return i ;
    else
        return -1;

}

