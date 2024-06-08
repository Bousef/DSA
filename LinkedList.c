// After the completion of this work on doing 2 easy leetcode problems 2 medium and see how you feel from there on linkedList
#include <stdio.h>
#include <stdlib.h>

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
    // return new Node
    return newNode;
}

node *insertHead(list *list, int data)
{
    node *newNode = createNode(data); // create the new Node

    if (list->head == NULL)
    {
        list->head = list->tail = newNode;
    }
    else
    {
        newNode->next = list->head;
        list->head = newNode;
    }
}

node *insertTail(list *list, int data)
{
    // create a new Node
    node *newNode = createNode(data);

    if (list->head == NULL)
    {
        // if no nodes in the list currently set both the head and tail to NULL
        list->head = list->tail = newNode;
    }
    else
    {
        list->tail->next = newNode;
        newNode->next = NULL;
        list->tail = newNode;
    }
}

void insertMiddle(list *list, int data)
{
    // insert in the middle of the list
    node *newNode = createNode(data);
    if (list->head == NULL)
    {
        list->head = list->tail = newNode;
    }
    else
    {
        // create a fast and slow pointer to reach the middle of the list and keeps track of the values in the list as well
        node *fast = list->head;
        node *slow = list->head;

        // Move `fast` two steps and `slow` one step until `fast` reaches the end
        while (fast != NULL && fast->next != NULL) // while the fast pointer does not == null and its next !== NULL meaning as long as its next has a value incriment it
        {
            slow = slow->next;       // move slow by 1
            fast = fast->next->next; // move fast by 2
            // ideally slow will be in the middle of the list once fast reaches the end
        }

        // Insert new node after `slow`
        newNode->next = slow->next; // set the new nodes next to slow next to insert the new node in the middle
        slow->next = newNode;       // update the slow->next to newNode so that newNode is inserted in the middle

        // If new node is inserted at the end, update the tail
        if (newNode->next == NULL)
        {
            list->tail = newNode;
        }
    }
}

void *freeNode(list *my_List, int data)
{
    if (my_List->head == NULL)
    {
        return NULL;
    }
    else
    {
        node *temp = my_List->head;
        my_List->head = my_List->head->next;
        free(temp);
    }
}

int numDirChange(list *my_list)
{
    // steps to solve problem,

    if (my_list->head == NULL || my_list->head->next == NULL || my_list->head->next->next == NULL)
    {
        return 0;
    }
    // Set node a to the first node
    node *a = my_list->head;
    // Set node b to the second node
    node *b = my_list->head->next;
    // set c to the third node
    node *c = my_list->head->next->next;
    int count = 0; // count variable to hold the number of directions

    // while c->next != NULL since we want break out once 1 of the pointers reaches NULL
    while (c->next != NULL)
    {
        // check if a > b && b < c or if a < b && b > c
        if (a > b && b < c || a < b && b > c)
        {
            count++; // incriment count as there has been a change of direction
        }
        a = b;       // update position of a
        b = c;       // update position of b
        c = c->next; // update position of b
    }

    return count; // return the number of directions
}

int check_all_even(list *my_list)
{

    // if the list is empty
    if (my_list == NULL || my_list->head == NULL)
    {
        return 0;
    }

    node *current = my_list->head;

    // if current is NULL it means all nodes visted were even and list is non empty
    if (current == NULL)
    {
        return 1;
    }

    // check if the current nodes data is even

    if (current->data % 2 != 0)
    {
        return 0;
    }

    // create a temp list and loop through that list
    list temp_list;
    temp_list.head = current->next;

    // recursion
    return check_all_even(&temp_list);
}

void printMixed(node *word1, node *word2)
{
    // Consider using a linked list to store a string
    // where each node in order stores one letter in the string
    // the struct used for a single node is included below. Write a fucntion that takes in two pointers to a linked list storing 2 strings
    // and prints out the letters in the string in alternating order, starting with the first letter of the string. If one string runs out of letters, just skip over it
    // if the two strings passed to the function were hello and computer then function should print hceolmlpouter
}

node *deleteMe(node *head, node *me)
{
    // write a function that takes in a pointer to the head of a doubly linked list(head) and a pointer to a node in that list (me), removes that node(me) from the list
    // and returns a pointer to the head node of the resulting doubly linked list. you may assume that both head and me are not NULL, and that me points to a node in the list
    // pointed to by head
}

void insertAfterN(node *head, int M, int N)
{
    // write a function insertAfterN that takes the head of a linked list and two integers M and N ( M != N) and inserts M after all nodes containing N
    //  example if M = 200 and N = 6, then the linked list 3, 6, 4, 6, 6 , 5 will be changed to 3, 6, 200, 4, 6, 200, 6, 200, 5
}

void markEven(node *head)
{
    // Supposed we have a linked list implemented with the structure below. Write a Function that will take in a pointer to the head of a list and inserts a node storing -1
    //  after each even value in the list. If the list is empty of there are no even values in the list, no modifications should be made to the list
    //  (For example, if the initial list had 2, 6, 7, 1, 3, and 8, the resulting list would have 2, -1, 6, -1, 7, 1, 8, -1.)
}

node *make_circle(struct node *head)
{
    if (head == NULL)
    {
        return NULL;
    }

    node *temp = head;

    while (temp->next != NULL)
    {
        temp = temp->next;
    }

    if (temp->next == NULL)
    {
        temp->next = head;
    }
    return head;
}

// print function
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
    insertTail(my_list, 2);
    insertTail(my_list, 2);
    insertTail(my_list, 2);
    insertTail(my_list, 2);
    insertTail(my_list, 1);
    insertTail(my_list, 6);
    insertTail(my_list, 4);
    insertTail(my_list, 8);
    insertTail(my_list, 2);
    printf("%d\n", check_all_even(my_list));
    printf("%d\n", numDirChange(my_list));
    printList(my_list);
}

// , 2, 2, 5, 6, 4, 8, 3
/*    for (int i = 0; i < 10; i++)
    {
        insertHead(my_list, i);
    }
    // Inserts numbers through the middle
    for (int i = 0; i < 10; i++)
    {
        insertTail(my_list, i);
    }
    // inserts value in the middle
    for (int i = 0; i < 1; i++)
    {
        insertMiddle(my_list, i);
    }
    for (int i = 0; i < 2; i++)
    {
        freeNode(my_list, i);
    }*/