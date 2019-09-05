#include <stdio.h>
#include <stdlib.h>

#include "merge_sort.h"

int int_comp(const void *a, const void *b) {
    int a_ = *(int*) a;
    int b_ = *(int*) b;
    return a_ > b_;
}

void print_int_arr(int arr[], unsigned int length) {
    for (unsigned int i = 0; i<length; ++i)
        printf(" %d ->", arr[i]);
    printf(" |\n");
}

int main () {
    int arr[5] = {0,2,3,1,3};
    print_int_arr(arr, 5);
    merge_sort((void*) arr, 0, 5, int_comp);
    print_int_arr(arr, 5);
    return 0;
}