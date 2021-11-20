#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>

static void print_array(void);
static int find(int data);

#define MAX 20

static int intArray[MAX] = {1,2,3,4,6,7,9,11,12,14,15,16,17,19,33,34,43,45,55,66};

// ------------------------------------------------------------------------------------------------
void binary_search_main_function(int data)
{
    printf("BINARY SEARCH \n\r");
    print_array();

    int found = find(data);           // Find element with data 45
    if(found != -1)
    { 
        printf("Data was found, index: %d\n\r", found);
    }
    else
    {
        printf("Data wasn't found !\n\r");
    }
}
// ------------------------------------------------------------------------------------------------
static void print_array(void)
{
    for(int i = 0; i < MAX; i++)
    {
        printf("[%d]=%d ", i, intArray[i]);
    }
    printf("\n\r");
}
// ------------------------------------------------------------------------------------------------
static int find(int data)
{
    int lowerBound = 0;
    int upperBound = MAX - 1;
    int midPoint = -1;
    int comparisons = 0;
    int index = -1;

    while(lowerBound <= upperBound)
    {
        comparisons++;

        // Debug information
        // printf("LowerBound: %d, intArray[%d] = %d\n\r", lowerBound, lowerBound, intArray[lowerBound]);
        // printf("upperBound: %d, intArray[%d] = %d\n\r", upperBound, upperBound, intArray[upperBound]);

        midPoint = lowerBound + (upperBound - lowerBound) / 2;

        if(intArray[midPoint] == data)      // If data was found
        {
            printf("Total comparisons: %d\n\r", comparisons);
            return midPoint;
        }
        else
        {
            if(intArray[midPoint] < data)
            {
                lowerBound = midPoint + 1;
            }
            else
            {
                upperBound = midPoint - 1;
            }
        }
    }
    printf("Total comparisons: %d\n\r", comparisons);
    return index;
}
// ------------------------------------------------------------------------------------------------
