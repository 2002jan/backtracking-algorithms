#ifndef GRAPH_GEN
#define GRAPH_GEN

#include "AL.h"
#include <stdio.h>
#include<time.h>

void randomGraph(int n, float sat);
int getMatrixIndex(int i, int j, int n);

void randomGraph(int n, float sat)
{
    srand(time(0));

    if (n >= RAND_MAX)
    {
        printf("Matrix size not supported!\n");
        exit(1);
    }

    initAList(n);

    int i, j;

    int8_t *aMatrix = calloc(n * n, sizeof(int8_t))

    for (i = 1; i < n; i++)
    {
        j = rand() % i;

        addALEdge(i, j)
        aMatrix[getMatrixIndex(i, j)] = 1;
    }

    free(aMatrix);
}

int getMatrixIndex(int i, int j, int n)
{

    return (n * i) + j;

}

#endif