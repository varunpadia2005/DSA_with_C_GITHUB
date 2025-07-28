/*Varun Padia 241003003101
Matrix calculator.*/
#include<stdio.h>
#include<stdlib.h>
int** creatmatrix1(int row, int col);
void scanmatrix(int **mat1,int row,int col);
void add(int **mat1,int **mat2,int **mat3,int row1,int col1);
void multiply(int **mat1,int **mat2,int **mat4,int row1,int col2,int col1);
void transpose(int **mat1,int **mat5,int row1,int col1);
void printmatrix(int **mat3,int row1,int col1);
int main()
{
	int** mat1;
	int** mat2;
	int** mat3;
	int** mat4,**mat5;
	int row1,col1,row2,col2,c;
	printf("Enter '1' for addition, '2' for multiplication and '3' for transpose. \n");
	scanf("%d",&c);
	if(c==1) 
	{
		printf("Enter the size of the row of 1st matrix : ");
		scanf("%d",&row1);
		printf("Enter the size of the coloum of 1st matrix : ");
		scanf("%d",&col1); 
    	printf("Enter the size of the row of 2nd matrix : ");
		scanf("%d",&row2);
		printf("Enter the size of the coloum of 2nd matrix : ");
		scanf("%d",&col2);
		if(row1==row2 && col1==col2) 
		{
			mat1=creatmatrix1(row1,col1);
			mat2=creatmatrix1(row2,col2);
			mat3=creatmatrix1(row1,col1);
			scanmatrix(mat1,row1,col1);
			scanmatrix(mat2,row2,col2);
			printf("The two matrix are :\n");
			printmatrix(mat1,row1,col1);
			printf("\n");
			printmatrix(mat2,row2,col2);
			add(mat1,mat2,mat3,row1,col1);
			printf("Matrix addition :\n");
			printmatrix(mat3,row1,col1);
		}
		else 
			printf("Addition is not possible.");
	}
	else if(c==2) 
	{
		printf("Enter the size of the row of 1st matrix : ");
		scanf("%d",&row1);
		printf("Enter the size of the coloum of 1st matrix : ");
		scanf("%d",&col1);
    	printf("Enter the size of the row of 2nd matrix : ");
		scanf("%d",&row2);
		printf("Enter the size of the coloum of 2nd matrix : ");
		scanf("%d",&col2);
		if(col1==row2) 
		{
			mat1=creatmatrix1(row1,col1);
			mat2=creatmatrix1(row2,col2);
			mat4=creatmatrix1(row1,col2);
			scanmatrix(mat1,row1,col1);
			scanmatrix(mat2,row2,col2);
			printf("The two matrix are :\n");
			printmatrix(mat1,row1,col1);
			printf("\n");
			printmatrix(mat2,row2,col2);
			printf("\n");
			multiply(mat1,mat2,mat4,row1,col2,col1);
			printf("Matrix multiplication : \n");
			printmatrix(mat4,row1,col2);
		}
		else 
			printf("Multiplication is not possible.");
	}
	else if(c==3)
	{
		printf("Enter the size of the row of 1st matrix : ");
		scanf("%d",&row1);
		printf("Enter the size of the coloum of 1st matrix : ");
		scanf("%d",&col1);
		mat1=creatmatrix1(row1,col1);
		mat5=creatmatrix1(row1,col1);
		scanmatrix(mat1,row1,col1);
		printf("Matrix before transpose is : \n");
		printmatrix(mat1,row1,col1);
		transpose(mat1,mat5,row1,col1);
		printf("Matrix after transpose is : \n");
		printmatrix(mat5,row1,col1);
	}
	else
		printf("Invalid Input");
}
int** creatmatrix1(int row, int col) {
	int** mat;
	mat=(int**)calloc(row,sizeof(int));
	for(int i=0;i<row;i++)
		mat[i]=(int*)calloc(col,sizeof(int));
	return mat;
}
void scanmatrix(int **mat,int row,int col) {
	int i,j;
	for(i=0;i<row;i++) {
		printf("Enter the elemnet of the %d row : \n",i+1);
		for(j=0;j<col;j++)
			scanf("%d",&mat[i][j]);
	}
}
void add(int **mat1,int **mat2,int **mat3,int row1,int col1) {
	int i,j;
	for(i=0;i<row1;i++) {
		for(j=0;j<col1;j++)
			mat3[i][j]=mat1[i][j]+mat2[i][j];
	}
}
void multiply(int **mat1,int **mat2,int **mat4,int row1,int col2,int col1) {
	int i,j,k;
	for(i=0;i<row1;i++){
		for(j=0;j<col2;j++) {
			for(k=0;k<col1;k++)
				mat4[i][j]+=mat1[i][k]*mat2[k][j];
		}
	}
}
void transpose(int **mat1,int **mat5,int row1,int col1) {
	int i,j;
	for(i=0;i<row1;i++) {
		for(j=0;j<col1;j++)
			mat5[i][j]=mat1[j][i];
	}
}
void printmatrix(int **mat3,int row1,int col1) {
	int i,j;
	for(i=0;i<row1;i++) {
		printf("\t");
		for(j=0;j<col1;j++)
			printf("%d\t",mat3[i][j]);
		printf("\n");
	}
}