#include <stdio.h>
#include <stdlib.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <unistd.h>
#include <fcntl.h>

int factoriza(int);

int main(int argc, const char * argv[])
{
	int fd;
    	int leidos = 1;
    
    	fd = open("/tmp/myfifo", O_RDONLY);
    
    	int n;
    
    	read(fd, &n, sizeof(int));
    
	printf("El resultado es: %d\n", factoriza(n));

   	close(fd);
    
    	return 0;
}

int factoriza(int n){

        int res = 1;
        int i;

        for(i = 1; i <= n; ++i){
                res *= i;
        }

        return res;
}
