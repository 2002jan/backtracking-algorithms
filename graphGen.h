#ifndef GRAPH_GEN
#define GRAPH_GEN

#include "AL.h"
#include <stdio.h>

void randomGraph(int n)
{

    initAList(n);

    int i;

    for(i = 1; i < n; i++)
    {
        printf("%d -> %d\n", i, rand() % i);
    }

}

#endif