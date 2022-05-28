#ifndef HAMILTONIAN_TOUR
#define HAMILTONIAN_TOUR

#include "AL.h"
#include <stdio.h>
#include <time.h>

#define TIMEOUTTIME 300

clock_t algoStart;

int8_t hamiltonianCycle();
int8_t findHamiltonianCycle(int *path, int currentPos);
int8_t checkPathArray(int pos, int v, int *path);
void printPath(int *path);

int8_t hamiltonianCycle()
{
    int i, *path = (int *)malloc(sizeof(int) * AdjacencyListCount);

    for (i = 0; i < AdjacencyListCount; i++)
        path[i] = -1;

    path[0] = 0;

    algoStart = clock();

    if (findHamiltonianCycle(path, 1) == 0)
    {
        return 0;
    }

    // printPath(path);

    free(path);
    return 1;
}

int8_t findHamiltonianCycle(int *path, int currentPos)
{
    clock_t runtime = clock() - algoStart;

    if ((double) runtime / CLOCKS_PER_SEC > TIMEOUTTIME){
        return 0;
    }
    

    if (currentPos == AdjacencyListCount)
    {
        if (checkALEdge(path[currentPos - 1], path[0]))
            return 1;
        else
            return 0;
    }

    ALI *current = AdjacencyList[path[currentPos - 1]];

    while (current != NULL)
    {
        if (checkPathArray(currentPos, current->j, path))
        {
            path[currentPos] = current->j;

            if(findHamiltonianCycle(path, currentPos + 1) == 1)
                return 1;

            path[currentPos] = -1;
        }
        
        current = current->next;
    }
    

    return 0;
}

int8_t checkPathArray(int pos, int v, int *path)
{
    int i;

    for(i = 0; i < pos; i++)
        if(path[i] == v)
            return 0;

    return 1;
}

void printPath(int *path)
{
    int i;

    printf("%d ", path[0]);

    for (i = 1; i < AdjacencyListCount; i++)
        printf("-> %d ", path[i]);

    printf("\n");
}

#endif