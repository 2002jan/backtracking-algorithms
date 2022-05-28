#include "graphGen.h"
#include "HP.h"
#include "csvExporter.h"

int main()
{

    
    int i, jp, jn = 6, runs = 10, avgFrom = 5, k;
    float j[] = {0.2, 0.3, 0.4, 0.6, 0.8, 0.95};

    int *ns;
    double *times[jn];
    ns = (int *)calloc(runs, sizeof(int));

    for (jp = 0; jp < jn; jp++)
    {
        times[jp] = (double *)calloc(runs, sizeof(double));

        printf("\nHC for p=%f\n", j[jp]);
        for (i = 1; i <= runs; i++)
        {
            int n = 25 * i;
            ns[i - 1] = n;
            times[jp][i - 1] = 0;
            for(k = 0; k < avgFrom; k++)
            {
                randomGraph(n, j[jp]);


                clock_t begin = clock();
                hamiltonianCycle();
                clock_t end = clock();

                times[jp][i - 1] += (double)(end - begin) / CLOCKS_PER_SEC * 1000;

                freeAdjacencyList();
            }
            
            times[jp][i - 1] /= avgFrom;

            printf("%d - %fms\n", n, times[jp][i - 1]);
        }
    }

    exportToCsvEP(ns, times, j, runs, jn, "HG");
}