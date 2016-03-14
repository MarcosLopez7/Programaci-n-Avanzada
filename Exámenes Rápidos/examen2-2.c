#include <stdio.h>
#include <stdlib.h>
#include <signal.h>
#include <unistd.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <errno.h>
#include <string.h>
#include <dirent.h>

#define DIRECTORY "datos"
#define N 5

int grabar;

void comprobar();
void borrar();
void handler_record(int);

int main(){

	struct sigaction handler; 
	
	sigset_t mascara, pendiente;
	sigfillset(&mascara);
	sigdelset(&mascara, SIGALRM);
	sigprocmask(SIG_SETMASK, &mascara, NULL);

	signal(SIGALRM, SIG_DFL);
	
	alarm(2);

	handler.sa_handler = handler_record;
	handler.sa_flags = SA_RESTART;

	sigaction(SIGALRM, &handler, 0);	

	comprobar();

	int i;
	char d[8];
	FILE *file;

	for(i = 0; i < N; ++i){
		sprintf(d, "datos/a%d", i);
		grabar = 1;
		int signal;
	
		file = fopen(d, "w+");

		printf("grabando en %s\n", d);

		memset(d, 0, sizeof(d));

		alarm(3);

		while(grabar)
			fputc('x', file);
	
		sigpending(&pendiente);
      	for(signal = 1; signal < NSIG; ++signal) {
          	if(sigismember(&pendiente, signal)) {
              	fprintf(file, "La señal %d, fue bloqueada\n", signal);
          	}
      	}
	
		fclose(file);	
	}

	execlp("ls", "ls", "-hl", DIRECTORY, NULL);

	return 0;
}

void comprobar(){
	
	DIR *directory;
	directory = opendir(DIRECTORY);	

	if(directory) {
		printf("Borrando ficheros en %s\n", DIRECTORY);
		borrar();
	} else if(ENOENT == errno) {
		printf("Creando el directorio %s\n", DIRECTORY);
		mkdir(DIRECTORY, 0755);
	} else {
		printf("Error al abrir directorio");	
	}

}

void handler_record(int senial){
	grabar = 0;
}

void borrar(){

	struct dirent *d;
 	DIR *directory;
  	char str[255];
  	directory = opendir(DIRECTORY);
  
  	while(d = readdir(directory)){
    	if(d->d_type == DT_REG){
      		sprintf(str, "%s/%s", DIRECTORY, d->d_name);
      		unlink(str);
      		remove(str);
    	}
  	}
}
