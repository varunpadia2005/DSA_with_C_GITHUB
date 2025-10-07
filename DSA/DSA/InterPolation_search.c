#include<stdio.h>
#include<stdlib.h> 
int* init(int n);
void scanArray(int *arr,int n);
void printArray(int *arr,int n);
int Inter_polation_search(int *arr, int low, int high, int key);
int main()
{
    int n,low,high,key,ans;
    int* arr;
    printf("Enter the size of the array: ");
    scanf("%d",&n); 
    arr=init(n);
    printf("Enter the sorted array: ");
    scanArray(arr,n);
    printf("Enter the key to be searched: ");
    scanf("%d",&key);
    printf("Original Array: ");
    printArray(arr,n);
    low=0;
    high=n-1;
    ans=Inter_polation_search(arr, low, high, key);
    if(ans>=0)
        printf("%d found at the index: %d",key,ans);
    else
        printf("Key not found.");
}
int* init(int n)
{
    int* arr;
    arr=(int*)calloc(sizeof(int),n);
    return arr;   
}
void scanArray(int *arr,int n)
{
    for(int i=0;i<n;i++)
        scanf("%d",&arr[i]);
}
void printArray(int *arr,int n)
{
    for(int i=0;i<n;i++)
        printf(" %d",arr[i]);
    printf("\n");
}
int Inter_polation_search(int *arr, int low, int high, int key)
{
    int pos;
    pos = low + ((( high - low ) * ( key - arr[low] )) / ( arr[high] - arr[low] ));
    if(low > high)
        return -1;
    if(arr[pos] == key) {
        return pos;
    } else if(arr[pos] > key) {
        return Inter_polation_search(arr, low, pos-1, key);
    } else if(arr[pos] < key) {
        return Inter_polation_search(arr, pos+1, high, key);
    }
}