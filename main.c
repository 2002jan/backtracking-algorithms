#include "graphGen.h"
#include "EP.h"
#include <time.h>
#include "csvExporter.h"

int main()
{

    int i, jp, jn = 6, runs = 10;
    float j[] = {0.2, 0.3, 0.4, 0.6, 0.8, 0.95};

    int *ns;
    double *times[jn];
    ns = (int *)calloc(runs, sizeof(int));

    for (jp = 0; jp < jn; jp++)
    {
        times[jp] = (double *)calloc(runs, sizeof(double));

        printf("\nEC for p=%f\n", j[jp]);
        for (i = 1; i <= runs; i++)
        {
            int n = 25 * i;
            ns[i - 1] = n;
            randomGraph(n, j[jp]);


            clock_t begin = clock();
            printEulerCycle();
            clock_t end = clock();

            times[jp][i - 1] = (double)(end - begin) / CLOCKS_PER_SEC * 1000;

            printf("%d - %fms\n", n, times[jp][i - 1]);

            freeAdjacencyList();
        }
    }

    exportToCsvEP(ns, times, j, runs, jn, "EG");

    return 0;
}