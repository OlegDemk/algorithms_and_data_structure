#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>

static int MAXSIZE = 8;
static int stack[8];
static top = -1;            // Because first element on adday has 0 

static int isEmpty(void);
static int isFull(void);
static int peek(void);
static int pop(void);
static int push(int data);
static void print_stack(void);

// ------------------------------------------------------------------------------------------------
void stack_main_function(void)
{
    printf("STACK \n\r");

    if(isEmpty())
    {
        int i = 0;
        for(i = 0; i <= 5; i++)         // Add several elements on stack
        {
            push(i);
        }
        print_stack();                  // print all stack

        printf("pop operation\n\r");
        for(i = 0; i <= 3; i++)
        {
            int data = pop();
            printf("pop element: %d \n\r", data);
            print_stack();
        }
        printf("Final stack: ");
        print_stack();
        printf("\n\r");
    }
    
}
// ------------------------------------------------------------------------------------------------
static void print_stack(void)
{
    if(!isEmpty())                       // Stack has elements
    {
        for(int k =0; k <= MAXSIZE; k++)
        {
            printf("%d ", stack[k]);
        }
        printf("\n\r");
    }
}
// ------------------------------------------------------------------------------------------------
static int isEmpty(void)
{
    if(top == -1)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}
// ------------------------------------------------------------------------------------------------
static int isFull(void)
{
    if(top == MAXSIZE)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}
// ------------------------------------------------------------------------------------------------
static int peek(void)
{
    return stack[top];
}
// ------------------------------------------------------------------------------------------------
static int pop(void)
{
    int data;
    if(!isEmpty())
    {
        data = stack[top];
        top = top - 1;
        return data;
    }
    else
    {
        printf("Could nor retrieve data, Stack is empty. \n\r"); 
    }
}
// ------------------------------------------------------------------------------------------------
static int push(int data)
{
    if(!isFull())
    {
        top = top + 1;
        stack[top] = data;
    }
    else
    {
        printf("Could not insert data, Stack os full\n\r");
    }
}
// ------------------------------------------------------------------------------------------------