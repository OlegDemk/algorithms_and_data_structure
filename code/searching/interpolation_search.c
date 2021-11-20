#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>

static int find(int data);
static void print_array(void);

#define MAX 20
static int list[MAX] = {1,2,3,4,6,7,9,11,12,14,15,16,17,19,33,34,43,45,55,66};

// ------------------------------------------------------------------------------------------------
void interpolation_search_main_function(int data)
{
    printf("INTERPOLATION SEARCH \n\r");
    print_array();
    int found = find(data);
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
static int find(int data)
{
    int lo = 0; 
    int hi = MAX - 1;
    int mid = -1;
    int comparisons = 1;
    int index = -1;

    while(lo <= hi)
    {
        // Debug information
        // printf("\n Comparison: %d\n\r", comparisons);
        // printf("lo: %d, list[%d] = %d\n\r ", lo, lo, list[lo]);
        // printf("hi: %d, list[%d] = %d\n\r", hi, hi, list[hi]);

        comparisons++;

        // probe the mid point
        mid = lo + (((double)(hi - lo)/(list[hi] - list[lo])) * (data - list[lo]));
        // printf("mind = %d\n\r", mid);

        if(list[mid] == data)       // Data found
        {
            index = mid;
            break;
        }
        else
        {
            if(list[mid] < data)
            {
                lo = mid + 1;       // If data is larger, data is in upper half
            }
            else
            {
                hi = mid - 1;       // If data is smaller, data is in lowwer half
            }
        }
    }
    printf("Total comparetions made: %d \n\r", --comparisons);
    return index;
}
// ------------------------------------------------------------------------------------------------
static void print_array(void)
{
    for(int i = 0; i < MAX; i++)
    {
        printf("[%d]=%d ", i, list[i]);
    }
    printf("\n\r");
}
// ------------------------------------------------------------------------------------------------


