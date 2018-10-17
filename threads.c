#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <sys/wait.h>

#define chunkSize 100
int arr[1000];

void *Sum(void *arg){
	int start = (int)arg;
	int end = start + chunkSize;
	int sum = 0;	

	for (int i = start; i < end; i++){
		sum = sum + arr[i];
	}
	return ((void*)sum);
}
int main(){
	int value = 1;
	int tSum = 0;
	pthread_t thr[10];
	int status[10] = {0};
	
	for(int i = 0; i < 1000; i++){
		arr[i] = value;
		value++;
	}
	
	for(int i = 0; i < 10; i++){
		pthread_create(&thr[i], NULL, Sum, (void*)(i*chunkSize));	
	}

	for(int i = 0; i < 10; i++){
		pthread_join(thr[i],(void**) &status[i]);	
	}
		
	for(int i = 0; i < 10; i++){
		tSum  = tSum + status[i];
	}		
	
	printf("Sum of 1000 numbers: %d\n", tSum);
}
