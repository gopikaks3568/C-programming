#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    int priority;
    struct node *next;
};

struct node *newNode(int d, int p)
{
    struct node *temp = (struct node *)malloc(sizeof(struct node));
    temp->data = d;
    temp->priority = p;
    temp->next = NULL;

    return temp;
}

int peek(struct node **head)
{
    return (*head)->data;
}

void pop(struct node **head)
{
    struct node *temp = *head;
    (*head) = (*head)->next;
    free(temp);
}

void push(struct node **head, int d, int p)
{
    struct node *start = (*head);

    // Create new Node
    struct node *temp = newNode(d, p);

    // Special Case: The head of list has lesser
    // priority than new node. So insert new
    // node before head node and change head node.
    if ((*head)->priority > p)
    {
        // Insert New Node before head
        temp->next = *head;
        (*head) = temp;
    }
    else
    {
        // Traverse the list and find a
        // position to insert new node
        while (start->next != NULL &&
               start->next->priority < p)
        {
            start = start->next;
        }

        // Either at the ends of the list
        // or at required position
        temp->next = start->next;
        start->next = temp;
    }
}

// Function to check is list is empty
int isEmpty(struct node **head)
{
    return (*head) == NULL;
}

int main()
{
    // Create a Priority Queue
    // 7->4->5->6
    struct node *pq = newNode(4, 1);
    push(&pq, 5, 2);
    push(&pq, 6, 3);
    push(&pq, 7, 0);

    while (!isEmpty(&pq))
    {
        printf("%d ", peek(&pq));
        pop(&pq);
    }

    return 0;
}
