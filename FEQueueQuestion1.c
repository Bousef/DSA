// implementing a queue in c with an array

#include <stdio.h>
#include <stdlib.h>

typedef struct
{
    int values[20];
    int front, size;
} cQueue;

int enqueue(cQueue *thisQ, int item)
{
    /* A queue is implemented as an array. The queue has the 2 attributes, front and size. front is the index in the array
where the next element to be removed from the queue can be found, if the queue is non-empty. (If the queue is
empty, front may be any valid array index from 0 to 19.) size is the total number of elements currently in the
queue. For efficient use of resources, elements can be added to the queue not just at the end of the array but also
in the indices at the beginning  of the array before front. Such a queue is called a circular queue. A circular queue
has the following structure:*/

    /*   Write an enqueue function for this queue. If the queue is already full, return 0 and take no other action.
If the queue isn't full, enqueue the integer item into the queue, make the necessary adjustments, and
return 1. Since the array size is hard-coded to be 20 in the struct above, you may use this value in your
code and assume that is the size of the array values inside the struct. */

    // check to see if the queue is full, if its full we return 0
    if (thisQ->size == 20)
    {
        return 0;
    }

    // otherwise we circle the front pointer around the array to check for a empty spot by doing the current front pointer + the total amount of elements in the array
    // modded by the size of the array
    thisQ->values[(thisQ->front + thisQ->size) % 20] = item;
    thisQ->size++; // value has been added so increase num elements
    return 1;      // return 1
}

// we do thisQ->front + thisQ->size because thisQ->front gives the starting index of the queue

// and since thisQ->size indicates how mnay elements are in the queue currently, adding them together gives the index
// of where the new element should be inserted, considering the elements already in the queue