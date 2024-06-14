#include <stdio.h>

void traverse(int *arr, int n)
{
    for (int i = 0; i < n; i++)
    {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

void insertion_sort(int *arr, int n)
{
    for (int i = 1; i < n-1; i++)
    {
        int j = i - 1, key = arr[i];
        while (key < arr[j] && j >= 0)
        {
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j+1]=key;
    }
}

int main()
{
    int arr[] = {15, 84, 54, 51, 65, 74, 62};
    int n = sizeof(arr) / sizeof(arr[0]);
    printf("Before Sorting: ");
    traverse(arr, n);
    insertion_sort(arr, n);
    printf("After Sorting:  ");
    traverse(arr, n);
    return 0;
}