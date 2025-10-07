#include<stdio.h>
#include<stdlib.h>
int* init(int n);
void scanarr(int* arr, int n);
void merge(int* arr, int start, int end, int mid);
void mergesort(int*arr , int start, int end);
void print(int* arr, int n);
int* init(int n)
{
    int*arr;
    arr=(int*)calloc(sizeof(arr),1);
    return arr;
}
void scanarr(int*arr, int n)
{
    for(int i = 0; i < n ; i++)
        scanf("%d", &arr[i]);
}
void print(int*arr, int n)
{
    for(int i = 0; i < n ; i++)
        printf("%d ", arr[i]);
}
void merge(int* arr, int start, int mid, int end)
{
    int i = start, j = mid + 1, k = start;
    int temp[end - start + 1];
    while (i <= mid && j <= end)
    {
        if (arr[i] < arr[j])
            temp[k++] = arr[i++];
        else
            temp[k++] = arr[j++];
    }
    while (i <= mid)
        temp[k++] = arr[i++];
    while (j <= end)
        temp[k++] = arr[j++];
    for (i = start, k = 0; i <= end; i++, k++)
        arr[i] = temp[k];
}
void mergesort(int* arr, int start, int end)
{
    if (start < end)
    {
        int mid = (start + end) / 2;
        mergesort(arr, start, mid - 1);
        mergesort(arr, mid + 1, end);
        merge(arr, start, mid, end);
    }
}
int main()
{
    int n;
    printf("Enter number of elements: ");
    scanf("%d", &n);
    int* arr = init(n);
    printf("Enter the elemnents of the array: ");
    scanarr(arr, n);
    printf("Original array:\n");
    print(arr, n);
    mergesort(arr, 0, n - 1);
    printf("\nSorted array:\n");
    print(arr, n);
    free(arr);
    return 0;
}