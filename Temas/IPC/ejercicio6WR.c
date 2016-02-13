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
   
	int numero;

        printf("Dame un numero a factorizar\n");
        scanf("%d", &numero);

        write(fd, &numero, sizeof(int)); 
    
    	close(fd);
    	unlink("/tmp/myfifo");
    
	int fd2, res;

        fd2 = open("/tmp/myfifo2", O_RDONLY);

	read(fd2, &res, sizeof(int));

	printf("El resultado es: %d\n", res);

	close(fd2);

    	return 0;
}

