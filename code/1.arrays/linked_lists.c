
#include "stdio.h"
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>

#include "linked_lists.h"

void printList(void);
void insertFirst(int key, int data);

// bool isEmpty(void);
// int length(void);

struct node {
    int data;
    int key;
    struct node *next;
};
struct nade *head = NULL;           // Create pointer on head
struct node *current = NULL;        // Create pointer on current 

/////////////////////////////////////////////////////////////////////////////////////////////////
// ------------------------------------------------------------------------------------------------
void main_linked_lists_functions(void)
{
    printf("Linked lists\n\r");

    insertFirst(1,10);
    insertFirst(2,20);
    insertFirst(3,30);
    insertFirst(4,40);
    insertFirst(5,50);
    insertFirst(6,60);

    // printf("Original list\n\r");

    // printList();

    // int number = length();
    // printf("Linked list has %d elements\n\r", number);

    // Problems start below  <<<<<<<<<<<<
    printf("TEST !!!\n\r");
    printList();
    struct node *temp = deleteFirst();

    int number = length();
    printf("Linked list has %d elements\n\r", number);

    insertFirst(7,70);

    number = length();
    printf("Linked list has %d elements\n\r", number);

    struct node *foundLink = find(3);
    if(foundLink != NULL)
    {
        printf("Elemt found\n\r");
        printf("(%d, %d)\n\r", foundLink->key, foundLink->data);   
    }   
    else
    {
        printf("Element not found\n\r");
    }


}
// ------------------------------------------------------------------------------------------------
/////////////////////////////////////////////////////////////////////////////////////////////////
// Print all list
void printList(void)
{
    struct node *ptr = head;        // Set on first element (head)
    printf("\n[");

    // Start from the begining
    while(ptr != NULL)
    {
        printf("(%d, %d)", ptr->key, ptr->data);
        ptr = ptr->next;
    }
    printf("]\n\r");
}
// ------------------------------------------------------------------------------------------------
// Insert link at the first location
void insertFirst(int key, int data)
{
    struct node *link = (struct node *) malloc(sizeof (struct node));   // Create a link

    link->key = key;                        // Write key data on created link
    link->data = data;                      // Write data on created link 
    link->next = head;                      // point it to old first node

    head = link;                            // Point first to new first node
}
// ------------------------------------------------------------------------------------------------
// Delete firct item
// struct node* deleteFirst(void)
// {
//     struct node *tempLink = head;           // Save refernse to first link
//     head = head->next;                      // Mark next to first link

//     return tempLink;                        // Return the deleted link
// }
// ------------------------------------------------------------------------------------------------
// Is list empty
bool isEmpty(void)
{
    return head == NULL;            
}
// ------------------------------------------------------------------------------------------------
// How meny elements on linked list
int length(void)
{
    int lenght = 0;
    struct node *current;

    for(current = head; current != NULL; current = current->next)
    {
        lenght++;
    }
    return lenght;
}
// ------------------------------------------------------------------------------------------------
// Find a link with given key
// struct node *find(int key)
// {
//     struct node* current = head;        // Start from the first link

//     if(head == NULL)
//     {
//         return NULL;
//     }

//     while(current->key != key)          // Navigate through list
//     {
//         if(current->next == NULL)       // Found end of list
//         {
//             return NULL;                // 
//         }
//         else                            // Go on find
//         {
//             current = current->next;
//         }
//     }
//     return current;                     
// }
// ------------------------------------------------------------------------------------------------
// Delete a link with given ke
// struct node* delete(int key)  
// {
//     // start from the first link
//     struct node* current = head;
//     struct node* previous = NULL;

//     if(head == NULL)                // If list is empty
//     {
//         return NULL;
//     }
    
//     while(current->key != key)      // Find target key
//     {   
//         if(current->key != NULL)        // If found last element
//         {
//             return NULL;
//         }
//         else
//         {
//             previous = current;         // Store reference to current link
//             current = current->next;    // muve to next list
//         }
//     }
//     if(current == head)                 // Found a match, update the link   ???????
//     {   
//         head = head->next;              // Change first to point to next link
//     }
//     else
//     {
//         previous->next = current->next;  // bypass the current link
//     }
//     return current;
// }
// ------------------------------------------------------------------------------------------------