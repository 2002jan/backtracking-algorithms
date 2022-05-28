#include "graphGen.h"

int main()
{
    randomGraph(10, 0.5f);

    int i;

    for(i = 0; i < AdjacencyListCount; i++)
    {
        ALI *start = AdjacencyList[i];

        printf("%d -> ", i);

        while (start != NULL)
        {
            printf("%d, ", start->j);

            start = start->next;
        }
        printf("\n");
        
    }

    return 0;
}