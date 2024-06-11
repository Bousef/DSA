// Music manager
//  Linked List practice

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct node
{
    char *artist;
    char *songName;
    char *genre;
    int duration;
    struct node *next;
} node;

typedef struct List
{
    node *head;
    node *tail;
} list;
// Create a new Node

node *createNode(char *artist, char *songName, char *genre, int duration)
{
    // Allocate Memory for a new Node
    node *newNode = malloc(sizeof(node));
    // Allocate memory for the name of the artist
    newNode->artist = malloc(sizeof(char) * strlen(artist) + 1);
    // Allocate memory for the name of the song
    newNode->songName = malloc(sizeof(char) * strlen(songName) + 1);
    // Allocate memory for the name of the genre
    newNode->genre = malloc(sizeof(char) * strlen(genre) + 1);

    // when dealing with assigning strings memory wise, you want to copy that string over into that node using strcpy by just using = it assigns the memory address and not the string itself
    /*When you allocate memory for a string using malloc(),
    you get a block of memory that can hold the characters of the string, but it's up to you to actually copy the characters into that memory block. This is where strcpy() comes into play.*/
    strcpy(newNode->artist, artist);
    strcpy(newNode->songName, songName);
    strcpy(newNode->genre, genre);
    newNode->duration = duration;
    newNode->next = NULL;
    return newNode;
}

void insertHead(list *my_list, char *artist, char *songName, char *genre, int duration)
{
    node *newNode = createNode(artist, songName, genre, duration);

    if (my_list->head == NULL)
    {
        my_list->head = my_list->tail = newNode;
    }
    else
    {
        newNode->next = my_list->head;
        my_list->head = newNode;
    }
}

void printList(list *my_list)
{
    node *current = my_list->head;

    // Traverse the list until the current node is NULL
    while (current != NULL)
    {
        // Print the data of the current node
        printf("Artist: %s, Song: %s, Genre: %s, Duration: %d\n",
               current->artist, current->songName, current->genre, current->duration);

        // Move to the next node
        current = current->next;
    }
}

// void playListManager(list *my_list, char *artist, char *songName, char *genre, int duration){
//     //Should allow you to access the playlist of a specific artist

// }

int main()
{
    list *my_list = malloc(sizeof(list));

    insertHead(my_list, "Abel", "lonley night", "pop", 3);
    insertHead(my_list, "Kanye", "Gold Digger", "Hip-pop", 3);
    insertHead(my_list, "Kanye", "New Workout Plan", "Hip-pop", 3);
    insertHead(my_list, "Drake", "Rich Flex", "pop", 3);

    printList(my_list);
}