#include "QuickSort.h"
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
int random(int begin, int end)
{
    srand(time(NULL));
    return (int)(rand() % (end - begin + 1) + begin);
}
void exchange(int *A, int i, int j)
{
    int temp = A[i];
    A[i] = A[j];
    A[j] = temp;
}
int *partition(int *A, int p, int r, int *get)
{
    int x = A[r];
    int q = p - 1;
    int t = p - 1;
    int j, k;
    for (j = p; j <= r - 1; j++)
    {
        if (A[j] < x)
        {
            q++;
            t++;
            exchange(A, j, t);
            exchange(A, t, q);
        }
        else if (A[j] == x)
        {
            t++;
            exchange(A, t, j);
        }
        for (k = p; k <= r; k++)
            printf("%d ", A[k]);
        printf("\n");
    }
    t++;
    exchange(A, t, r);
    for (k = p; k <= r; k++)
        printf("%d ", A[k]);
    printf("\n");
    get[0] = q;
    get[1] = t;
    return get;
}
int *random_partition(int *A, int p, int r, int *get)
{
    int m = random(p, r);
    exchange(A, m, r);
    return partition(A, p, r, get);
}
void quick_sort(int *A, int p, int r)
{
    if (p < r)
    {
        int get[2];
        partition(A, p, r, get);
        quick_sort(A, p, get[0]);
        quick_sort(A, get[1] + 1, r);
    }
}
void random_quick_sort(int *A, int p, int r)
{
    if (p < r)
    {
        int get[2];
        random_partition(A, p, r, get);
        random_quick_sort(A, p, get[0]);
        random_quick_sort(A, get[1] + 1, r);
    }
}