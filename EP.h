#ifndef EULERIAN_TOUR
#define EULERIAN_TOUR

#include "AL.h"
#include <stdio.h>

void printEulerCycle();
void findEulerCycle(int start);
int8_t isValidEdge(int start, int v);
int dfsCount(int v, int8_t *visited);

void printEulerCycle()
{
    int i, start = 0;

    for (int i = 0; i < AdjacencyListCount; i++)
    {
        if (countEdges(i) % 2 == 1)
        {
            start = i;
            break;
        }
    }

    findEulerCycle(start);
}

void findEulerCycle(int start)
{
    ALI *current = AdjacencyList[start];

    while (current != NULL)
    {
        int target = current->j;

        if (isValidEdge(start, target))
        {
            printf("%d -> %d, ", start, target);

            removeUDEdge(start, target);
            findEulerCycle(target);
        }

        current = current->next;
    }
    
}

int8_t isValidEdge(int start, int v)
{
    if (countEdges(start) == 1)
        return 1;

    int8_t *visited = (int8_t *)calloc(AdjacencyListCount, sizeof(int8_t));
    int c1 = dfsCount(start, visited);
    free(visited);

    removeUDEdge(start, v);
    visited = (int8_t *)calloc(AdjacencyListCount, sizeof(int8_t));

    int c2 = dfsCount(start, visited);
    free(visited);

    if (c1 > c2)
        return 0;
    else
        return 1;
}

int dfsCount(int v, int8_t *visited)
{
    visited[v] = 1;
    int c = 1;

    ALI *current = AdjacencyList[v];

    while (current != NULL)
    {
        if (!visited[current->j])
            c = c + dfsCount(current->j, visited);

        current = current->next;
    }

    return c;
}

#endif