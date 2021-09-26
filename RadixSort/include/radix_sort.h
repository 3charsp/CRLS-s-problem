#ifndef RADIX_SORT_H
#define RADIX_SORT_H
#define MaxLenth 10
union key
{
    int number;
    char string[MaxLenth + 1];
};
typedef struct
{
    union key keys;
    int value;
} item;
typedef int (*dimension_f)(item);
typedef int (*key_f)(item, int);

void digit_sort(item *, int size, int max_digits, dimension_f dimension, key_f key);
void string_sort(item *, int size, int max_lenth, dimension_f dimension, key_f key);

void partition(item *, int max_lenth, int size, int *group, dimension_f dimension);
void radix_sort(item *, int begin, int end, int maxlenth, key_f key);
void count_sort(item *, int max_lenth, int left, int right, key_f key, int key_index);

int item_nth_digit(item i, int d);
int item_digit(item i);

int item_string_lenth(item i);
int item_nth_char(item i, int n);

#endif
