int main()
{
    char colour[20];
    char plural_noun[20];
    char celebrity[20];
    printf("Enter the colour\n");
    scanf("%s",&colour);
    printf("Enter the plural noun:\n");
    scanf("%s",&plural_noun);
    printf("Enter a celebrity:\n");
    scanf("%s",&celebrity);


    printf("Roses are %s \n", colour);
    printf("%s is blue  \n",plural_noun);
    printf("I love %s  \n",celebrity);
    return 0;
}