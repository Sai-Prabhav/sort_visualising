#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <unistd.h>
#include "array.h"
#include "sketch.h"

#define n 10
int arr[n];
int size = 1260;
int number_steps = 0;

void print_int(int x, char label[])
{
    printf("%s %d\n", label, x);
}
void draw(int j)
{
    // clear_sketch();
    // draw_chart(arr, n, j + 1);
    number_steps += 1;
    // print_array(arr, n);
    // save_sketch("sketch.svg");
    // usleep(100000);
    // save_frame();
}

int is_sorted(int arr[n])
{

    for (int i = 0; i < n - 1; i++)
    {
        if (arr[i] > arr[i + 1])
        {
            return 0;
        }
    }
    return 1;
}

void bubble_sort(int arr[n])
{
    int temp;
    printf("%d\n", is_sorted(arr));
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

void random_sort(int arr[n])
{

    int index;
    int temp;
    while (!is_sorted(arr))
    {
        index = rand() % (n - 1);
        temp = arr[index];
        arr[index] = arr[index + 1];
        arr[index + 1] = temp;
        draw(index);
    }
}

int main(int argc, char const *argv[])
{
    double min_seed=0, min_steps=100000000000000;
    for (int s = 0; s < 10; s++)
    {   
        number_steps=0;
        int seed = s*s+234%s;
        print_int(seed, "seed: ");
        srand(seed);
        rand_array(arr, n);
        random_sort(arr);
        print_int(number_steps, "number of steps:");
        if (number_steps<min_steps)
        {
            min_seed=seed;
            min_steps=number_steps;
        }
        
        print_int(min_steps,"the lowest steps is");
        print_int(min_seed,"The seed of the fastest");
    
    }

    return 0;
}
