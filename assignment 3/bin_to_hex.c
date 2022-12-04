//Convert a given decimal number into binary and hex.
//degubbed and working
#include<stdio.h>
#include<stdlib.h>
#define MAX 50
int isEmpty(int top, int stack_arr[]);
void push(int x, int *top, int stack_arr[]);
int pop(int *top, int stack_arr[]);
void DecToBin(int num);
void DectoHex(int num);
int main()
{
        int num;
        printf("\nEnter an integer : ");
        scanf("%d",&num);
        printf("\nBinary Equivalent is : ");
        DecToBin(num);
        printf("\nHexadecimal Equivalent is : ");
        DectoHex(num);
        printf("\n");
}

void DecToBin(int num)
{
        int stack[MAX], top=-1, rem;
        while(num!=0)
        {
                rem = num%2;
                push(rem, &top, stack);
                num/=2;
        }
        while(top!=-1)
                printf("%d", pop(&top, stack));
        printf("\n");
}

void DectoHex(int num)
{
        int stack[MAX],top=-1, rem;
        while(num!=0)
        {
                rem = num%16;
                push(rem,&top,stack);
                num/=16;
        }
        while(top!=-1)
        {
        if(stack[top]>9)
        {
         stack[top]=stack[top]+55;
         printf("%c",pop(&top,stack));
        }
        else if(stack[top]<10)
        {
        	printf("%d", pop(&top, stack));
       	 	printf("\n");
		    }
	  }
}


void push(int x, int *top, int stack_arr[])
{
        if(*top == (MAX-1))
                printf("Stack Overflow\n");
        else
        {
                *top=*top+1;
                stack_arr[*top] = x;
        }
}

int pop(int *top, int stack_arr[])
{
        int x;
        if(*top == -1)
        {
                printf("Stack Underflow\n");
                exit(1);
        }
        else
        {
                x = stack_arr[*top];
                *top=*top-1;
        }
        return x;
}