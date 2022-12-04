//q4
#include<stdio.h>
#include<stdlib.h>
typedef struct{
    int row;    
    int col;
    int val;
}sparse;
void readtoSparse(sparse a[],int count){
    int n;
    printf("Enter the no. of non zero elements of matrix %d: ",count);
    scanf("%d", &n);

    
    a[0].val = n;

  printf("\nEnter the no. of rows and columns: ");
    scanf("%d %d", &a[0].row, &a[0].col);


    printf("\nEnter the sparse matrix representation: \n");
    for (int i = 1; i <= n; i++)
        scanf("%d %d %d", &a[i].row, &a[i].col, &a[i].val);    
}
void printSparse(sparse a[]){  
    printf("\nRows Column Value\n");
    for (int i=0; i<=a[0].val; i++)
        printf("%d      %d      %d\n", a[i].row, a[i].col, a[i].val);
}
void sumofSparse(sparse a[],sparse b[],sparse sum[]){
    int i=1,j=1,l=1;
    if(a[0].row != b[0].row || a[0].col != b[0].col)
    {
        printf("Addition Not Possible");
        exit(0);
    }
    sum[0].row = a[0].row;
    sum[0].col = a[0].col;
    void addA(){
        sum[l].row = a[i].row;
        sum[l].col = a[i].col;
        sum[l].val = a[i].val;
        i++;
        l++;
    }
    void addB(){
        sum[l].row = b[j].row;
        sum[l].col = b[j].col;
        sum[l].val = b[j].val;
        j++;
        l++;
    }
    while(i<=a[0].val && j <= b[0].val){
        if(a[i].row < b[j].row || (a[i].row == b[j].row && a[i].col < b[j].col)){
            addA();
        }
        else if(a[i].row > b[j].row || (a[i].row == b[j].row && a[i].col > b[j].col)){
            addB();
        }
        else if(a[i].row == b[j].row && a[i].col == b[j].col){
            sum[l].row= a[j].row;
            sum[l].col = a[i].col;
            sum[l].val = a[i].val + b[j].val;
            i++;
            j++;
            l++;
        }
    }
    while (i<=a[0].val)
    {
        addA();
    }

    while (j<=b[0].val)
    {
        addB();
    }
    sum[0].val = l-1;
}
int main(){
    sparse a[100],b[100],sum[100];
    readtoSparse(a,1);
    readtoSparse(b,2);
    sumofSparse(a,b,sum);
    printf("\n\nFirst matrix: ");
    printSparse(a);
    printf("\n\nSecond matrix: ");
    printSparse(b);
    printf("\n\nSum:");
    printSparse(sum);
    return 0;
}


