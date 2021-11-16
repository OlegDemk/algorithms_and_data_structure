
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>
//#include "queue/queue.h"

static int remoteData(void);
static void insert(int data);
static int size(void);
static bool isFull(void);
static bool isEmpty(void);
static int peek(void);

#define MAX 6

static int intArray[MAX];
static int front = 0;      
static int rear = -1;
static int itemCount = 0;

// ------------------------------------------------------------------------------------------------
void qeue_main_function(void)
{
    printf("QEUE \n\r");

    // 1. Fill in queue
    int i = 0;
    for(i = 0; i < MAX; i++)
    {
        insert(i);
    }

    // 2. Print queue
    for(i = 0; i <= MAX; i++)
    {
        printf("index:%d, data:%d ", i, intArray[i]);
    }
    printf("\n\r");

    // 3. Remove some elements from queue
    for(i = 0; i< 2; i++)
    {
        if(!isEmpty())
        {
            int data = remoteData();
            printf("remove: %d\n\r", data);
        }
        else
        {
            break;
        }
    }
  
    // 4. Print queue
    for(i = 0; i <= MAX; i++)
    {
        printf("index:%d, data:%d ", i, intArray[i]);
    }
    printf("\n\r");

}
// ------------------------------------------------------------------------------------------------
static int peek(void)
{
    return intArray[front];
}
// ------------------------------------------------------------------------------------------------
static bool isEmpty(void)
{
    return itemCount == 0;
}
// ------------------------------------------------------------------------------------------------
static bool isFull(void)
{
    return itemCount == MAX;
}
// ------------------------------------------------------------------------------------------------
static int size(void)
{
    return itemCount;
}
// ------------------------------------------------------------------------------------------------
static void insert(int data)
{
    if(!isFull())
    {
        if(rear == MAX-1)
        {
            rear = -1;
        }
        intArray[++rear] = data;
        itemCount++;
    }
}
// ------------------------------------------------------------------------------------------------
static int remoteData(void)
{
    int data = intArray[front++];
    if(front == MAX)
    {
        front = 0;
    }
    itemCount--;
    return data;
}
// ------------------------------------------------------------------------------------------------