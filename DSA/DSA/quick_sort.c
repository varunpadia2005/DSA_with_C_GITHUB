#include <stdio.h>
#include<stdlib.h>
int* init(int n);
void scanarr(int *Arr, int n);
int partition(int *Arr, int start, int end);
void quickSort(int *Arr, int start, int end);
void printArray(int *Arr, int n);
int main()
{
    int n,start,end;
    printf("Enter number of elements: ");
    scanf("%d", &n);
    int* Arr = init(n);
    start=0;
    end=n-1;
    printf("Enter the elemnents of the array: ");
    scanarr(Arr, n);
    printf("Original array:\n");
    printArray(Arr, n);
    quickSort(Arr,start,end);
    printf("\nSorted array:\n");
    printArray(Arr, n);
    return 0;
}
int* init(int n)
{
    int*arr;
    arr=(int*)calloc(sizeof(arr),1);
    return arr;
}
void scanarr(int*Arr, int n)
{
    for(int i=0;i<n;i++)
        scanf("%d", &Arr[i]);
}
void printArray(int *Arr, int n)
{
    for (int i = 0; i < n; i++)
        printf("%d ", Arr[i]);
    printf("\n");
}
int partition(int *Arr, int start, int end)
{
    int pivot = Arr[end];
    int i = start-1;
    int temp;
    for(int j=start;j<end;j++)
    {
        if(Arr[j]<=pivot)
        {
            i++;
            temp = Arr[i];
            Arr[i] = Arr[j]; 
            Arr[j] = temp;
        }
    }
    i++;
    temp = Arr[i];
    Arr[i] = Arr[end];
    Arr[end] = temp;
    return i;
}
void quickSort(int *Arr, int start, int end)
{
    int pvitIdx; // Index of pivot after partition
    if (start < end)
    {
        pvitIdx = partition(Arr, start, end); 
        quickSort(Arr, start, pvitIdx - 1);  // sort left subarray 
        quickSort(Arr, pvitIdx + 1, end); // sort right subarray
    }
}