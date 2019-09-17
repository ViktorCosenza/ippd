#include <stdio.h>
#include <stdlib.h>
#include <omp.h>

#include "merge_sort.h"
#include "../../utils/gen_random_ints.h"
#include "../../utils/cronometer.h"


int main () {
    int length = 5000;
    int *unsorted_arr = gen_random_ints(length, length);
    
    #pragma omp parallel
    {
        #pragma omp single
        merge_sort(unsorted_arr, 0, length);
    }

    if(assert_asc_order(unsorted_arr, length))
        printf("Success!\n");
    return 0;
}