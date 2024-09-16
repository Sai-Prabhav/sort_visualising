#include <stdio.h>
#include <time.h>
#include <stdlib.h>

void print_array(int arr[], int len)
{

    for (int i = 0; i < len; i++)
    {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

void arr_remove(int *arr, int len, int pos)
{
    for (int i = pos; i < len; i++)
    {
        arr[i] = arr[i + 1];
    }
}

void range(int *range, int len)
{
    for (int j = 0; j < len; j++)
    {
        range[j] = j + 1;
    }
}

void rand_array(int *arr, int len)
{
    int ran[len];
    range(ran, len);
    int left = len;
    int num;
    for (int i = 0; i < len; i++)
    {

        num = rand() % left;
        arr[i] = ran[num];
        arr_remove(ran, left, num);

        left -= 1;
    }
}
