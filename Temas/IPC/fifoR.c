#include <stdio.h>
#include <stdlib.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <unistd.h>
#include <fcntl.h>

int main(int argc, const char * argv[])
{
	    int fd;
    	int leidos = 1;
    
    	fd = open("/tmp/myfifo", O_RDONLY);
    
    	int i = -1;
    
    	while (leidos = read(fd, &i, sizeof(int))) {
        	printf("%d\n", i);
    	}
    
   	 close(fd);
    
    	return 0;
}
