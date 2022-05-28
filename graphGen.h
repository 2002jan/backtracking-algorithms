#ifndef GRAPH_GEN
#define GRAPH_GEN

#include "AL.h"
#include <stdio.h>
#include <time.h>
#include <stdlib.h>

void randomGraph(int n, float sat);
int getMatrixIndex(int i, int j, int n);

void randomGraph(int n, float sat)
{
    initAList(n);

    char buffer[255];

    sprintf(buffer, "python eug.py %d %0.2f", n, sat);
    system(buffer);

    FILE *outputFile = fopen("./output.txt", "r");

    if (outputFile == NULL)
    {
        printf("Could not open output.txt");
        exit(1);
    }

    int i, j;

    while (1)
    {
        fgets(buffer, 255, outputFile);

        sscanf(buffer, "%d -> %d", &i, &j);

        if (i == -1 || j == -1)
            break;

        addALEdge(i, j);
        addALEdge(j, i);
    }
}

void randomHamGraph(int n, float sat)
{
    initAList(n);

    char buffer[255];

    sprintf(buffer, "python ham.py %d %0.2f", n, sat);
    system(buffer);

    FILE *outputFile = fopen("./outputham.txt", "r");

    if (outputFile == NULL)
    {
        printf("Could not open output.txt");
        exit(1);
    }

    int i, j;

    while (1)
    {
        fgets(buffer, 255, outputFile);

        sscanf(buffer, "%d -> %d", &i, &j);

        if (i == -1 || j == -1)
            break;

        addALEdge(i, j);
        addALEdge(j, i);
    }
}

#endif