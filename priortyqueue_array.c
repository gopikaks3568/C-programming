#include<stdio.h>
#include<stdlib.h>
#define MAX_SIZE 100
typedef struct 
{
    int priority;
    int value;
} Element;

typedef struct 
{
    Element elements[MAX_SIZE];
    int size;
}priorityQueue;

void intit(priorityQueue *queue){
    queue->size=0;

}

int is_empty(priorityQueue *queue){
    return queue->size==0;
}

void push(priorityQueue *queue,int value ,int priority){
    if (queue->size==MAX_SIZE){
        printf("Error: queue is full \n");
        return;
    }
}

Element new_element;
new_element.priority=priority;
new_element.value=value;
int i;
for(i=queue->size;i>0&& queue->elements[i-1].priority <priority;i--){
    
}