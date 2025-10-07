/*Varun Padia 241003003101
Program to add two polynomial and compute polynomial for a given value of X */

#include<stdio.h>
#include<stdlib.h>
#include<math.h>
typedef struct Polynomial{
  int** array;
  int terms;
}Polynomial;
int** create2DArray(int r, int c);
void scanPoly(Polynomial p);
void printPoly(Polynomial p);
int addPoly(Polynomial p1,Polynomial p2,Polynomial p3);
void finalpoly(Polynomial p1,Polynomial p2,int in);
int computePoly(Polynomial p3, int x);
int main()
{
    struct Polynomial poly1, poly2, poly3,temp;
    int c,x,result,in;
    printf("Enter the no. of terms of 1st polynomial : ");
    scanf("%d",&poly1.terms);
    printf("Enter the no. of terms of 2nd polynomial : ");
    scanf("%d",&poly2.terms);
    c=poly1.terms;
    poly1.array=create2DArray(2,c);
    c=poly2.terms;
    poly2.array=create2DArray(2,c);
    scanPoly(poly1);
    printf("Polynomial 1: ");
    printPoly(poly1);
    scanPoly(poly2);
    printf("Polynomial 2: ");
    printPoly(poly2);
    temp.array=create2DArray(2,poly1.terms+poly2.terms);
    in=addPoly(poly1,poly2,temp);
    poly3.array=create2DArray(2,in);
    poly3.terms=in;
    finalpoly(poly3,temp,in);
    printf("Sum of the polynomials: ");
    printPoly(poly3);
    printf("Enter the value of X : ");
    scanf("%d",&x);
    result=computePoly(poly3,x);
    printf("Result after putting the value of x : %d",result);
}
int** create2DArray(int r, int c) {
    int** arr;
	arr=(int**)calloc(r,sizeof(int));
	for(int i=0;i<r;i++)
		arr[i]=(int*)calloc(c,sizeof(int));
	return arr;
}
void scanPoly(Polynomial p) {
    printf("Enter the coefficients and exponents \n");
    for(int i=0;i<p.terms;i++) {
        printf("Term %d Coefficient : ",i+1);
        scanf("%d", &p.array[0][i]);
        printf("Term %d Exponent : ",i+1);
        scanf("%d",&p.array[1][i]);
    }
}
void printPoly(Polynomial p)  {
    int i;
    for (i=0; i < p.terms; i++) {
        printf("%dx^%d", p.array[0][i], p.array[1][i]);
        if(i!=(p.terms-1))
            printf(" + ");
    }
    printf("\n");
}
int addPoly(Polynomial p1,Polynomial p2,Polynomial temp) {
    int i=0,j=0,k=0;
    while (i<=p1.terms && j<=p2.terms) 
    {
        if (p1.array[1][i] == p2.array[1][j]) {
            int sum=p1.array[0][i] + p2.array[0][j];
            if (sum!=0) {
                temp.array[0][k] = sum;
                temp.array[1][k] = p1.array[1][i];
                k++;
            }
            i++; 
            j++;
        }
        else if(p1.array[1][i] > p2.array[1][j]) {
            temp.array[0][k] = p1.array[0][i];
            temp.array[1][k] = p1.array[1][i];
            i++; 
            k++;
        }
        else {
            temp.array[0][k] = p2.array[0][j];
            temp.array[1][k] = p2.array[1][j];
            j++;
            k++;
        }
    }
    int a=0;
    for(i=0;i<(p1.terms+p2.terms);i++) {
        if(temp.array[0][i]==0)
            break;
        a++;
    }
    return a;
}
void finalpoly(Polynomial p3,Polynomial temp,int in) {
    int i,j;
    for(i=0;i<2;i++) {
        for(j=0;j<in;j++)
            p3.array[i][j] = temp.array[i][j];
    }
}
int computePoly(Polynomial p3, int x) {
    int result = 0;
    for (int i=0; i<p3.terms;i++) 
        result +=p3.array[0][i] * pow(x, p3.array[1][i]);
    return result;
}