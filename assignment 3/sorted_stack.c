//implement a sorted push so that stack is always maintained in sorted order.
//Debugged and working 
#include <stdio.h>
#define MAX 100
int Stack[MAX],top=-1;
void push(int data)
{
    if(top==MAX-1)
        printf("\nStack Overflow/full");
    else if(top==-1)
        Stack[++top]=data;
    else
    {
        int tempStack[MAX],tempTop=-1;
        while(data>Stack[top]&&top!=-1)
        {
            int del=Stack[top--];
            tempStack[++tempTop]=del;
        }
        Stack[++top]=data;
        while(tempTop>=0)
        {
            int del=tempStack[tempTop--];
            Stack[++top]=del;
        }
    }    
}
void pop()
{
    int del;
    if(top==-1)
        printf("\nStack empty.");
    else
    {
        del=Stack[top--];
        printf("\nDeleted : %d",del);
    }    
}
void display()
{
    if(top==-1)
        printf("\nStack empty!!\n");
    else
    {
        printf("\n");
        for(int i=0;i<=top;i++)
        {
            printf("%d\n",Stack[i]);
        }
    }    
}
int main()
{
    int ch,element;
    do
    {
        printf("\n1.Push");
        printf("\n2.Pop");
        printf("\n3.Display stack.");
        printf("\n4.Exit");
        printf("\n\nEnter the choice(1/2/3/4): ");
        scanf("%d",&ch);
        switch(ch)
        {
            case 1:
            printf("pushing in progress\n");
                printf("\nEnter the element : ");
                scanf("%d",&element);
                push(element);
                break;

            case 2:
                printf("poping in progress");
                pop();
                break;

            case 3:
                printf("The sorted stack is:");
                display();
                break;    
        }
    }while(ch<4);
    return 0;
}




