/*Varun Padia   241003003101
Program to implements tower of Hanoi using recursion in c */
#include<stdio.h>
#include<stdlib.h>
void towerOfHanoi(int n, char s, char h, char dest);        //s=source, h=helper, dest=destination
int main() 
{
    int n;
    printf("Enter number of rings: ");
    scanf("%d", &n);
    printf("The sequence of moves involved:\n");
    towerOfHanoi(n, 'A', 'B', 'C'); 
    return 0;
}
void towerOfHanoi(int n, char s, char h, char dest) 
{
    if (n == 1) 
    {
        printf("Moves ring 1 from %c to %c\n", s, dest);
        return;
    }
    towerOfHanoi(n - 1, s, dest, h);
    printf("Moves ring %d from %c to %c\n", n, s, dest);
    towerOfHanoi(n - 1, h, s, dest);
}