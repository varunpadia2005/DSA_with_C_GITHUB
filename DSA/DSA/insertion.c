/*Varun Padia 241003003101
insertion and count sort*/
#include<stdio.h>
#include<stdlib.h>
int* creatmatrix(int l);
void scanmatrix(int *arr,int l);
void insertionSort(int *arr, int l);
void countSort(int *arr, int l);
void printArray(int *arr,int l);
int main()
{
	int* arr;
    int* arr1;
	int l,l1;
	/*insertion  sort*/
    printf("Enter the size of the array for insertion sort : ");
	scanf("%d",&l);
	arr=creatmatrix(l);
    printf("Enter the elemnets of the array for insertion sort : ");
    scanmatrix(arr,l);
    printf("Array before insertion sort is : ");
    printArray(arr,l);
    insertionSort(arr,l);
    printf("\nArray after insertion sort is : ");
    printArray(arr,l);
    /*count sort*/
    printf("Enter the size of the array for count sort : ");
	scanf("%d",&l1);
	arr1=creatmatrix(l1);
    printf("Enter the elemnets of the array for count sort : ");
    scanmatrix(arr1,l1);
    printf("Array before count sort is : ");
    printArray(arr1,l1);
    countSort(arr1,l1);
    printf("\nArray after count sort is : ");
    printArray(arr1,l1);
}
int* creatmatrix(int l)
{
	int* arr;
	arr=(int*)calloc(l,sizeof(int));
    return arr;
}
void scanmatrix(int *arr,int l)
{
	int i,j;
	for(i=0;i<l;i++)
		scanf("%d",&arr[i]);
}
void insertionSort(int *arr, int l) 
{
    int i,j,temp=0;
    for(i=1;i<l;i++) 
    {
        temp=arr[i];
        j=i-1;
        while(j>=0 && arr[j]>temp) 
        {
            arr[j+1]=arr[j];
            j--;
        }
        arr[j+1]=temp;
    }
}
void countSort(int *arr, int l) 
{
    int i,j,k,max=0,index,val;
    int* b;
    max=arr[0];
    for(i=1;i<l;i++) 
    {
        if(max<arr[i])
            max=arr[i];
    }
    index=max+1;
    b=creatmatrix(index);
    for(i=0;i<index;i++)
        b[i]=0;
    for(i=0;i<l;i++)
        b[arr[i]]++;
    i=0;
    for(j=0;j<=max;j++) 
    {
        val=b[j];
        for(k=0;k<val;k++) 
        {
            arr[i]=j;
            i++;
        }
    }
}
void printArray(int* arr,int l) 
{
    int i;
	for(i=0;i<l;i++)
		printf("%d\t",arr[i]);
}