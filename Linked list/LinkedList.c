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

node *reverseList(list *list)
{
    node *current = list->head;
    node *prev = NULL;
    node *next = NULL;

    while (current != NULL)
    {
        next = current->next; // set the next node to the currents next
        current->next = prev; // set the currents next to NULL esentially setting the current heads next to nULL
        prev = current;       // update prev to be at the end of the list
        current = next;       // move to the next node in the list
    }
    list->tail = list->head; // update the tail to be the current head of the list
    list->head = prev;       // update head to be the tail
    return prev;
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

// void printMixed(node *word1, node *word2)
// {

//     // create temp nodes storing the data
//     node *temp1 = word1->data;
//     node *temp2 = word2->data;

//     // Loop through both until temp1 and temp2 are NULL
//     while (temp1 != NULL || temp2 != NULL)
//     {
//         if (temp1 != NULL)
//         {
//             printf("%c", temp1->data);
//             temp1 = temp1->next;
//         }
//         if (temp2 != NULL)
//         {
//             printf("%c", temp2->data);
//             temp2 = temp2->next;
//         }
//     }
// }

node *deleteMe(node *head, node *me)
{

    // check if the head is to be deleted

    if (head == me)
    {
        head = me->next;
    }

    // update the next pointer of the previous node, if it exists

    if (me->prev != NULL)
    {

        me->prev->next = me->next;
    }

    if (me->next != NULL)
    {
        me->next->prev = me->prev;
    }
    free(me);

    return head;
}

void insertAfterN(node *head, int M, int N)
{
    if (head == NULL)
    {
        return;
    }

    // temp node to store the head
    node *current = head;

    // loop through the list
    while (current->next != NULL)
    {
        // if the current node is == to N
        if (current->data == N)
        {
            // create a temp node to store M
            node *temp = malloc(sizeof(node));
            temp->data = M;             // store M
            temp->next = current->next; // insert M after current
            current->next = temp;       // insert M after current
        }
        else
        {
            // continue traversing if current data is not N
            current = current->next;
        }
    }
}

void markEven(node *head)
{
    node *current = head;

    while (current != NULL || current)
    {
        if (current->data % 2 == 0)
        {
            node *temp = malloc(sizeof(node));
            temp->data = -1;
            temp->next = current->next;
            current->next = temp;

            // Move to the next node after the inserted one
            current = temp->next;
        }
        else
        {
            current = current->next;
        }
    }
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
    insertTail(my_list, 1);
    insertTail(my_list, 2);
    insertTail(my_list, 3);
    insertTail(my_list, 4);
    insertTail(my_list, 5);
    insertTail(my_list, 6);
    insertTail(my_list, 7);
    insertTail(my_list, 8);
    insertTail(my_list, 9);
    // printf("%d\n", check_all_even(my_list));
    // printf("%d\n", numDirChange(my_list));
    reverseList(my_list);

    printList(my_list);
}