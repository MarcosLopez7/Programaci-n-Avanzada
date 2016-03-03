#include <signal.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>
#define TIME 10

int bucle = 1;
int ctrlC = 0;
int ctrlZ = 0;
int x = 3;
pid_t hijo;

void gestor_asesino(int);
void gestor_alarma_h(int);
void gestor_ctrlc(int);
void gestor_ctrlz(int);
void gestor_alarma_p(int);

int main(){

	struct sigaction gestion;

    int estado;
  
    hijo = fork();
  
    /* De aquí en adelante lo ejecutan los dos procesos */
    if (hijo == -1)
    {
        printf("Error al crear el proceso hijo \n");
    }
    else if (hijo == 0)
    {

		gestion.sa_handler = SIG_IGN;
    	gestion.sa_flags = SA_RESTART;
    	sigaction(SIGINT, &gestion, 0);
    
    	gestion.sa_handler = SIG_IGN;
    	gestion.sa_flags = SA_RESTART;
    	sigaction(SIGTSTP, &gestion, 0);
	
		printf("Estamos en el proceso hijo con PID = %d y su padre es PPID = %d \n", \
                    getpid(), getppid());
	
		sleep(TIME); 
				
        printf("QUE TARDE ES!! LE VOY MENTAR LA MADRE A MI PAPA POR NO DESPERTARME\n");
        kill(getppid(), SIGUSR1);
	}
    else {
        gestion.sa_handler = gestor_ctrlc;
        gestion.sa_flags = SA_RESTART;
  
        sigaction(SIGINT, &gestion, 0);

		gestion.sa_handler = gestor_ctrlz;
    	gestion.sa_flags = SA_RESTART;
    
        sigaction (SIGTSTP, &gestion, 0);

		printf("Estamos en el proceso padre con PID = %d y su padre es PPID = %d \n", \
                  getpid(), getppid());

		printf("Mi hijo se va dormir, asi que soy todo tuyo\n");

		gestion.sa_handler = gestor_alarma_p;
		gestion.sa_flags = SA_RESTART;
		 
		sigaction(SIGALRM, &gestion, 0);
		
		printf("Aparezco cada %d segundos\n", x);
		alarm(x);

		gestion.sa_handler = gestor_asesino;
		gestion.sa_flags = SA_ONESHOT;

		sigaction(SIGUSR1, &gestion, 0);
		
    	while(bucle);
		wait(NULL);
	}

	return 0;
}

void gestor_alarma_h(int senial) {   
    printf("QUE TARDE ES!! LE VOY MENTAR LA MADRE A MI PAPA POR NO DESPERTARME\n");
	kill(getppid(), SIGUSR1);
}

void gestor_ctrlc(int senial) {
	ctrlC++;
	x++;
	
	printf("aumentaste a %d segundos\n", x);
	alarm(x);		
}

void gestor_ctrlz(int senial) {
    ctrlZ++;
	if(x > 1){
		x--;
		printf("disminuiste a %d segundos\n", x);
	}
		
	alarm(x);
}

void gestor_alarma_p(int senial){
	printf("Aparezco cada %d segundos\n", x);
	alarm(x);
}

void gestor_asesino(int senial){
	bucle = 0;
	printf("Se ha pulsado %d veces CTRL+C y se ha pulsado %d veces CTRL+Z. Acabando...\n", ctrlC, ctrlZ);
	kill(hijo, SIGKILL);
	raise(SIGKILL);	
}
