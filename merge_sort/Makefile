EXECS=merge_sort
MPICC?=mpicc

all: ${EXECS}

merge_sort: merge_sort.c
	${MPICC} -c merge_sort.c ../cronometer.c ../cronometer.h

test: merge_sort test.c
	${MPICC} -o test test.c merge_sort.o cronometer.o
clean:
	rm -f ${EXECS} *.o *.out *.gch