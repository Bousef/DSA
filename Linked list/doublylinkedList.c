// creating a doubly linked list

#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
    int data;
    struct node *prev;
    struct node *next;
} node;

typedef struct List
{
    node *head;
    node *tail;
} list;

// create a node

node *createNode(int data)
{
    node *newNode = malloc(sizeof(node));
    newNode->data = data;
    newNode->next = NULL;
    newNode->prev = NULL;
    return newNode;
};

// insert head

void insertHead(list *my_list, int data)
{
    node *newNode = createNode(data);

    if (my_list->head == NULL)
    {
        my_list->head = my_list->tail = newNode;
    }
    else
    {
        newNode->next = my_list->head;
        my_list->head->prev = newNode;
        my_list->head = newNode;
    }
}

void insertTail(list *my_list, int data)
{
    node *newNode = createNode(data);
    if (my_list->head == NULL)
    {
        my_list->head = my_list->tail = newNode;
    }
    else
    {
        my_list->tail->next = newNode;
        newNode->next = NULL;
        newNode = my_list->tail;
    }
}

void printListForward(list *my_list)
{
    node *current = my_list->head;

    while (current != NULL)
    {
        printf("%d ->", current->data);
        current = current->next;
    }
    printf("NULL\n");
}

void printListBackward(list *my_List)
{
    node *current = my_List->tail;

    while (current != NULL)
    {
        printf("%d<-->", current->data);
        current = current->prev;
    }
    printf("NULL\n");
}

node *reverseDoublyLinkedList(list *my_list)
{
    // Current, prev and a next
    node *current = my_list->head;
    node *prev = NULL;
    node *next = NULL;
    if (my_list->head == NULL)
    {
        return NULL;
    }

    while (current != NULL)
    {
        next = current->next;
        current->next = prev;
        current->prev = next; // update the previous pointers as well to make sure links stay connected
        prev = current;
        current = next;
    }
    // set the head to the tail and the tail to the head to reverse the list
    my_list->tail = my_list->head;
    // set the head to the previous node
    my_list->head = prev;

    return prev;
}

void removeFromHead(list *my_list)
{
    node *temp = NULL;

    if (my_list->head == NULL)
    {
        return NULL;
    }
    if (my_list->head->next == NULL)
    {
        free(my_list->head);
        my_list->tail = NULL;
    }
    else
    {
        temp = my_list->head;
        my_list->head = my_list->head->next;
        my_list->head->prev = NULL;
        free(temp);
    }
}
int main()
{
    list *my_list = malloc(sizeof(list));

    insertHead(my_list, 1);
    insertHead(my_list, 2);
    insertHead(my_list, 3);
    insertHead(my_list, 4);
    insertHead(my_list, 5);
    insertHead(my_list, 6);
    insertHead(my_list, 7);
    insertHead(my_list, 8);
    insertHead(my_list, 9);
    insertHead(my_list, 10);
    insertTail(my_list, 11);
    reverseDoublyLinkedList(my_list);
    removeFromHead(my_list);
    printListForward(my_list);
}