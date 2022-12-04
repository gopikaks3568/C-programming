/*
    An n x 4 array stores 4 bit binary numbers. Read the matrix and print the 
    hexadecimal equivalent of the binary numbers.
/

/ Input:

    3
    1 0 1 1
    1 1 0 1
    1 0 0 1

    Output:

    B
    D
    9

*/

#include <stdio.h>
#include <math.h>

int main()
{
    int n, arr[n][4];
    printf("Enter the number of rows(n): ");
    scanf("%d", &n);

    printf("Enter the matrix:\n");
    for (int i = 0; i < n; i++)
        for (int j = 0; j < 4; j++)
            scanf("%d", &arr[i][j]);

    for (int i = 0; i < n; i++)
    {
        int sum = 0;
        for (int j = 0; j < 4; j++)
            sum += arr[i][j] * pow(2, 3 - j);
        if (sum < 10)
            printf("%d\n", sum);
        else
            printf("%c\n", sum + 55);
    }

    return 0;
}