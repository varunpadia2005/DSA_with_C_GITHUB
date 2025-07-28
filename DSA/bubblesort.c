/*Varun Padia 241003003101
bubble and selection sort*/
#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
int* creatmatrix(int l);
void scanmatrix(int *arr,int l);
void bubbleSort(int *arr,int l,bool v_flag);
void selectionSort(int *arr,int l1,bool v_flag);
void printArray(int *arr,int l);
int main()
{
	int* arr,array;
	int l,l1;
    bool v_flag=true;
    /*bubble sort*/
	printf("Enter the size of the array for bubble sort : ");
	scanf("%d",&l);
	arr=creatmatrix(l);
    printf("Enter the elemnets of the array for bubble sort : ");
    scanmatrix(arr,l);
    printf("Array before bubble sort is : \n");
    printArray(arr,l);
    printf("\n STEPS of bubble sort : ");
    bubbleSort(arr,l,v_flag);
    printf("\nArray after bubble sorts is : ");
    printArray(arr,l);
    /*selection sort*/
    printf("\n Enter the size of the array for selection sort : ");
	scanf("%d",&l1);
	array=creatmatrix(l1);
    printf("Enter the elemnets of the array for selection sort : ");
    scanmatrix(array,l1);
    printf("Array before selection sort is :\n ");
    printArray(array,l1);
    printf("\n STEPS of bubble sort : ");
    selectionSort(array,l1,v_flag);
    printf("\nArray after selcetion sorts is : ");
    printArray(array,l1);
}
int* creatmatrix(int l) {
	int* arr;
	arr=(int*)calloc(l,sizeof(int));
    return arr;
}
void scanmatrix(int *arr,int l) {
	int i,j;
	for(i=0;i<l;i++)
		scanf("%d",&arr[i]);
}
void bubbleSort(int *arr, int l,bool v_flag) {
    int i,j,temp,swap,a=0;
    for (i=0; i<l-1;i++) {
        swap=0; 
        for (j=0;j<l-i-1;j++) {
            if (arr[j] > arr[j+1]) {
                temp=arr[j];
                arr[j]=arr[j+1];
                arr[j+1]=temp;
                swap=1;
            }
        }
        a++;
        if(v_flag==true) {
            printf("\n");
            printArray(arr,l);
        }
        if(swap==0)
            break;
    }
    if(v_flag==true)
        printf("\nNo of times no. swapped %d \n",a);
}
void selectionSort(int *arr, int l1,bool v_flag) {
    int i,j,temp,min,a=0;
    for(i=0; i<l1-1;i++) {
        min=i;
        for(j=i+1;j<l1;j++) {
            if (arr[min] > arr[j])
                min=j;
        }
        if(min!=i) {
            temp=arr[i];
            arr[i]=arr[min];
            arr[min]=temp;
        }
        a++;
        if(v_flag==true) {
            printArray(arr,l1);
            printf("\n");
        }

    }
    if(v_flag==true)
        printf("\nNo of times no. swapped %d \n",a);
}
void printArray(int* arr,int l) {
    int i;
	for(i=0;i<l;i++)
		printf("%d\t",arr[i]);
}