MPICC?=mpicc

all: test

test: merge_sort.c merge_sort.h test.c
	${MPICC} -o test test.c merge_sort.c merge_sort.h 
	
clean:
	rm -f *.o *.out *.gch