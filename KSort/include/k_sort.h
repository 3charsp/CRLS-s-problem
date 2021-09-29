#ifndef K_SORT_H
#define K_SORT_H
#define PARENT(i) (i - 1) / 2
#define LEFT(i) (2 * i + 1)
#define RIGHT(i) (2 * i + 2)
typedef struct
{
    int key;
    int value;
} item;
typedef struct
{
    int size;
    int k;
    int *indices;
    item *item;
    int lenth;
} k_sort_state;
typedef struct
{
    item *heap;
    int lenth;
    item *i;
    int size;
    int *record; //all value eq k
    int k;
} k_heap;
void k_to1sort(k_heap *, int *);
item extract_min(k_heap *);
void heap_add(k_heap *, int);
void build_heap_min(k_heap *, item *, int);
void min_heapify(k_heap *, int);
void k_sort(item *i, int k, int size, int *record);
void merge_k_sort(k_sort_state *kss, int begin, int end, int i);
void merge(k_sort_state *kss, int begin, int end, int mid, int i);
#endif