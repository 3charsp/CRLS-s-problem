#include "radix_sort.h"
#include <math.h>
#include <stdio.h>
#include <string.h>
void digit_sort(item *i, int size, int max_digits, dimension_f dimension, key_f key)
{
    int groups[max_digits + 1];
    partition(i, max_digits, size, groups, dimension);
    int d;
    for (d = 1; d <= max_digits; d++)
    {
        radix_sort(i, groups[d - 1], groups[d] - 1, d, key);
    }
}
void string_sort(item *i, int size, int max_lenth, dimension_f dimension, key_f key)
{
    int groups[max_lenth + 1];
    partition(i, max_lenth, size, groups, dimension);
    int d;
    for (d = max_lenth; d >= 1; d--)
    {
        count_sort(i, 26, groups[d - 1], size - 1, key, d - 1);
    }
}
void partition(item *i, int max_lenth, int size, int *group, dimension_f f)
{
    int count[max_lenth + 1];
    item temp[size];
    int j;
    for (j = 0; j < max_lenth + 1; j++)
        count[j] = 0;
    for (j = 0; j < size; j++)
        count[f(i[j])]++;
    for (j = 1; j <= max_lenth; j++)
        count[j] += count[j - 1];
    for (j = 0; j <= max_lenth; j++)
        group[j] = count[j];
    for (j = 0; j < size; j++)
        temp[j] = i[j];
    for (j = size - 1; j >= 0; j--)
    {
        i[count[f(temp[j])] - 1] = temp[j];
        count[f(temp[j])]--;
    }
}
void count_sort(item *i, int max_lenth, int left, int right, key_f key, int key_i)
{
    int count[max_lenth + 1];
    int j;
    item temp[right - left + 1];
    for (j = 0; j < max_lenth + 1; j++)
        count[j] = 0;
    for (j = left; j <= right; j++)
        count[key(i[j], key_i)]++;
    for (j = left; j <= right; j++)
        temp[j - left] = i[j];
    for (j = 1; j < max_lenth + 1; j++)
        count[j] += count[j - 1];
    int n;
    for (j = right; j >= left; j--)
    {
        n = count[key(temp[j - left], key_i)];
        i[n - 1 + left] = temp[j - left];

        count[key(temp[j - left], key_i)]--;
    }
}
void radix_sort(item *i, int begin, int end, int maxlenth, key_f key)
{
    int j;
    for (j = 0; j < maxlenth; j++)
        count_sort(i, 10, begin, end, key, j);
}
int item_nth_digit(item i, int d)
{
    int n = pow(10, d);

    return (i.keys.number / n) % 10;
}
int item_nth_char(item i, int n)
{
    return i.keys.string[n] - 'a';
}
int item_digit(item i)
{
    int j = 0;
    int t = i.keys.number;
    if (t == 0)
        return 1;
    while (t > 0)
    {
        t = t / 10;
        j++;
    }
    return j;
}
int item_string_lenth(item i)
{
    return strlen(i.keys.string);
}
