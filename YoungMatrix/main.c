#include <stdlib.h>
#include <stdio.h>
#include "YoungMatrix.h"
int main(void)
{
    int **m;
    m = (int **)malloc(sizeof(int *) * 2);
    for (int a = 0; a < 2; a++)
        m[a] = (int *)malloc(sizeof(int) * 2);
    int i, j;
    int n[2][2] = {3, 1, 4, 7};
    for (i = 0; i < 2; i++)
        for (j = 0; j < 2; j++)
            m[i][j] = n[i][j];
    sort(m, 2);
    printf("after sorted:\n");
    for (i = 0; i < 2; i++)
        for (j = 0; j < 2; j++)
            printf("%d ", m[i][j]);
    int yon[4] = {1, 2, 3, 4};
    YM ym = {yon, 2, 2, 4};
    printf("4 in Yong's %dth position", find(&ym, 4));
    return 0;
}