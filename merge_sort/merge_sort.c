#include <stdio.h>
#include <stdlib.h>

#include "merge_sort.h"

#define MIN_ARR_LEN 4

void bubble_sort(
        void **, 
        unsigned int, 
        int (*)(const void *, const void *));

void merge (
        void **array, 
        unsigned int start, 
        unsigned int middle, 
        unsigned int  end, 
        int (*comparator)(const void*, const void*)) {
    
    unsigned int start_ = middle + 1;
    if (array[middle] <= array[start_]) return;

    while (start <= middle && start_ <=end) {
        if (array[start] <= array[start_]) ++start;
        else {
            void *value = array[start_];
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
        void **array, 
        unsigned int start,
        unsigned int end, 
        int (*comparator)(const void*, const void*)) {
    unsigned int length = end - start;
    if (length < 1) {
        printf("Error: Length too small");
        return;
    }
    if (length < MIN_ARR_LEN) 
        return bubble_sort(array, length, comparator);

    unsigned int middle = start + (end - start) / 2;
    merge_sort(array, start, middle, comparator);
    merge_sort(array, middle + 1, end, comparator);
    merge(array, start, middle, end, comparator);
}

void swap(void **a, void **b) {
    void **temp = (void**) malloc(sizeof a);
    *temp = *a;
    *a = *b;
    *b = *temp;
}

void bubble_sort(
        void **array, 
        unsigned int length, 
        int (*comparator)(const void *, const void *)) {
    int swapped;
    for (int j=0; j<length; ++j) {
        swapped = 0;
        for (int i=0; i<length-1; ++i) {
            if (comparator(&array[i], &array[i+1])) {
                swap(&array[i], &array[i+1]);
                swapped = 1;
            }
        }
        if (!swapped) break;
    }
}