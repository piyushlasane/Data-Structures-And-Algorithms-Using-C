#include <stdio.h>
void display(int *arr, int n)
{
    printf("\nNew array: ");
    for (int i = 0; i < n; i++)
    {
        printf("%d ", arr[i]);
    }
}
int deletion(int *arr, int size, int index)
{
    for (int i = index; i < size - 1; i++)
    {
        arr[i] = arr[i + 1];
    }
    return 1;
}
int main()
{
    int arr[100] = {12, 33, 65, 87, 45, 23, 67, 54};
    int size = 8, index = 3;
    // printf("%d", size);
    printf("Old array: ");
    for (int i = 0; i < size; i++)
    {
        printf("%d ", arr[i]);
    }
    deletion(arr, size, index);
    size -= 1;
    display(arr, size);
    return 0;
}