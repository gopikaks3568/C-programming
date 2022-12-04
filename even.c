#include <stdio.h>
int main()
{
    int n;
    printf("Enter the number: \n");
    scanf("%d",&n);
    if (n%2==0)
        {
            printf("Yes the number is even");
        }
    else if (n%3==0)
        {
            printf("the number is odd");
        }
    
return 0;
}