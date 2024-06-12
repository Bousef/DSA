#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct node
{
    int data;
    struct node *next;
    struct node *prev;
} node;

typedef struct List
{
    node *head;
    node *tail;
} list;

node *createNode(int data)
{
    // Allocate memory for the new Node
    node *newNode = malloc(sizeof(node));
    // set the data to the new Node
    newNode->data = data;
    // set nextPointer to Null
    newNode->next = NULL;

    newNode->prev = NULL;
    // return new Node
    return newNode;
}

node *insertHead(list *list, int data)
{
    node *newNode = createNode(data); // create the new Node

    if (list->head == NULL) // if the list is empty
    {
        list->head = list->tail = newNode; // set the head and tail to the new node
    }
    else
    {
        // if list is not empty set the new nodes next to the current head
        newNode->next = list->head;
        list->head->prev = newNode;
        list->head = newNode; // update the current head to the new Node
    }
}

node *insertTail(list *list, int data)
{
    // create a new Node
    node *newNode = createNode(data);

    if (list->head == NULL) // if the list is empty
    {
        // if no nodes in the list currently set both the head and tail to NULL
        list->head = list->tail = newNode;
    }
    else
    {
        // set the next of the current tail to the new Node
        list->tail->next = newNode;
        // set the new Node to be the new tail so we set its next to NULL and set list->tail to new node
        newNode->next = NULL;
        list->tail = newNode;
    }
}

void findPairSum(list *my_list, int x)
{

    // Initialize two pointer variables to find the candidate elements in the sorted doubly linked list
    node *first = my_list->head;
    node *last = my_list->head;
    bool found = false;

    while (last->next != NULL)
    {
        last = last->next;
    }

    while (first != last && last->next != first)
    {
        if (first->data + last->data == x)
        {
            // we found a pair
            printf("(%d , %d)", first->data, last->data);
            first = first->next;
            last = last->prev;
            found = true;
        }
        else
        {
            if (first->data + last->data < x)
            {
                first = first->next;
            }
            else
            {
                last = last->prev;
            }
        }
        if (!found)
        {
            printf("No pairs found\n");
        }
    }
}

list *printList(list *my_List)
{
    // print list
    node *cur = my_List->head;
    while (cur != NULL)
    {
        // Print the list
        printf("%d -> ", cur->data);
        // Move to the next node
        cur = cur->next;
    }
    printf("NULL\n");
}

int main()
{
    list *my_list = malloc(sizeof(list));

    my_list->head = my_list->tail = NULL;
    // inserts numbers from the head
    insertHead(my_list, 1);
    insertHead(my_list, 2);
    insertHead(my_list, 3);
    insertHead(my_list, 4);
    insertHead(my_list, 5);
    insertHead(my_list, 6);
    insertHead(my_list, 7);
    insertHead(my_list, 8);
    insertHead(my_list, 9);

    findPairSum(my_list, 10);
}