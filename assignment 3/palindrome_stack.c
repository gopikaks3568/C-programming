// C implementation of the approach
#include<stdio.h>
#include<string.h>
char stack[50];
int top=-1;


void push(char arg)
{
	top=top+1;
	stack[top]=arg;
}

char pop()
{
	char c;
	c=stack[top];
	top=top+1;
	return c;
}
int main()
{
	char string[30];
	int i,count=0,len;
	printf("Enetr the string:\n");
	scanf("%s",&string);
	len=strlen(string);
	for ( i = 0; i < len; i++)
	{
		push(string[i]);
	}
	for ( i = 0; i < len; i++)
	{
		if (string[i]==pop()){
			count++;

		}
	}
	if (len==count)
	{
		printf("palindrome");
	}
	else
	{
		printf("not palidrome");
	}
	
	
	
	


}