#include <stdio.h>
#include <stdlib.h>

#include "merge_sort.h"
#include "../utils/gen_random_ints.h"
#include "../utils/cronometer.h"

int main () {
    const unsigned int length = 50;
    int *arr = gen_random_ints(length, 100);
    merge_sort(arr, 0, length - 1);


    if (assert_asc_order(arr, length))
        printf("Success: The Array is Sorted!\n");
    else 
        printf("FAILURE: The Array is NOT Sorted!\n");
    return 0;
}