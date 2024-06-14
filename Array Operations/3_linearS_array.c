#include <stdio.h>
int linearSearch(int *a, int size, int element)
{
    for (int i = 0; i < size - 1; i++)
    {
        if (a[i] == element)
        {
            return i;
        }
    }
    return -1;
}

int main()
{
    int arr[100] = {23, 64, 12, 45, 76, 34, 99, 2, 19};
    int size = 9, element = 45;
    int i = linearSearch(arr, size, element);
    if (i == -1)
        printf("The element is not present in array.");
    else
        printf("The element %d is at %d index.", element, i);
    return 0;
}