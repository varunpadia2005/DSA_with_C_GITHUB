#include<stdio.h>
#include<stdlib.h>

int* init(int s);
void scanarray(int* arr, int s);
void merge(int* arr,int st,int en, int mid);
void mergesort(int* arr,int st,int en);
void print(int* arr,int s);
int main()
{
    int s,st,en;
    int* arr;
    printf("Enter the size of the array: ");
    scanf("%d",&s);
    arr=init(s);
    printf("Enter the values of the array: ");
    scanarray(arr,s);
    st=0;
    en=s;
    mergesort(arr,st,en-1);
    printf("Array after sorting");
    print(arr,en);
}
int* init(int s)
{
    int* arr;
    arr=(int*)calloc(sizeof(int),s);
    return arr;
}
void scanarray(int* arr, int s)
{
    for(int i=0;i<s;i++)
        scanf("%d",&arr[i]);
}
void merge(int* arr,int st,int en, int mid)
{
    int i,j,k;
    int n1=mid-st+1;
    int n2=en-mid;
    int leftarr[n1],rightarr[n2];
    for(i=0;i<n1;i++)
        leftarr[n1]=arr[st+i];
    for(i=0;i<n2;i++)
        rightarr[i]=arr[mid+1+i];
    i=0;
    j=0;
    k=st;
    while(i<n1 && j<n2)
    {
        if(leftarr[i]>rightarr[j])
        {
            arr[k]=rightarr[j];
            j++;
        }
        else 
        {
            arr[k]=leftarr[i];
            i++;
        }
        k++;
    }
    while(i<n1)
    {
        arr[k]=leftarr[i];
        i++;
        k++;
    }
    while(j<n2)
    {
        arr[k]=rightarr[j];
        j++;
        k++;
    }
}
void mergesort(int* arr,int st,int en)
{
    int mid=st+en-st/2;
    mergesort(arr,st,mid);
    mergesort(arr,mid+1,en);
    merge(arr,st,en,mid);
}
void print(int* arr, int s)
{
    for(int i=0;i<s;i++)
        printf(" %d \n",arr[i]);
}