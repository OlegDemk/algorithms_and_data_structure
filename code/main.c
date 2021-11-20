
#include "main.h"

int main()
{
    printf("------------- START -------------\n\r");

    // ARRAYS
    // insertion_one_element_on_array();
    // delete_one_element_on_array();
    // search_one_element_on_array();
    // update_element_on_array();

    // LINKED LISTs
    // linked_lists_main_functions();   
    // doubly_linked_list_main_function();
    // circular_linked_list_main_function();

    // stack_main_function();
    // expression_parsing_main_function();         // Nothing
    // qeue_main_function();

    // SEARCH
    // Every functions print index found element, and how meny
    // iterations was made.
    int target_data = 45;       
    linear_search_main_function(target_data);
    binary_search_main_function(target_data);
    interpolation_search_main_function(target_data);



 


    // main_test_file();
    printf("\n\r------------- DONE -------------\n\r");


    

    return 0;
}
