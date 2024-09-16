#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <unistd.h>
#include "array.h"
#include "sketch.h"

#define n 150
int arr[n ];
int size = 1260;

void draw(int j)
{
    clear_sketch();
    draw_chart(arr, n, j + 1);
    // print_array(arr, n);
    // save_sketch("sketch.svg");
    // usleep(100090);
    save_frame();
}
void bubble_sort(int arr[n])
{
    int temp;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n - i - 1; j++)
        {
            if (arr[j] > arr[j + 1])
            {
                temp = arr[j + 1];
                arr[j + 1] = arr[j];
                arr[j] = temp;
                draw(j);
            }
        }
    }
}

int main(int argc, char const *argv[])
{
    set_sketch_size(size);
    set_fill("#000000");
    srand(time(0));

    rand_array(arr, n);
    bubble_sort(arr);
    return 0;
}
