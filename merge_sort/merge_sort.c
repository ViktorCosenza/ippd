#include <stdio.h>
#include <stdlib.h>

#include "merge_sort.h"

#define MIN_ARR_LEN 10

void bubble_sort(
        int [], 
        unsigned int);

void merge (
        int array[], 
        unsigned int start, 
        unsigned int middle, 
        unsigned int  end ) {
    
    unsigned int start_ = middle + 1;
    if (array[middle] <= array[start_]) return;

    while (start <= middle && start_ <= end) {
        if (array[start] <= array[start_]) ++start;
        else {
            int value = array[start_];
            unsigned int index = start_;

            while (index != start) {
                array[index] = array[index-1];
                --index;
            }           
            array[start] = value;
            ++start;
            ++middle;
            ++start_; 
        }
    }
}

void merge_sort(
        int array[], 
        unsigned int start,
        unsigned int end ) {
    unsigned int length = end - start;
    if (length < 1) {
        printf("Error: Length too small");
        return;
    }
    if (length < MIN_ARR_LEN) 
        return bubble_sort(array, length);

    unsigned int middle = start + (end - start) / 2;
    merge_sort(array, start, middle);
    merge_sort(array, middle + 1, end);
    merge(array, start, middle, end);
}


void swap(int *a, int *b) {
    int *temp = a;
    *a = *b;
    *b = *a;
}


void bubble_sort(
        int array[], 
        unsigned int length) {
    int swapped;
    for (int j=0; j<length; ++j) {
        swapped = 0;
        for (int i=0; i<length-1; ++i) {
            if (array[i] > array[i+1]) {
                swap(&array[i], &array[i+1]);
                swapped = 1;
            }
        }
        if (!swapped) break;
    }
}