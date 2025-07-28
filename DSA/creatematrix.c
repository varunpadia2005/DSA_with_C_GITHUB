#include<stdio.h>
#include<stdlib.h>
int** creatmatrix(int row, int col);
void scanmatrix(int **mat,int row,int col);
void printmatrix(int **mat,int row,int col);

int main()
{
	int** mat;
	int row,col;
	printf("Enter the size of the row: ");
	scanf("%d",&row);
	printf("Enter the size of the coloum: ");
	scanf("%d",&col);
	mat=creatmatrix(row,col);
	scanmatrix(mat,row,col);
	printmatrix(mat,row,col);
}
int** creatmatrix(int row, int col)
{
	int** mat;
	mat=(int**)calloc(row,sizeof(int));
	for(int i=0;i<row;i++)
	{
		mat[i]=(int*)calloc(col,sizeof(int));
	}
	return mat;
}
void scanmatrix(int **mat,int row,int col)
{
	int i,j;
	for(i=0;i<row;i++)
	{
		printf("Enter the elemnet of the %d row",i);
		for(j=0;j<col;j++)
		{
			scanf("%d",&mat[i][j]);
		}
	}
}
void printmatrix(int **mat,int row,int col)
{
	int i,j;
	for(i=0;i<row;i++)
	{
		for(j=0;j<col;j++)
		{
			printf("%d\t",mat[i][j]);
		}
		printf("\n");
	}
}