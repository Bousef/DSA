#include <stdio.h>
#include <stdlib.h>

struct queue
{
    int *array;
    int num_elements;
    int front;
    int capacity;
};

int dequeue(struct queue *q)
{
    /* The queue contains the array and three attributes: the current number of elements in the array, the current
front of the queue, and the maximum capacity. Elements may be added to the queue not just at the end of
the array but also in the indices at the beginning of the array before front. Such a queue is called a circular
queue.
Write a function to implement the dequeue functionality for the queue, while ensuring that no null pointer
errors occur. Your function should take in 1 parameter: a pointer to the queue. Your function should return
the integer that was dequeued. If the queue is NULL or if there are no elements to dequeue, your function
should return 0.*/

    // if array is empty or the number of elements == 0
    if (q->array == NULL || q->num_elements == 0)
    {
        return 0; // queue empty
    }
    // store the value we want to delete
    int dequeued = q->array[q->front];
    // circular queue
    q->front = (q->front) + 1 % q->capacity;
    // make sure to decrease the number of elements as we are dequeuing
    q->num_elements--;
    // return the element that has been dequeued
    return dequeued;
}
