
#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

#include "test.h"

// Define structure
struct time{
    int seconds;
    int minutes;
    int hours;
};

struct time data_1;                     // Create data_1 object
struct time data_2;                     // Create data_2 object
struct time *data_2_p = &data_2;        // Create pointer on data_2 object


void test_structure(void);
void receive_struct_function(struct time);
void receive_struct_like_pointer(struct time *t);
struct data_struct_p* function_return_struct(void);


// ------------------------------------------------------------------------------------------------
void main_test_file(void)
{
    printf(">>>  TEST FUNCTION  <<<\n\r");

    test_structure();
    
}
// ------------------------------------------------------------------------------------------------
void test_structure(void)
{
    // 1. Cshnge field of struct usind direct method
    data_1.seconds = 10;
    printf("data_1.seconds = %d \n\r", data_1.seconds);

    // 2. Fill in field using pointer on structure data_2_p
    data_2_p->seconds = 59;
    printf("Pointer data_2_p.seconds = %d \n\r", data_2_p->seconds);

    // 3. Receive structure into function (makes local copy) (передача структури по значенню)
    struct time data_3;
    data_3.seconds = 33;
    printf("Receiving struct data_3.seconds before function = %d\n\r", data_3.seconds);
    receive_struct_function(data_3);
    printf("Receiving struct data_3.seconds after function = %d\n\r", data_3.seconds);

    // 4. Receive POINTER structure into function
    printf("Pointer. Before functions. data_2_p.seconds = %d \n\r", data_2_p->seconds);
    receive_struct_like_pointer(&data_2);
    printf("Pointer. Before functions. data_2_p.seconds = %d \n\r", data_2_p->seconds);

    // 5. RETURN pointer structure from function 
    struct time *data_struct_p;
    data_struct_p = &data_1;
    data_struct_p->seconds = 11;
    printf("Before function: data_struct_p->seconds = %d\n\r", data_struct_p->seconds);
    data_struct_p = function_return_struct();
    printf("After function: data_struct_p->seconds = %d\n\r", data_struct_p->seconds); 
}
// ------------------------------------------------------------------------------------------------
void receive_struct_function(struct time t)
{
    t.seconds = 22;
    printf("Receiving struct data_3.seconds = %d\n\r", t.seconds);
}
// ------------------------------------------------------------------------------------------------
void receive_struct_like_pointer(struct time *t)
{
    t->seconds = 50;
    printf("Pointer. Inside functions. data_2_p.seconds = %d \n\r", data_2_p->seconds);

}
// ------------------------------------------------------------------------------------------------
struct data_struct_p* function_return_struct(void)
{
    struct time *t = &data_1; 
    t->seconds = 99;
    printf("Pointer. Inside functions. t.seconds = %d \n\r", t->seconds);

    return t;
}
// ------------------------------------------------------------------------------------------------

