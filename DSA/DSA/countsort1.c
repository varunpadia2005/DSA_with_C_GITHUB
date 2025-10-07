/*Varun Padia 241003003101
count sort*/

#include<stdio.h>
#include<stdlib.h>
int* creatmatrix(int l);
void scanmatrix(int *arr,int l);
void countSort(int *arr, int l);
void printArray(int *arr,int l);
int main()
{
	int* arr;
	int l;
	/*count sort*/
    printf("Enter the size of the array for count sort : ");
	scanf("%d",&l);
	arr=creatmatrix(l);
    printf("Enter the elemnets of the array for count sort : ");
    scanmatrix(arr,l);
    printf("Array before count sort is : ");
    printArray(arr,l);
    countSort(arr,l);
    printf("\nArray after count sort is : ");
    printArray(arr,l);
}
int* creatmatrix(int l)
{
	int* array;
	array=(int*)calloc(l,sizeof(int));
    return array;
}
void scanmatrix(int *arr,int l)
{
	int i,j;
	for(i=0;i<l;i++)
		scanf("%d",&arr[i]);
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
	for(i=0;i<l;i++) {
		printf("%d\t",arr[i]);
	}
}