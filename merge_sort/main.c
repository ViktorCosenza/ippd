#include <stdio.h>
#include <stdlib.h>

#include "merge_sort.h"


int main () {
    int arr[] = {5, 7, 6, 1, 2, 3};
    merge_sort(arr, 0, 5);
    print_int_arr(arr, 0, 5);
    return 0;
}