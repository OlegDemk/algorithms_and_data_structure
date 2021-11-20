#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>

static int find_element(int k);
static void print_all_array(void);

#define MAX 20
static int intArray[MAX] = {1,2,3,4,6,7,9,11,12,14,15,16,17,19,33,34,43,45,55,66};
static int total_comparisons = 0;

// ------------------------------------------------------------------------------------------------
void linear_search_main_function(int data)
{
    printf("LINEAR SEARCH \n\r");

    print_all_array();

    int found = find_element(data);      
    if(found != -1)
    {
        printf("Data was found, index: %d\n\r", found);
    }
    else
    {
        printf("Data wasn't found !\n\r");
    }
    printf("Total comparisons: %d\n\r", total_comparisons);
}
// ------------------------------------------------------------------------------------------------
static int find_element(int k)
{
    for(int i = 0; i < MAX; i++)
    {
        total_comparisons++;
        if(intArray[i] == k)
        {
            return i;   // Return index
        }
    }
    return -1;           // No found
}
// ------------------------------------------------------------------------------------------------
static void print_all_array(void)
{
    for(int i = 0; i < MAX; i++)
    {
        printf("[%d]=%d ", i, intArray[i]);
    }
    printf("\n\r");
}
// ------------------------------------------------------------------------------------------------
