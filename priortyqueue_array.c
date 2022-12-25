#define MAX_SIZE 100

typedef struct {
  int data;
  int priority;
} Element;

typedef struct {
  Element elements[MAX_SIZE];
  int size;
} PriorityQueue;

void push(PriorityQueue *queue, int data, int priority) {
  if (queue->size >= MAX_SIZE) {
    // Queue is full, cannot add more elements
    return;
  }

  Element element = {data, priority};
  int i;
  for (i = queue->size - 1; i >= 0; i--) {
    if (queue->elements[i].priority <= priority) {
      break;
    }
    queue->elements[i + 1] = queue->elements[i];
  }
  queue->elements[i + 1] = element;
  queue->size++;
}

int pop(PriorityQueue *queue) {
  if (queue->size == 0) {
    // Queue is empty, cannot pop an element
    return -1;
  }

  int data = queue->elements[queue->size - 1].data;
  queue->size--;
  return data;
}

int main() {
  PriorityQueue queue;
  queue.size = 0;

  push(&queue, 1, 2);
  push(&queue, 2, 1);
  push(&queue, 3, 3);
  push(&queue, 4, 0);

  printf("%d\n", pop(&queue));  // 4
  printf("%d\n", pop(&queue));  // 2
  printf("%d\n", pop(&queue));  // 1
  printf("%d\n", pop(&queue));  // 3
}
