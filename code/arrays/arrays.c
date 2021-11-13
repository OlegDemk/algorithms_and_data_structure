#include <stdio.h>
#include "arrays.h"

void insertion_one_element_on_array(void)
{
    int LA[10] = {1,2,3,4,5,6};
    int item = 10;                  // Insert this item 
    int k = 3;                      // Place where insert element
    int n = 5;
    int i = 0;
    int j = n;

    printf(">>>  Insertion  <<<\n\r");

    printf("Original array\n\r");
    for(i = 0; i <= n; i++)
    {
        printf("LA[%d] = %d \n", i, LA[i]);
    }

    n = n + 1;                          // new size of new array (becouse i vatr insert ine integer element)

    while(j >= k)                       // Поки 6 >= 3            
    {
        LA[j+1] = LA[j];                // Зсувати елементи до позиції елемента на місце якого потрібно робити вставку
        j = j - 1;                      // Декремент
    }

    LA[k] = item;                       // записати на вставку в массив

    printf("After\n\r");
    for(i = 0; i < n; i++)
    {
        printf("LA[%d] = %d \n", i, LA[i]);
    }
}
// ------------------------------------------------------------------------------------------------
void delete_one_element_on_array(void)
{
    int LA[] = {1,2,3,4,5,6};
    int k = 3;                                // Delete it elemento of array
    int n = (sizeof(LA)/sizeof(int)) - 1;       // Sizeo of array
    int i;
    int j;

    printf(">>>  Delete element  <<<\n\r");

    printf("Original array\n\r");
    for(int i = 0; i <= (sizeof(LA)/sizeof(int)) - 1; i++)
    {
        printf("LA[%d] = %d\n\r", i, LA[i]);
    }

    j = k;

    while(j < sizeof(LA)/sizeof(int))
    {
        LA[j-1] = LA[j];
        j++;
    }
    n = n - 1;

    printf("After\n\r");
    for(int i = 0; i <= n; i++)
    {
        printf("LA[%d] = %d\n\r", i, LA[i]);
    }
}
// ------------------------------------------------------------------------------------------------
void search_one_element_on_array(void)
{
    int LA[] = {1,2,3,4,5,6};
    int n = (sizeof(LA)/sizeof(int)) - 1;
    int j = 0;
    int item = 4;
    
    printf(">>>  Search element  <<<\n\r");

    printf("Original array\n\r");
    for(int i = 0; i <= (sizeof(LA)/sizeof(int)) - 1; i++)
    {
        printf("LA[%d] = %d\n\r", i, LA[i]);
    }

    while(j < (sizeof(LA)/sizeof(int)) - 1)
    {
        if(LA[j] == item)                       // Compare
        {
            break;
        }
        j++;
    }
    printf("Found element %d at position %d", item, j+1);

}
// ------------------------------------------------------------------------------------------------
void update_element_on_array(void)
{
    int LA[] = {1,2,3,4,5,6};
    int n = (sizeof(LA)/sizeof(int)) - 1;
    int j = 0;
    int item = 10;                           // Value for update
    int k = 3;                               // Update this array element

    printf(">>>  Update element  <<<\n\r");
    printf("Original array\n\r");
    for(int i = 0; i <= (sizeof(LA)/sizeof(int)) - 1; i++)
    {
        printf("LA[%d] = %d\n\r", i, LA[i]);
    }

    LA[k-1] = item;                         

    printf("After\n\r");
    for(int i = 0; i <= n; i++)
    {
        printf("LA[%d] = %d\n\r", i, LA[i]);
    }
}
// ------------------------------------------------------------------------------------------------