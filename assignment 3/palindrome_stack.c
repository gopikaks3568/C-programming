//program to check given string is palidrome or not
#include<stdio.h>
#include<string.h>
#include<ctype.h>
#include<stdlib.h>
char stack[50];
int top=-1;

void push(char arg)
{
    top=top+1;
    stack[top]=arg;
}
char pop(){
    char c;
    c=stack[top];
    top=top-1;
    return c;
}


int main()
{
    char string[30],b;
    int i,count=0,len;
    printf("Enter the String\n");
    scanf("%s",string);
    len=strlen(string);
    for ( i = 0; i < len; i++)
    {
        string[i]=tolower(string[i]);
        b=string[i];
        push(b);
    }
     for ( i = 0; i < len; i++)
     {
        if (string[i]==pop())
        {
            count=count+1;
        }

     }
     if (len==count){
        printf("Given String is palindrome\n");
     }
     else
     {
        printf("given String is not palindrome");
     }



}