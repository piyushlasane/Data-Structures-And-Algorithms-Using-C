#include <stdio.h>

void traverse(int *arr, int n)
{
    for (int i = 0; i < n; i++)
    {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

void selection_sort(int *arr, int n)
{
    int i, j;
    for (i = 0; i < n - 1; i++)
    {
        int indexOfMin = i;
        for (j = i + 1; j < n; j++)
        {
            if (arr[j] < arr[indexOfMin])
            {
                indexOfMin = j;
            }
        }
        int temp = arr[i];
        arr[i] = arr[indexOfMin];
        arr[indexOfMin] = temp;
    }
}

int main()
{
    int arr[] = {15, 84, 54, 51, 65, 74, 62};
    int n = sizeof(arr) / sizeof(arr[0]);
    printf("Before Sorting: ");
    traverse(arr, n);
    selection_sort(arr, n);
    printf("After Sorting:  ");
    traverse(arr, n);
    return 0;
}