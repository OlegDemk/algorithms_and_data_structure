#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>

#define SIZE 20

static struct DataItem{
    int data;
    int key;
};

struct DataItem* hashArray[SIZE];
struct DataItem* dummyItem;
struct DataItem* item;


static int hashCode(int key);
static struct DataItem *search(int key);
static void insert(int key, int data);
static struct DataItem* delete(struct DataItem* item);
static void display(void);

// ------------------------------------------------------------------------------------------------
void hash_main_function(void)
{
    printf("HASH \n\r");

    dummyItem = (struct DataItem*) malloc(sizeof(struct DataItem));
    dummyItem -> data = -1;
    dummyItem -> key = -1;

    insert(1, 11);
    insert(3, 70);
    insert(4, 88);
    insert(7, 33);

    display();

    item = search(4);
    if(item != NULL)
    {
        printf("Item found: %d\n\r", item->data);
    }
    else
    {
        printf("Item didn't find\n\r");
    }

    delete(item);
    item = search(4);

    if(item != NULL)
    {
        printf("Element found: %d\n", item->data);
    }
    else
    {
        printf("Element not found\n");
    }

    display();

}
// ------------------------------------------------------------------------------------------------
static int hashCode(int key)                // Function calculate hash
{
    return key % SIZE;
}
// ------------------------------------------------------------------------------------------------
static struct DataItem *search(int key)
{
    int hashIndex = hashCode(key);          // Get the hash

    while(hashArray[hashIndex] != NULL)     // Move in array until an empty
    {
        if(hashArray[hashIndex] -> key == key)          // 
        {
            return hashArray[hashIndex];
        }
        ++hashIndex;                        // GO to next cell
        hashIndex %= SIZE;                  // Wrap arount the table
    }
    return NULL;
}
// ------------------------------------------------------------------------------------------------
static void insert(int key, int data)
{
    struct DataItem *item = (struct DataItem*) malloc(sizeof(struct DataItem));
    item -> data = data;
    item -> key = key;

    int hashIndex = hashCode(key);      // Get the hash

    // Move in array until an empty or deleted cell
    while(hashArray[hashIndex] != NULL && hashArray[hashIndex] -> key != -1)
    {
        ++hashIndex;                    // Go to next cell
        hashIndex %= SIZE;              // warp around the table 
    }
    hashArray[hashIndex] = item;
}
// ------------------------------------------------------------------------------------------------
static struct DataItem* delete(struct DataItem* item)
{
    int key = item -> key;                      // Read key
    int hashIndex = hashCode(key);              // Get the hash
 
    while(hashArray[hashIndex] != NULL)         // Mowe in array until an empty
    {
        if(hashArray[hashIndex] -> key == key)              // Find element with the same hash
        {
            struct DataItem* temp = hashArray[hashIndex];   // Assign a dummy item at deleted position
            hashArray[hashIndex] = dummyItem;
            return temp;
        }
        ++hashIndex;                            // Go to next cell
        hashIndex %= SIZE;                      // Warp around the table
    } 
}
// ------------------------------------------------------------------------------------------------
static void display(void)
{
    int  i = 0;
    
    for(i = 0; i < SIZE; i++)
    {
        if(hashArray[i] != NULL)
        {
            printf(" (%d, %d)", hashArray[i] -> key, hashArray[i] -> data);
        }
        else
        {
            printf(" ~~ ");
        }
    }
    printf("\n");
}
// ------------------------------------------------------------------------------------------------
