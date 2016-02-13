#include <stdio.h>
#include <stdlib.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <unistd.h>
#include <fcntl.h>

int suma(int *);

int main(int argc, const char * argv[])
{
	int fd;
    
    	fd = open("/tmp/myfifo", O_RDONLY);
    
    	int *nums = (int *) malloc(40 * sizeof(int));
    
    	read(fd, nums, 40 * sizeof(int));
	    
	printf("El resultado de la suma es: %d\n", suma(nums));

   	close(fd);
    
	free(nums);
    	return 0;
}

int suma(int *v){

        int res = 0;

        int *vP = v;

        while(*vP != 0){
                res += *vP;
                vP++;
        }

        return res;

}
