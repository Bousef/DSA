#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_TASK_LENGTH 100

typedef struct node
{
    char task[MAX_TASK_LENGTH];
    struct node *next;
} node;

typedef struct List
{
    node *head;
    node *tail;
} list;
// create a node

node *createNode(char *task)
{
    // allocate the memory for this node
    node *newNode = malloc(sizeof(node));
    // copy the task into the new node
    strcpy(newNode->task, task);
    // set the next to NULL
    newNode->next = NULL;
    // return the new node
    return newNode;
}

// Remove a task by position in the list
void removeTaskByPostion(list *my_list, int position)
{
    node *cur = my_list->head;
    node *prev = NULL;
    int i = 0; // current position
    while (cur != NULL)
    {
        // if the current position is the position we want to remove
        if (i == position)
        {
            // if the previous is NULL, it means we are removing the head
            if (prev == NULL)
            {
                // set the head to the next node
                my_list->head = cur->next;
            }
            else
            {
                // set the next of the previous to the next of the current;
                prev->next = cur->next;
            }
            // free the current node
            free(cur);
            return;
        }
        // move to the next node
        prev = cur;
        cur = cur->next;
        i++;
    }
    printf("Task not found");
}

// display all task in the list

void printAllTask(list *my_list)
{
    node *cur = my_list->head;

    while (cur != NULL)
    {
        printf("Task: %s \n", cur->task);
        cur = cur->next;
    }
    printf("NULL");
}

// add a task to the end of the list
void insertTaskTail(list *my_list, char *task)
{
    node *newNode = createNode(task);
    if (my_list->head == NULL)
    {
        my_list->head = my_list->tail = newNode;
    }
    else
    {
        my_list->tail->next = newNode;
        newNode->next = NULL;
        my_list->tail = newNode;
    }
}
int main()
{
    list *my_list = malloc(sizeof(list));

    insertTaskTail(my_list, "Clean the yard");
    insertTaskTail(my_list, "Clean the house");
    insertTaskTail(my_list, "Clean the dog");
    removeTaskByPostion(my_list, 3);
    printAllTask(my_list);
    return 0;
}
