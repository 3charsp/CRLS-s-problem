#include "k_sort.h"
#include <stdlib.h>
#include <stdio.h>
void k_sort(item *item, int k, int size, int *record)
{
    k_sort_state s;
    int lenth = size / k + 1;
    int *indices;
    indices = (int *)malloc(sizeof(int) * lenth);
    for (int j = 0; j < lenth; j++)
        indices[j] = j * k;
    s.indices = indices;
    s.lenth = lenth;
    s.item = item;
    s.k = k;
    s.size = size;
    int end;
    int i;
    for (i = 0; i < k; i++)
    {
        end = ((i + k * (lenth - 1)) >= size) ? lenth - 2 : lenth - 1;
        record[i] = end + 1;
        merge_k_sort(&s, 0, end, i);
    }
}
void merge_k_sort(k_sort_state *kss, int begin, int end, int i)
{
    if (begin < end)
    {
        int mid = (end + begin) / 2;
        merge_k_sort(kss, begin, mid, i);
        merge_k_sort(kss, mid + 1, end, i);
        merge(kss, begin, end, mid, i);
    }
}
void merge(k_sort_state *kss, int begin, int end, int mid, int b)
{
    int n1 = mid - begin + 1;
    int n2 = end - mid;
    item L[n1], R[n2];
    int i, j, k;
    for (i = 0; i < n1; i++)
        L[i] = kss->item[kss->indices[i + begin] + b];
    for (j = 0; j < n2; j++)
        R[j] = kss->item[kss->indices[j + mid + 1] + b];
    i = j = 0;
    int a;
    int l, r;
    for (k = begin; k <= end; k++)
    {
        l = L[i].value;
        r = R[j].value;
        if (l <= r)
        {
            kss->item[kss->indices[k] + b] = L[i];
            i++;
        }
        else
        {
            kss->item[kss->indices[k] + b] = R[j];
            j++;
        }
        if (i == n1)
        {
            for (a = k + 1; a <= end; a++)
            {
                kss->item[kss->indices[a] + b] = R[j];
                j++;
            }
            break;
        }
        if (j == n2)
        {
            for (a = k + 1; a <= end; a++)
            {
                kss->item[kss->indices[a] + b] = L[i];
                i++;
            }
            break;
        }
    }
}
void k_to1sort(k_heap *h, int *local)
{
    int *ano_count;
    ano_count = (int *)malloc(sizeof(int) * h->lenth);
    for (int p = 0; p < h->lenth; p++)
        ano_count[p] = 0;
    int i;
    item q;
    int t;
    for (i = 0; i < h->size; i++)
    {
        q = extract_min(h);
        t = q.key;
        ano_count[t]++;        //列对应层数加一
        if (h->record[t] == 0) //t列已经被排完
            ;
        else
            heap_add(h, ano_count[t] * h->k + t); //层数*宽度+列数
        local[i] = q.value;
    }
}
item extract_min(k_heap *h)
{
    item min = h->heap[0];
    h->heap[0] = h->heap[h->lenth - 1];
    h->lenth--;
    min_heapify(h, 0);
    h->record[min.key]--; //此列未排元素减一
    return min;
}
void heap_add(k_heap *h, int K)
{
    h->lenth++;
    h->heap[h->lenth - 1] = h->i[K];
    int i = h->lenth - 1;
    item temp;
    while (i > 0 && h->heap[PARENT(i)].value > h->heap[i].value)
    {
        temp = h->heap[PARENT(i)];
        h->heap[PARENT(i)] = h->heap[i];
        h->heap[i] = temp;
        i = PARENT(i);
    }
}
void build_heap_min(k_heap *h, item *t, int size)
{
    int j;
    h->i = t;
    h->size = size;
    for (j = 0; j < h->lenth; j++)
        h->heap[j] = h->i[j];
    for (j = h->lenth / 2 - 1; j >= 0; j--)
        min_heapify(h, j);
}
void min_heapify(k_heap *h, int j)
{
    int l = LEFT(j);
    int r = RIGHT(j);
    int min;
    if (l < h->lenth && h->heap[l].value < h->heap[j].value)
        min = l;
    else
        min = j;
    if (r < h->lenth && h->heap[r].value < h->heap[min].value)
        min = r;
    item temp;
    if (min != j)
    {
        temp = h->heap[min];
        h->heap[min] = h->heap[j];
        h->heap[j] = temp;
        min_heapify(h, min);
    }
}
