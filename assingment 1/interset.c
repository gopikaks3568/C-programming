/*
Consider two sets S1={1,2,3,4}, and S2={3,4,5}. Find the intersection of S1 and S2={3,4}.
Implement the set operation intersection using arrays.
*/
#include <stdio.h>
int main()
{
    int s1[100], s2[100], com[100];
    int n1, n2;

    printf("Enter the no of elements in S1:\n");
    scanf("%d", &n1);
    printf("Enter the elements in S1:\n");
    for (int i = 0; i < n1; i++)
        scanf("%d", &s1[i]);

    printf("Enter the no of elements in S2:\n");
    scanf("%d", &n2);
    printf("Enter the elements in S2:\n");
    for (int i = 0; i < n2; i++)
        scanf("%d", &s2[i]);

    int k = 0;
    for (int i = 0; i < n1; i++)
    {
        for (int j = 0; j < n2; j++)
        {
            if (s1[i] == s2[j])
            {
                com[k] = s1[i];
                k++;
                break;
            }
        }
    }

    printf("Intersection of two sets is: ");
    for (int i = 0; i < k; i++)
        printf("%d ", com[i]);

    printf("\n");
    return 0;
}
