void merge_sort (
        void **array, 
        unsigned int start,
        unsigned int end, 
        int (*comparator)(const void*, const void*));

void merge (
        void **array, 
        unsigned int start, 
        unsigned int middle, 
        unsigned int  end, 
        int (*comparator)(const void*, const void*));
        