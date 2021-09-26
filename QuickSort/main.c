#include "QuickSort.h"
#include <stdio.h>
int main(void)
{
    int A[7] = {4, 1, 3, 2, 5, 4, 3};
    //int B[12] = {13, 19, 9, 5, 12, 8, 7, 4, 11, 2, 6, 21};
    random_quick_sort(A, 0, 6);
    //random_quick_sort(B, 0, 11);
    int i;
    for (i = 0; i < 7; i++)
    {
        printf("%d ", A[i]);
    }
    /***for (i = 0; i < 12; i++)
        printf("%d ", B[i]);***/
    return 0;
}