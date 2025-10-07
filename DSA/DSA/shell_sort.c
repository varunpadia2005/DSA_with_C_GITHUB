#include<stdio.h>
#include<stdlib.h>
int* init(int n);
void scanArray(int* arr,int n);
void printArray(int* arr,int n);
void shell_sort(int* arr,int n);
int main()
{
    int n;
    int* arr;
    printf("Enter the size of the array: ");
    scanf("%d",&n);
    arr=init(n);
    printf("Enter the elemnet of the array: ");
    scanArray(arr,n);
    printf("Original Array: ");
    printArray(arr,n);
    shell_sort(arr,n);
    printf("Array after Shell sorting: ");
    printArray(arr,n);
    return 0;
}
int* init(int n)
{
    int* temp;
    temp=(int*)calloc(sizeof(int),n);
    return temp;
}
void scanArray(int* arr,int n)
{
    for(int i=0;i<n;i++)
        scanf("%d",&arr[i]);
}
void printArray(int* arr,int n)
{
    for(int i=0;i<n;i++)
        printf("%d ",arr[i]);
    printf("\n");
}
void shell_sort(int* arr,int n)   //its an in-place compairision based sorting algorithm with time complexcity of O(nlogn).It is also an advance version of insertion sort where we basically do the the comparision not on the adjacent element but with the farther elments.But in the last iterration we do insertion sort only.
{
    int gap,i,j,temp;
    for(gap=n/2;gap>0;gap/=2)
    {
        for(j=gap;j<n;j++)
        {
            for(i=j-gap;i>=0;i-=gap)
            {
                if(arr[i]>arr[i+gap])
                {
                    temp=arr[i];
                    arr[i]=arr[i+gap];
                    arr[i+gap]=temp;
                }
                else 
                    break;
            }
        }
    }
}