#include "radix_sort.h"
#include <stdio.h>
#include <string.h>
int main(void)
{
    //item A[4] = {{13, 2}, {9, 2}, {12, 2}, {100, 2}};
    item B[4];
    int j;
    printf("Please enter 4 words,and then ");
    for (j = 0; j < 4; j++)
    {
        scanf("%s", &B[j].keys.string);
        B[j].value = strlen(B[j].keys.string);
    }
    //digit_sort(A, 4, 3, item_digit, item_nth_digit);
    string_sort(B, 4, MaxLenth, item_string_lenth, item_nth_char);
    int i;
    //for (i = 0; i < 4; i++)
    //   printf("%d ", A[i].keys.number);
    for (i = 0; i < 4; i++)
        printf("%s ", B[i].keys.string);
    return 0;
}