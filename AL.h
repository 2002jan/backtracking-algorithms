#ifndef ADJACENCY_LIST
#define ADJACENCY_LIST

#include <stdint.h>
#include <stdlib.h>


typedef struct AdjacencyListItem
{
    int j;
    struct AdjacencyListItem *next;
} ALI;

ALI **AdjacencyList;
int AdjacencyListCount;

void addALEdge(int i, int j);

void initAList(int n)
{
    int i, j;

    AdjacencyList = (ALI **)calloc(n, sizeof(ALI *));
    AdjacencyListCount = n;
}

void addALEdge(int i, int j)
{
    if (AdjacencyList == NULL)
        return;

    ALI *newEdge = (ALI *)calloc(1, sizeof(ALI));

    newEdge->j = j;

    if (AdjacencyList[i] == NULL)
    {
        AdjacencyList[i] = newEdge;
        return;
    }

    ALI *current = AdjacencyList[i];

    while (current->next != NULL)
    {
        current = current->next;
    }

    current->next = newEdge;

    return;
}

void addUDEdge(int i, int j)
{
    addALEdge(i, j);
    addALEdge(j, i);
}

void freeAdjacencyList()
{
    if (AdjacencyList == NULL)
        return;

    int i;

    for (i = 0; i < AdjacencyListCount; i++)
    {
        ALI *current = AdjacencyList[i], *prev;

        while (current != NULL)
        {
            prev = current;
            current = prev->next;
            free(prev);
        }
    }

    free(AdjacencyList);
}

uint8_t checkALEdge(int i, int j)
{
    ALI *current;

    current = AdjacencyList[i];

    while (current != NULL)
    {
        if (current->j == j)
            return 1;

        current = current->next;
    }

    return 0;
}

void removeALEdge(int i, int j)
{
    if (AdjacencyList == NULL)
        return;

    if (AdjacencyList[i] == NULL)
        return;

    ALI *current = AdjacencyList[i], *prev;

    if (current->j == j)
    {
        AdjacencyList[i] = current->next;
        free(current);
        return;
    }

    while (current != NULL && current->j != j)
    {
        prev = current;
        current = current->next;
    }

    if (current == NULL)
        return;
    
    prev->next = current->next;

    free(current);
    
    return;
}

void removeUDEdge(int i, int j)
{
    removeALEdge(i, j);
    removeALEdge(j, i);
}

int countEdges(int i)
{
    int count = 0;

    ALI *current = AdjacencyList[i];

    if (current == NULL) return count;

    while (current != NULL)
    {
        count++;
        current = current->next;
    }

    return count;
    
}

#endif