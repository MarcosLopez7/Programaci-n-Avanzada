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

        int n, res;

        read(fd, &n, sizeof(int));
	res = factoriza(n);

        close(fd);

	int error = mkfifo("/tmp/myfifo2", 0777);

        if (error) {
                printf("Error al crear el FIFO\n");
                exit(-1);
        }

        int fd2 = open("/tmp/myfifo2", O_WRONLY);

	write(fd2, &res, sizeof(int));	

	close(fd2);
	unlink("/tmp/myfifo2");

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
