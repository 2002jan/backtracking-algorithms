#ifndef EULERIAN_TOUR
#define EULERIAN_TOUR

#include "AL.h"

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


}

void findEulerCycle(int start)
{
    int i, count = countEdges(start);

}

#endif