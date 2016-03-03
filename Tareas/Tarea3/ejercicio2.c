#include <stdio.h>
#include <stdlib.h>
#include <signal.h>
#include <unistd.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <errno.h>

#define DIRECTORY "Datos"
#define N 5

void comprobar();
void mkdirs();

int main(){

	struct sigaction handler; 

	handler.sa_handler = SIGALRM;
	handler.sa_flags = SA_ONESHOT;

	sigaction(SIGALRM, &handler, 0);	

	return 0;
}

void comprobar(){
	
	DIR *directory;
	directory = opendir(DIRECTORY);	

	if(directory) {
		erase();
		closedir();
	} else if(ENOENT == errno) {
		mkdir(DIRECTORY, 0755);
	} else {
		printf("Error al abrir directorio");	
	}

}

void mkdirs(){

	int i;

	for(i = 0; i < N ; ++i){
		mkdir
	}	
}
