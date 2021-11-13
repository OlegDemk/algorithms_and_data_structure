#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>

static bool isEmpty(void);
static int lenght(void);
static void displayForward(void);
static void displayBackward(void);
static void insertFirst(int key, int data);
static void insertLast(int key, int data);
static struct node* deleteFirst(void);
static struct node* deleteLast(void);
static struct node* delete(int key);
extern bool insertAfter(int key, int newKey, int data);


struct node{
    int data;
    int key;

    struct node *next;
    struct node *prev;
};

static struct node *head = NULL;           // This link always point to first link
static struct node *last = NULL;           // This link always point to last link
static struct node *current = NULL;

// ------------------------------------------------------------------------------------------------
void doubly_linked_list_main_function(void)
{
    printf("DOUBLY LINKED LIST\n\r");

     // 1. Fill in double linked list
    printf("_______________ 1. Add new nodes to double linked list\n\r");
    insertFirst(7, 77);
    insertFirst(4, 44);
    insertFirst(3, 33);
    insertFirst(6, 66);
    insertFirst(9, 99);

    // 2. Print created double linked list
    printf("_______________ 2. Print all double linked list\n\r");
    displayForward();
    displayBackward();
    printf("\n\r");

    // 3. How many nodes on double linked list
    printf("_______________ 3. Measure lenght of double linked list\n\r");
    int number = lenght();
    printf("Double linked list has %d elements\n\r", number);

    // 4. Insert node on the last
    printf("_______________ 4. Insert node on lasr place in double linked list\n\r");
    printf("Before insert\n\r");
    displayForward();
    insertLast(1, 11);
    printf("\n\r");
    printf("After insert\n\r");
    displayForward();
    printf("\n\r");

    // 5. Delete first node
    printf("_______________ 5. Delete first node from double linked list\n\r");
    printf("Before delete\n\r");
    displayForward();
    deleteFirst();
    printf("\n\r");
    printf("After delete\n\r");
    displayForward();
    printf("\n\r");

    // 6. Delete last node
    printf("_______________ 6. Delete last node from double linked list\n\r");
    printf("Before delete\n\r");
    displayForward();
    deleteLast();
    printf("\n\r");
    printf("After delete\n\r");
    displayForward();
    printf("\n\r");

    // 7. Delete node using key
    insertFirst(3, 33);
    insertFirst(1, 11);
    insertFirst(8, 88);
    printf("_______________ 7. Delete node using key from double linked list\n\r");
    printf("Before delete\n\r");
    displayForward();
    delete(1);
    printf("\n\r");
    printf("After delete\n\r");
    displayForward();
    printf("\n\r");


    // 8. Insert node after 
    printf("_______________ 8. Insert first node using key from double linked list\n\r");
    printf("Before insert\n\r");
    displayForward();
    printf("\n\r");
    if (insertAfter(6, 99, 99))
    {
        printf("OK!\n\r");
    }
    else
    {
        printf("ERROR !!!\n\r");
    }
    printf("After insert\n\r");
    displayForward();
    printf("\n\r");
    



}
// ------------------------------------------------------------------------------------------------
////////////////////////////////////////////////////////////////////////////////////////////////////
static bool isEmpty(void)
{
    return head == NULL;
}
// ------------------------------------------------------------------------------------------------
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
static void displayForward(void)
{   
    struct node *ptr = head;
    printf("\n[ ");

    while(ptr != NULL)
    {
        printf("(%d,%d)", ptr->key, ptr->data);
        ptr = ptr->next;
    }
    printf(" ]");
}
// ------------------------------------------------------------------------------------------------
static void displayBackward(void)
{
    struct node *ptr = last;
    printf("\n[ ");

    while(ptr != NULL)
    {
        printf("(%d,%d)",ptr->key, ptr->data );
        ptr = ptr->prev;
    }
    printf(" ]");
}
// ------------------------------------------------------------------------------------------------
static void insertFirst(int key, int data)
{
    struct node *link = (struct node*) malloc(sizeof(struct node));
    link->key = key;
    link->data = data;

    if(isEmpty())
    {
        last = link;                // make it the last link
    }
    else
    {
        head->prev = link;          // update first prew link
    }
    link->next = head;              // point it to old first link
    head = link;                    // Point first to new first link
}
// ------------------------------------------------------------------------------------------------
static void insertLast(int key, int data)
{
    struct node *link = (struct node*) malloc(sizeof(struct node));
    link->key = key;
    link->data = data;

    if(isEmpty())
    {
        last = link;                // make it the last link
    }
    else
    {
        last->next = link;          // make link a new last link
        link->prev = last;          // mark old last node as prev of new link
    }
    last = link;                    // point last to new last node
}
// ------------------------------------------------------------------------------------------------
static struct node* deleteFirst(void)
{
    struct node *tempLink = head;       // Save reference to first link 
    if(head->next == NULL)              // If only one link (node)
    {
        last = NULL;
    }
    else
    {
        head->next->prev = NULL;
    }
    head = head->next;

    return tempLink;                    // Return the deleted link
}
// ------------------------------------------------------------------------------------------------
static struct node* deleteLast(void)
{
    struct node *tempLink = last;
    if(head->next == NULL)
    {
        head = NULL;
    }
    else
    {
        last->prev->next = NULL;
    }
    last = last->prev;
    return tempLink;
}
// ------------------------------------------------------------------------------------------------
static struct node* delete(int key)
{    
    struct node* current = head;                // Start from the first link
    struct node* previous = NULL;

    if(head == NULL)
    {
        return NULL;
    }
    while(current->key != key)                  // navigate through list
    {  
        if(current->next == NULL)               // If it is the last node
        {
            return NULL;
        }
        else
        {
            previous = current;                 // Store reference to current link
            current = current->next;            // Move to next link
        }
    }

    // Fount a match, update the link
    if(current == head)
    {
        head = head->next;                      // Change first to point next link
    }
    else
    {
        current->prev->next = current->next;    // Bypass the current link
    }

    if(current == last)
    {
        last = current->prev;                   // Change last to point to prev link
    }
    else
    {
        current->next->prev = current->prev;
    }

    return current;
}
// ------------------------------------------------------------------------------------------------
extern bool insertAfter(int key, int newKey, int data)
{
    struct node *current = head;        // STart from the first link
    if(head == NULL)
    {
        return false;
    }    
    while(current->key != key)
    {
        if(current->next == NULL)
        {
            return false;
        }
        else
        {
            current = current->next;
        }
    }
    // Create a link
    struct node *newLink = (struct node*) malloc(sizeof(struct node));
    newLink->key = newKey;
    newLink->data = data;

    if(current == last)
    {
        newLink -> next = NULL;
        last = newLink;
    }
    else
    {
        newLink->next = current->next;
        current->next->prev = newLink;
    }
    newLink->prev = current;
    current->next = newLink;

    return true;
}
// ------------------------------------------------------------------------------------------------
