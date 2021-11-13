#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>

#include "linked_list.h"

static int lenght(void);
static void printList(void);
static bool isEmpty(void);
static void insertFirst(int key, int data);
static struct node* deleteFirst(void);
static struct node *find(int key);
static struct node* delete(int key);
static void sort(void);
static void reverse(struct node** head_ref);

struct node {
    int data;
    int key;
    struct node *next;
};

static struct node *head = NULL;           // Create global pointer on head
static struct node *current = NULL;        // Create global pointer on current 

/////////////////////////////////////////////////////////////////////////////////////////////////
// ------------------------------------------------------------------------------------------------
void linked_lists_main_functions(void)
{
    printf("LINKED LIST\n\r");
    // 1. Fill in linked list
    printf("_______________ 1. Add new nodes to linked list\n\r");
    insertFirst(1,10);
    insertFirst(2,20);
    insertFirst(3,30);
    insertFirst(4,40);
    insertFirst(5,50);
    insertFirst(6,60);
 
    // 2. Print created linked list
    printf("_______________ 2. Print added nodes linked list\n\r");
    printf("Original list\n\r");
    printList();

    // 3. Maesure lenght of current linked list (how many elements there)
    printf("_______________ 3. Measure lenght of linked list\n\r");
    int number = lenght();
    printf("Linked list has %d elements\n\r", number);

    // 4. Found node of list spesial key
    printf("_______________ 4. Found node in linked list\n\r");
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

    // 5. Delete first node from linked list     (Delete all nodes from linked list) 
    printf("_______________ 5. Delete first node from linked list\n\r"); 
    printf("Linked before deleteFirst\n\r");   
    number = lenght();
    printf("Linked list has %d elements\n\r", number);
    printList();
    while(!isEmpty())                               // Delete all nodes from list 
    {
        struct node *temp = deleteFirst();   
        printList();
    }
    printf("Linked after deleteFirst\n\r");
    number = lenght();
    printf("Linked list has %d elements\n\r", number);
    printList();

    // 6. Delete node usin key
    printf("_______________ 6. Print delete some node from linked list\n\r");
    // Add nodes
    printf("Creating new linked list\n\r");
    insertFirst(4, 44);
    insertFirst(2, 22);
    insertFirst(7, 77);
    insertFirst(1, 11);
    insertFirst(9, 99);
    printList();
    number = lenght();
    printf("Linked list has %d elements\n\r", number);
    printf("Delete one node\n\r");
    delete(2);
    number = lenght();
    printf("Linked list has %d elements\n\r", number);
    printList();
 
    // 7. Sort
    printf("_______________ 7. Sort nodes linked list\n\r");
    printf("Sort linked list\n\r");
    printf("Linked list before sort\n\r");
    printList();
    sort();
    printf("Linked list after sort\n\r");
    printList();

    // 8. Reverse
    printf("_______________ 8. Reverse linked lisе\n\r");
    reverse(&head);
    printf("Linked list after reverse\n\r");
    printList();
}
// ------------------------------------------------------------------------------------------------
/////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////
// Print all list
static void printList(void)
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
static void insertFirst(int key, int data)
{
    struct node *link = (struct node *) malloc(sizeof (struct node));   // Create a link

    link->key = key;                        // Write key data on created link
    link->data = data;                      // Write data on created link 
    link->next = head;                      // point it to old first node

    head = link;                            // Point first to new first node
}
// ------------------------------------------------------------------------------------------------
// Delete firct item
static struct node* deleteFirst(void)
{
    struct node *tempLink = head;           // Create pointer
    head = head->next;                      // Mark next to first link as first               

    return tempLink;                        // Return the deleted link
}
// ------------------------------------------------------------------------------------------------
// Is list empty
static bool isEmpty(void)
{
    return head == NULL;            
}
// ------------------------------------------------------------------------------------------------
// How meny elements on linked list
static int lenght(void)
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
static struct node *find(int key)
{
    struct node* current = head;        // Start from the first link

    if(head == NULL)
    {
        return NULL;
    }

    while(current->key != key)          // Navigate through list
    {
        if(current->next == NULL)       // Found end of list
        {
            return NULL;                // 
        }
        else                            // Go on find
        {
            current = current->next;
        }
    }
    return current;                     
}
// ------------------------------------------------------------------------------------------------
// Delete a link with given ke
static struct node* delete(int key)  
{
    // start from the first link
    struct node* current = head;
    struct node* previous = NULL;

    if(head == NULL)                    // If list is empty (protection)
    {
        return NULL;
    }
    
    while(current->key != key)          // Find target key
    {   
        if(current->key == NULL)        // If found last element
        {
            return NULL;
        }
        else
        {
            previous = current;         // Store reference to current link
            current = current->next;    // muve to next list
        }
    }
    if(current == head)                 // Found a match, update the link   ???????
    {   
        head = head->next;              // Change first to point to next link
    }
    else
    {
        previous->next = current->next;  // bypass the current link
    }
    return current;
}
// ------------------------------------------------------------------------------------------------
static void sort(void)
{
    int i, j, k, tempKey, tempData;   
    struct node *current;                               // Local pointer
    struct node *next;                                  // Local pointer

    int size = lenght();
    k = size;

    for(i = 0; i < size - 1; i++, k--)
    {   
        current = head;                                 // Start from head
        next = head->next;                              // Point on next  
        for(j = 1; j < k; j++)
        {
            if(current->data > next->data)              // Condition
            {
                // Swap "data" field
                tempData = current->data;
                current->data = next->data;
                next->data = tempData;
                // Swap "key" field
                tempKey = current->key;
                current->key = next->key;
                next->key = tempKey;
            }
            current = current->next;                    // Muve on next node  
            next = next->next;
        }
    }
}
// ------------------------------------------------------------------------------------------------
static void reverse(struct node** head_ref)
{
    struct node* prev = NULL;
    struct node* current = *head_ref;
    struct node* next;

    while(current != NULL)                      // Do it till the end of list
    {
        next = current->next;
        current->next = prev;
        prev = current;
        current = next;
    }
    *head_ref = prev;
}
// ------------------------------------------------------------------------------------------------











