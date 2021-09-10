#include "YoungMatrix.h"
#include <stdlib.h>
#include <stdio.h>
#include <limits.h>
int up(YM *ym, int i) { return (i / ym->m == 0) ? -1 : i - ym->m; }
int left(YM *ym, int i) { return (i % ym->m == 0) ? -1 : i - 1; }
int down(YM *ym, int i) { return (i / ym->m == ym->n - 1) ? ym->m * ym->n : i + ym->m; }
int right(YM *ym, int i) { return ((i + 1) % ym->m == 0) ? ym->m * ym->n : i + 1; }
int extract_min(YM *ym)
{
    int temp = ym->YoungMatrix[0];
    ym->YoungMatrix[0] = INT_MAX;
    int key = INT_MAX;
    int i = 0;
    int min;
    int eles = ym->m * ym->n;
    int rightnum, downnum, mininum;
    while (1)
    {
        rightnum = (right(ym, i) == eles) ? INT_MAX : ym->YoungMatrix[right(ym, i)];
        downnum = (down(ym, i) == eles) ? INT_MAX : ym->YoungMatrix[down(ym, i)];
        if (key > rightnum)
        {
            min = right(ym, i);
            mininum = ym->YoungMatrix[min];
        }
        else
        {
            min = i;
            mininum = key;
        }
        if (mininum > downnum)
            min = down(ym, i);
        ym->YoungMatrix[i] = ym->YoungMatrix[min];
        if (min == i)
        {
            ym->YoungMatrix[i] = key;
            break;
        }
        i = min;
    }
    ym->total--;
    return temp;
}
void sort(int **m, int size)
{
    int i, j;
    int *Yon;
    Yon = (int *)malloc(sizeof(int) * size * size);
    YM ym = {Yon, size, size, 0};
    for (i = 0; i < size; i++)
        for (j = 0; j < size; j++)
        {
            insert(&ym, m[i][j]);
        }
    for (i = 0; i < size * size; i++)
    {
        printf("%d ", ym.YoungMatrix[i]);
    }
    for (i = 0; i < size; i++)
        for (j = 0; j < size; j++)
        {
            m[i][j] = extract_min(&ym);
            printf("%d ", m[i][j]);
        }
    for (i = 0; i < size * size; i++)
    {
        printf("%d ", ym.YoungMatrix[i]);
    }
}
void insert(YM *ym, int key)
{
    if (ym->total == ym->m * ym->n)
        ;
    else
    {
        int i = ym->total;
        ym->total++;
        int upnum, leftnum, maxinum;
        int max;
        while (1)
        {
            upnum = (up(ym, i) == -1) ? INT_MIN : ym->YoungMatrix[up(ym, i)];
            leftnum = (left(ym, i) == -1) ? INT_MIN : ym->YoungMatrix[left(ym, i)];
            if (key < upnum)
            {
                max = up(ym, i);
                maxinum = ym->YoungMatrix[max];
            }
            else
            {
                max = i;
                maxinum = key;
            }
            if (maxinum < leftnum)
                max = left(ym, i);
            ym->YoungMatrix[i] = ym->YoungMatrix[max];
            if (i == max)
            {
                ym->YoungMatrix[max] = key;
                break;
            }
            i = max;
        }
    }
}
int find(YM *ym, int key)
{
    if (key < ym->YoungMatrix[0])
        return -1;
    else
    {
        int i = 0;
        int min;
        int eles = ym->m * ym->n;
        int rightnum, downnum, mininum;
        while (1)
        {
            rightnum = (right(ym, i) == eles) ? INT_MAX : ym->YoungMatrix[right(ym, i)];
            downnum = (down(ym, i) == eles) ? INT_MAX : ym->YoungMatrix[down(ym, i)];
            if (key >= rightnum || key >= downnum)
            {
                if (rightnum < downnum)
                {
                    min = right(ym, i);
                }
                else
                    min = down(ym, i);
            }
            else
            {
                min = i;
            }
            /***
            if (key >= rightnum)
            {
                min = right(ym, i);
                mininum = ym->YoungMatrix[min];
            }
            else
            {
                min = i;
                mininum = key;
            }
            if (mininum >= downnum)
                min = down(ym, i);
                ***/
            if (i == min)
                break;
            i = min;
        }
        if (ym->YoungMatrix[i] == key)
            return i;
        else
            return -1;
    }
}