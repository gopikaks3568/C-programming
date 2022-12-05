#include<stdio.h>
#include<stdlib.h>
void traverse();
void insertAfternode();


struct Node
{
    int info;
    struct Node*next;
};

struct Node*start=NULL;


