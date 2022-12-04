/*Write a program to read two polynomials and store them in an array.
Calculate the sum of the two polynomials and display the first
polynomial, second polynomial and the resultant polynomial.*/

#include<stdio.h>

typedef struct{
    int exp;
    int coeff;
}polynomial;


void readPoly(polynomial a[],int start,int end,int num){
    int i,k=0;
    for(i=start;i<=end;i++,k++)
    {
        printf("Enter coefficient and exponent of term %d of polynomial %d: ",k+1,num);
        scanf("%d",&a[i].coeff);
        scanf("%d",&a[i].exp);
    }
}

void printPoly(polynomial a[],int start,int end){
    int i,k=0;
    for(i=start;i<=end;i++,k++)
    {
        printf("%dx^%d",a[i].coeff,a[i].exp);
        if(i!=end){
            printf(" + ");
        }
    }
    printf("\n");
}




void polySum(polynomial a[],int startA,int endA,int startB,int endB,int startD, int *end){
    int i=0,j=0;
    int endD  = *end;
    void addA(){
            a[endD].exp = a[startA].exp;
            a[endD].coeff = a[startA].coeff;
            startA++;
            endD++;
    }

    void addB(){
            a[endD].exp = a[startB].exp;
            a[endD].coeff = a[startB].coeff;
            startB++;
            endD++;
    }
    while(startA<=endA && startB <= endB){
        if(a[startA].exp < a[startB].exp){
            addB();
        }
        else if (a[startA].exp > a[startB].exp){
            addA();
        }
        else {
            a[endD].exp = a[startB].exp;
            a[endD].coeff = a[startA].coeff + a[startB].coeff;
            startA++;
            startB++;
            endD++;
        }
    }

    while (startA<=endA)
    {
        addA();
    }

    while (startB<=endB)
    {
        addB();
    }
    *end = endD-1;
}

void main(){
    polynomial a[100],sum[100];
    int n1,n2,startA,endA,startB,endB,startD,endD;
    printf("Enter no. of terms of 1st polynomial : ");
    scanf("%d",&n1);
    startA = 0;
    endA = n1-1;
    startB = n1;
    printf("Enter no. of terms of 2nd polynomial : ");
    scanf("%d",&n2);
    endB = n1+n2-1;
    startD = n1+n2;
    endD = startD;
    readPoly(a,startA,endA,1);
    readPoly(a,startB,endB,2);
    polySum(a,startA,endA,startB,endB,startD,&endD);
    printf("Polynomial 1 : ");
    printPoly(a,startA,endA);
      printf("Polynomial 2 : ");
    printPoly(a,startB,endB);
    printf("Sum of the polynomials : \n");
    printPoly(a,startD,endD);
}