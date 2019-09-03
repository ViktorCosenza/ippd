EXECS=ping_pong ring
MPICC?=mpicc

all: ${EXECS}

ping_pong: ping_pong.c
	${MPICC} -o ping_pong ping_pong.c cronometer.c cronometer.h

ring: ring.c
	${MPICC} -o ring ring.c cronometer.c cronometer.h

clean:
	rm -f ${EXECS} *.o *.out *.gch