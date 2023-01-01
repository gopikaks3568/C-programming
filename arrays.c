#include <stdio.h>
#define MAX_SIZE 100
int main()
{   
    int n, arr[MAX_SIZE];
    printf("Enter the number of elements:");
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &arr[i]);
    }
  
    printf("[");
    for (int i = 0; i < n; i++)
    {
        printf(" %d ,", arr[i]);
    }
    printf("]");
}