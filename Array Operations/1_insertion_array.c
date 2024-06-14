#include <stdio.h>
void display(int *arr, int n)
{
    for (int i = 0; i < n; i++)
    {
        printf("%d ", arr[i]);
    }
}
int insertion(int *arr, int size, int index, int element, int capacity)
{
    if (size >= capacity)
    {
        return -1;
    }
    for (int i = size - 1; i >= index; i--)
    {
        arr[i + 1] = arr[i];
    }
    arr[index] = element;
    return 1;
}
int main()
{
    int arr[100] = {12, 33, 65, 87, 45, 23, 67, 54};
    int size = 6, index = 2, capacity = sizeof(arr) / sizeof(int), element = 15;
    // printf("%d", size);
    printf("Old array: ");
    display(arr, size);
    insertion(arr, size, index, element, capacity);
    size += 1;
    printf("\nNew array: ");
    display(arr, size);
    return 0;
}