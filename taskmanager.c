#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Queue
{
    int front;
    int rear;
    int size;
    char **arr;

} Queue;

// Create the queue
Queue *createQueue(int size)
{
    // allocate memory for the queue itself
    Queue *q = (Queue *)malloc(sizeof(Queue));

    // Set size
    q->size = size;
    // initialize the pointers
    q->front = q->rear = 0;
    // initialize the array and allocate the memory
    q->arr = (char **)malloc(sizeof(char *) * q->size);

    // initialize the arrays of an array
    for (int i = 0; i < q->size; i++)
    {
        q->arr[i] = NULL;
    }
    return q;
}

// Enqueue (add a task)
void Enqueue(Queue *q, char *task)
{
    // check if the queue is full
    if (q->rear == q->size)
    {
        printf("Queue is full\n");
        return;
    }

    // allocate memory for the task string
    q->arr[q->rear] = (char *)malloc(sizeof(char) * (strlen(task) + 1));
    if (q->arr[q->rear] == NULL)
    {
        printf("Memory allocation failed\n");
        return;
    }

    // copy the task string into the queue
    strcpy(q->arr[q->rear], task);

    // increment rear
    q->rear++;
}

// Is Empty (check if the queue is empty)
int isEmpty(Queue *q)
{
    return q->front == q->rear;
}

// Dequeue (remove a task from the front)
char *dequeue(Queue *q)
{
    // check if the queue is empty
    if (isEmpty(q))
    {
        printf("Queue is empty\n");
        return NULL; // or handle this case appropriately
    }

    // get the task string from the front
    char *temp = q->arr[q->front];

    // increment front
    q->front++;

    // return the dequeued task string
    return temp;
}

// Size (get the current size of the queue)
int size(Queue *q)
{
    return q->rear - q->front;
}

// Peek (shows the first task in the queue)
char *peek(Queue *q)
{
    if (isEmpty(q))
    {
        printf("Queue is empty\n");
        return NULL; // or handle this case appropriately
    }

    return q->arr[q->front];
}

// Free Queue (free dynamically allocated memory)
void freeQueue(Queue *q)
{
    // Free memory for each task string in the queue
    for (int i = q->front; i < q->rear; i++)
    {
        free(q->arr[i]);
    }

    // Free memory for the array of task string pointers and the queue structure itself
    free(q->arr);
    free(q);
}

int main()
{
    Queue *q = createQueue(10);

    Enqueue(q, "Mow the lawn");
    Enqueue(q, "Trim the lawn");
    Enqueue(q, "Play games");

    printf("Dequeued: %s\n", dequeue(q));

    printf("Peek: %s\n", peek(q));
    printf("Size: %d\n", size(q));

    freeQueue(q);

    return 0;
}
