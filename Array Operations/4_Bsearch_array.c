#include <stdio.h>
int BSearch(int *a, int size, int element)
{
    int High = size - 1, Low = 0;
    while (Low <= High)
    {
        int mid = (Low + High) / 2;
        if (a[mid] == element)
        {
            return mid;
        }
        if (a[mid] < element)
        {
            Low = mid + 1;
        }
        else if (a[mid] > element)
        {
            High = mid - 1;
        }
    }
    return -1;
}

int main()
{
    int arr[100] = {
        2,
        12,
        19,
        23,
        34,
        45,
        64,
        76,
        99,
    };
    int size = 9, element = 34;
    int i = BSearch(arr, size, element);
    if (i == -1)
        printf("The element is not present in array.");
    else
        printf("The element %d is at %d index.", element, i);
    return 0;
}