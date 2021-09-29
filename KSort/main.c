#include <stdio.h>
#include "k_sort.h"
#include <stdlib.h>
int main(void)
{
    int k[11] = {3, 2, 1, 9, 7, 8, 5, 4, 6, 12, 11};
    int m;
    m = 3;
    item i[11];
    for (int p = 0; p < 11; p++)
    {
        i[p].key = p % m;
        i[p].value = k[p];
    }
    int *count;
    count = (int *)malloc(sizeof(int) * m);
    k_sort(i, m, 11, count);

    int j;
    for (j = 0; j < 11; j++)
        printf("%d %d\n", i[j].value, i[j].key);

    k_heap h;
    h.lenth = m;
    item *heap;
    heap = (item *)malloc(sizeof(item) * h.lenth);
    h.heap = heap;
    h.record = count;
    h.k = m;

    build_heap_min(&h, i, 11);
    k_to1sort(&h, k);
    for (j = 0; j < 11; j++)
        printf("%d ", k[j]);
    return 0;
}