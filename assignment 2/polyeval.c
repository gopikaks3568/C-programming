/*2.Read and polynomial of degree n and store in an array. Evaluate this
polynomial for a given value of x.
Eg: 3x^2+2x+1
x=2
evaluation=12+4+1=17*/

#include<stdio.h>
#include<math.h>

typedef struct{
    int exp;
    int coeff;
}polynomial;

void readPoly(polynomial a[],int start,int end){
    int i,k=0;
    for(i=start;i<=end;i++,k++)
    {
        printf("Enter coefficient and exponent of term %d : ",k+1);
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

int evalPoly(polynomial a[],int start,int end,int x){
    int result = 0;
    while(start<=end){
        result += a[start].coeff * pow(x,a[start].exp);
        start++;
    }
    return result;
}


void main(){
    polynomial a[100];
    int n1,x,startA,endA;
    printf("Enter no. of terms of the polynomial: ");
    scanf("%d",&n1);
    startA = 0;
    endA = n1-1;
    readPoly(a,startA,endA);
    printf("Entered polynomial is : ");
    printPoly(a,startA,endA);
    printf("Enter value of x: ");
    scanf("%d",&x);
    printf("Value of Polynomial is %d",evalPoly(a,startA,endA,x));
}