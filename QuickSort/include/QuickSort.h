#ifndef QUICKSORT_H
#define QUICKSORT_H
int random(int, int);
int *partition(int *, int, int, int *);
void quick_sort(int *, int, int);
int *random_partition(int *, int, int, int *);
void random_quick_sort(int *, int, int);
void exchange(int *, int, int);
#endif