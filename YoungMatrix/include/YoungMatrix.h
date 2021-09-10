#ifndef YOUNGMATRIX_H
#define YOUNGMATRIX_H
typedef struct YoungMatrix
{
    int *YoungMatrix;
    int m;
    int n;
    int total;
} YM;
int down(YM *ym, int i);
int right(YM *ym, int i);
int up(YM *ym, int i);
int left(YM *ym, int i);
int extract_min(YM *ym);
void insert(YM *ym, int key);
void sort(int **m, int size);
int find(YM *ym, int target);
#endif