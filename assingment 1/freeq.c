/*
    Find the frequency of occurrence of each character in the string ( histogram)
    Eg: input: This is a test string
    Output: t-3, h-1,i-3,s-4,’ ‘-4…….etc
*/

#include <stdio.h>
#include <string.h>

int main()
{
    char str[100];
    int i, j, count = 0;
    printf("Enter the string: ");
    gets(str);
    for (i = 0; i < strlen(str); i++)
    {
        count = 1;
        for (j = i + 1; j < strlen(str); j++)
        {
            if (str[i] == str[j])
            {
                count++;
                str[j] = '0';
            }
        }

        if (str[i] != '0')
            printf("%c-%d ", str[i], count);
    }
    printf("\n");
    return 0;
} 