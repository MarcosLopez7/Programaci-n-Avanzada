#include <stdio.h>
#include <stdlib.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <string.h>

#define TCP_PORT 8000

int maximo(int *);
int minimo(int *);
int promedio(int *);

/* reverse:  reverse string s in place */
void reverse(char s[])
{
    int i, j;
    char c;
    
    for (i = 0, j = strlen(s)-1; i<j; i++, j--) {
        c = s[i];
        s[i] = s[j];
        s[j] = c;
    }
}

void itoa(int n, char s[])
{
    int i, sign;
    
    if ((sign = n) < 0)  /* record sign */
        n = -n;          /* make n positive */
    i = 0;
    do {       /* generate digits in reverse order */
        s[i++] = n % 10 + '0';   /* get next digit */
    } while ((n /= 10) > 0);     /* delete it */
    if (sign < 0)
        s[i++] = '-';
    s[i] = '\0';
    reverse(s);
}



int main(int argc, const char * argv[]) {
    
    struct sockaddr_in direccion;
    char buffer[1000];
    
    int servidor, cliente;
    
    int leidos, escritos;
    
    if (argc != 2) {
        printf("Error. Use: %s A.B.C.D \n", argv[0]);
        exit(-1);
    }
    
    //Crear el socket
    servidor = socket(PF_INET, SOCK_STREAM, 0);
    
    // Enlace con el socket
    direccion.sin_port = htons(TCP_PORT);
    direccion.sin_family = AF_INET;
    inet_aton(argv[1], &direccion.sin_addr);
    
    bind(servidor, (struct sockaddr *) &direccion, sizeof(direccion));
    
    // Escuchar a los clientes
    listen(servidor, 10);
    
    // Comunicación
    socklen_t tamano = sizeof(direccion);
    
    cliente = accept(servidor, (struct sockaddr *) &direccion, &tamano);
    
    int prom, max, min;
    
    if (cliente >= 0) {
        printf("Aceptando conexiones en %s:%d \n",
               inet_ntoa(direccion.sin_addr),
               ntohs(direccion.sin_port));
        
	int *t = (int *) malloc(1000 * sizeof(int));

        // Leer de socket y escribir en pantalla
        while (leidos = read(cliente, t, sizeof(buffer))) {
            write(fileno(stdout), t, leidos);
            
            	max = maximo(t);
		min = minimo(t);
		prom = promedio(t);            

            	printf("El maximo es %d, el minimo %d y el promedio %d\n", max, min, prom);
            
		buffer[0] = 'y';

            //itoa(fact, buffer);
            
           leidos = write(fileno(stdin), &buffer, sizeof(buffer));
            write(cliente, &buffer, sizeof(int));
        }

	free(t);
    }
    
    // Cerrar el socket
    
    close(servidor);
    close(cliente);
    
    return 0;
}

int maximo (int *n){

	int max = 0;
	int i;

 	int *nP = n;

	for(i = 0; (i < 1000) && *nP != 0; ++i){
		if(*nP > max){
			max = *nP;
		}
		nP++;
	} 
  
 
    	return max;
}

int minimo(int *n){

	int min = 1000;
        int i;

        int *nP = n;

        for(i = 0; (i < 1000) && *nP != 0; ++i){
                if(*nP < min){
                        min = *nP;
                }
                nP++;
        }


        return min;

}

int promedio(int *n){

	int res = 0;
	int i;
	
	int *nP = n;

	for(i = 0; (i < 1000) && *nP != 0; ++i){
                res += *nP;
		nP++;
        }

	return (res / 2);
}
