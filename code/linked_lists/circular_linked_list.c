#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>

static bool isEmpty(void);
static int lenght(void);
static void insertFirst(int key, int data);
static struct node* deleteFirst(void);
static void printList(void);

struct node{
    int data;
    int key;

    struct node *next;
};
struct node *head = NULL;
struct node *current = NULL;

// ------------------------------------------------------------------------------------------------
void circular_linked_list_main_function(void)
{
    printf("CIRCULAR LINKED LIST\n\r");

    insertFirst(1, 11);
    insertFirst(2, 22);
    insertFirst(3, 33);
    insertFirst(4, 44);
    insertFirst(5, 55);
    
  
    printf("New linked list\n\r");
    printList();

    printf("Delete node from  linked list\n\r");
    for(int i = 0; i <= 3; i++)
    {
        printList();
        deleteFirst();
    }
    
    int lenght_list = lenght();
    printf("Lenght: %d \n\r", lenght_list);
    
    
    printf("\n\r");
}
// ------------------------------------------------------------------------------------------------
static bool isEmpty(void)
{
    return head == NULL;
}
// ------------------------------------------------------------------------------------------------
static int lenght(void)   /// <<<<<<<<<<<<<<<<<<<<<     Doesn't work 
{
    int lenght = 0;
    if(head == NULL)
    {
        return 0;
    }
    
    current = head->next;               //  Start from first node

    while(current != head)
    {
        lenght++;
        current = current->next;
    }

    return lenght;
}
// ------------------------------------------------------------------------------------------------
static void insertFirst(int key, int data)
{
    struct node *link = (struct nore*) malloc(sizeof(struct node));
    link->key = key;
    link->data = data;

    if(isEmpty())
    {
        head = link;
        head->next = head;
    }
    else
    {
        link->next = head;          // Point to the old first node
        head = link;                // point first to new first node  ????
    }
}
// ------------------------------------------------------------------------------------------------}
static struct node* deleteFirst(void)
{
    struct node* tempLink = head;

    if(head->next == head)
    {
        head = NULL;
        return tempLink;
    }

    head = head->next;              // Mark next to first link as first
    
    return tempLink;                // Return the deleted link
}
// ------------------------------------------------------------------------------------------------
static void printList(void)
{
    struct node *ptr = head;            
    printf("\n[ ");

    if(head != NULL)                    // Start from the begining
    {
        while(ptr->next != ptr)         // Print from first node to last node before head
        {
            printf("(%d,%d)", ptr->key, ptr->data);
            ptr = ptr->next;
        }
    }
    printf(" ]");
}
// ------------------------------------------------------------------------------------------------
