#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int numero = 100;
pthread_mutex_t mutex;

typedef struct params {
	int n;
} param;

void *duplica(void *);
void *divide(void *);

int main() {

	pthread_t thread1;
	pthread_t thread2;

	param p;

	p.n = 5;

	pthread_create(&thread1, NULL, duplica, &p);
	pthread_create(&thread2, NULL, divide, &p);

	pthread_join(thread1, NULL);
	pthread_join(thread2, NULL);

	return 0;
}

void *duplica(void *p) {
	
	int i;
		
	pthread_mutex_lock(&mutex);
	int temp = numero;
	pthread_mutex_unlock(&mutex);

	for(i = 0; i < ((param *) p)->n; i++) {
			temp *= 2;
			printf("duplicando %d\n", temp);
			sleep(5);
	}

	pthread_mutex_lock(&mutex);
	numero = temp;
	pthread_mutex_unlock(&mutex);

	pthread_exit(NULL);
}


void *divide(void *p) {
	
	int i;

	pthread_mutex_lock(&mutex);
	double temp = (double) numero;
	pthread_mutex_unlock(&mutex);

	for(i = 0; i < ((param *)p)->n; i++) {
		temp /= 2;
		printf("Divide %f\n", temp);
		sleep(5);
	}

	pthread_mutex_lock(&mutex);
	numero = (int) temp;	
	pthread_mutex_unlock(&mutex);

	pthread_exit(NULL);
}
