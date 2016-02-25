#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>
#include <signal.h>

int main(int argc, const char * argv[]) {

   	pid_t pid;
   	int estado;
    
    	pid = fork();
    
    	
	void (*ret_signal)();

	if(pid < -1){

	}
	else if (pid == 0)
    	{
                ret_signal = signal(SIGINT, SIG_IGN );
		ret_signal = signal(SIGTSTP, SIG_IGN);       
 
		sleep(2);
	
		printf("Estamos en el proceso hijo con PID = %d y su padre es PPID = %d \n", \
               	getpid(), getppid());
		
		int i;

		for(i = 10; i > 0; --i){
			printf("Contando %d segundos \n", i);
			sleep(1);
		}

        	exit(0);
    	}
    	else {
	        
		ret_signal = signal(SIGTSTP, SIG_IGN);

		printf("Estamos en el proceso padre con PID = %d y su padre es PPID = %d \n", \
               	getpid(), getppid());
       
		printf("Si me matas, vas a ver bobalicon\n");

		int i; 

		for(i = 10; i > 0; --i){
			printf("Contando %d segundos \n", i);
			sleep(1);
		}

        	if (waitpid(pid, &estado, 0) != -1)
        	{
            		if (WIFEXITED(estado))
                		printf("Ya terminó el hijo con PID %d con valor de retorno %d \n", pid, WEXITSTATUS(estado));
        	}	
        
        	printf("Después del wait\n");
        
    	}
    
    	return 0;
}

