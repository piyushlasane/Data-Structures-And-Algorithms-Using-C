#include <stdio.h>

void traverse(int *arr, int n)
{
    for (int i = 0; i < n; i++)
    {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

void bubble_sort(int *arr, int n)
{
    for (int i = 0; i < n-1; i++)
    {
        int flag = 1;
        printf("Performing Pass number %d\n", i+1);
        for (int j = 0; j < n-i-1; j++)
        {
            if (arr[j]>arr[j+1])
            {
                int temp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = temp;
                flag=0;
            }
        }
        if (flag)
        {
            return;
        }
    }
}

int main()
{
    int arr[] = {1, 9, 10, 13, 14, 24, 7, 38};
    int n = sizeof(arr)/sizeof(arr[0]);
    printf("Before Sorting: ");
    traverse(arr, n);
    bubble_sort(arr, n);
    printf("After Sorting:  ");
    traverse(arr, n);
    return 0;
}