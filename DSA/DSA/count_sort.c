#include<stdio.h>
#include<stdlib.h>
int* init(int n);
void scanArray(int* arr, int n);
void printArray(int* arr, int n);
void countsort(int* arr, int n);
int main()
{
    int n;
    int* arr;
    printf("Enter the size of the array: ");
    scanf("%d",&n);
    arr=init(n);
    printf("Enter the elements of the array: ");
    scanArray(arr,n);
    printf("Original Array: ");
    printArray(arr,n);
    printf("Array after sorting: ");
    countsort(arr,n);
    printArray(arr,n);
    return 0;
}
int* init(int n)
{
    int* arr;
    arr=(int*)calloc(sizeof(int),n);
    return arr;
}
void scanArray(int* arr, int n)
{
    for(int i=0;i<n;i++)
        scanf("%d",&arr[i]);
}
void printArray(int* arr, int n)
{
    for(int i=0;i<n;i++)
        printf("%d ",arr[i]);
    printf("\n");
}
void countsort(int* arr, int n)
{
    int i,j,k,max,index,val;
    max=arr[0];
    for(i=1;i<n;i++)
    {
        if(arr[i]>max)
            max=arr[i];
    }
    index=max+1;
    int* freqarr=init(index);
    for(i=0;i<index;i++)
        freqarr[i]=0;
    for(i=0;i<n;i++)
        freqarr[arr[i]]++;
    i=0;
    for(j=0;j<=max;j++)
    {
        val=freqarr[j];
        for(k=0;k<val;k++)
        {
            arr[i]=j;
            i++;
        }
    }
    free(freqarr);
}