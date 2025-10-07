/*Varun Padia   241003003101
*/
#include<stdio.h>
#include<stdlib.h>
int linearSearch(int arr[], int st, int e, int ele);
int binarySearch(int arr[], int st, int e, int ele);
int main()
{
    int size,ele,ch,check=-1,i;
    printf("Enter the size of the array: ");
    scanf("%d",&size);
    int *arr=(int*)calloc(sizeof(int),size);
    printf("Enter the elements of the array: ");
    for(i=0;i<size;i++)
        scanf("%d",&arr[i]);
    printf("Enter the element to search in the array: ");
    scanf("%d",&ele);
    printf("1. Linear Search \n2. Binary Search\n");
    printf("Enter the choice: ");
    scanf("%d",&ch);
    switch(ch)
    {
        case 1: check=linearSearch(arr, 0, size-1, ele);
                if (check != -1)
                    printf("Element found at index: %d\n", check);
                else
                    printf("Element not found in the array.\n");
                break;
        case 2: check=binarySearch(arr, 0, size-1, ele);
                if (check != -1)
                    printf("Element found at index: %d\n", check);
                else
                    printf("Element not found in the array.\n");
                break;
        default:printf("Invalid! Choice");
    }
    free(arr);
}
int linearSearch(int arr[], int st, int e, int ele)
{
    if(st>e)
        return -1;
    if(arr[st]==ele)
        return st;
    return linearSearch(arr, st+1, e, ele);
}
int binarySearch(int arr[], int st, int e, int ele)
{
    if(st>e)
        return -1;
    int mid=st+(e-st)/2;
    if(arr[mid]==ele)
        return st;
    else if (arr[mid] > ele) 
        return binarySearch(arr, st, mid-1, ele);
    else 
        return binarySearch(arr, mid + 1, e, ele);
}