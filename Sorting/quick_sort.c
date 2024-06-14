#include <stdio.h>

void traverse(int *arr, int n)
{
    for (int i = 0; i < n; i++)
    {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

int partition(int *arr, int low, int high)
{
    int i = low, j = high, temp;
    do{
        while (arr[i]<=arr[low])
        {
            i++;
        }

        while (arr[j]>arr[low])
        {
            j--;
        }
        
        if (i<j)
        {
            temp = arr[i];
            arr[i] = arr[j];
            arr[j] = temp;
        }
    }while(i<j);

    temp = arr[low];
    arr[low] = arr[j];
    arr[j] = temp;
    return j;
}

void Quick_sort(int *arr, int low, int high)
{
    traverse(arr, 7);
    int partitionIndex;
    if(low<high)
    {
        partitionIndex = partition(arr, low, high);
        Quick_sort(arr, low, partitionIndex-1);
        Quick_sort(arr, partitionIndex+1, high);
    }
}

int main()
{
    int arr[] = {5, 4, 3, 2, 1, 0, -1, -2};
    int n = sizeof(arr) / sizeof(arr[0]);
    printf("Before Sorting: ");
    traverse(arr, n);
    Quick_sort(arr, 0, n-1);
    printf("After Sorting:  ");
    traverse(arr, n);
    return 0;
}