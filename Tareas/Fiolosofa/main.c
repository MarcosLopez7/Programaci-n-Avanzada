#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/wait.h>
#include "sem.h"

int sems;

void ciclo(int id) {
	srand(getpid());

	do {
            printf("F %d: pensando...\n", id);
	    sleep(rand()%5);

	    Wait(sems, id);
	    Wait(sems, (id+1)%5);

            printf("F %d: comiendo (palillos %d y %d).\n", id, id, (id+1)%5);
	    sleep(rand()%5);

	    Signal(sems, (id+1)%5);
	    Signal(sems, id);
	} while(1);
}

int main() {
        int i;
	sems = Getsem(5);

	for(i=0;i<5;i++) {
		Signal(sems, i);
	}

	for(i=0;i<5;i++) {
		if(!fork()) ciclo(i);
	}
	for(i=0;i<5;i++) {
		wait(0);
	}

	exit(0);
}
