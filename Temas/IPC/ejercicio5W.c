#include <stdio.h>
#include <stdlib.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <unistd.h>
#include <fcntl.h>

int main(int argc, const char * argv[])
{
    
 	int error = mkfifo("/tmp/myfifo", 0777);
    
    	if (error) {
        	printf("Error al crear el FIFO\n");
        	exit(-1);
    	}
    
    	int fd = open("/tmp/myfifo", O_WRONLY);
    
    	int *numeros = (int *) malloc(40 * sizeof(int));
	int *n = numeros;    
	int temp;

	printf("Inserta numeros, inserta 0 para dejar de sumer numeros\n");

    	do {
		scanf("%d", &temp);
		*n = temp;		
		n++;
    	} while (temp != 0);

	write(fd, numeros, 40 * sizeof(int));
    
    	close(fd);
    	unlink("/tmp/myfifo");
	    
	free(numeros);
    	return 0;
}

