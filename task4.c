#include <stdio.h>
#include <unistd.h>
#inlcude <sys/wait.h>
#include <stdlib.h>
int main()
{
	int arr[1000];
	int value = 1;
	int sum1, sum2, sum3, sum4, sum5, sum6, sum7, sum8, sum9, sum10 = 0;	
	int tSum = 0;
	int status1, status2, status3, status4, status5, status6, status7, status8, status9, status10;
	for(int i = 0; i < 1000; i++){
	arr[i] = value;
	value++;
	}
		
	int id1 = fork();
	if(id1 == 0){
		for(int i = 0; i < 100; i++){
			sum1 = sum1 + arr[i];
		}	
		tSum = tSum + sum1;
		exit(0);
	}
	else{
		wait(&status1);
		int id2 = fork();
		if(id2 == 0){
		for(int i = 100; i < 200; i++){
			sum2 = sum2 + arr[i];
		}	
		tSum = tSum + sum2;
			exit(0);
		}
		else{
			wait(&status2);
			int id3 = fork();
			if(id3 == 0){
			for(int i = 200; i < 300; i++){
				sum3 = sum3 + arr[i];
			}	
			tSum = tSum + sum3;
				exit(0);
		}
			else{
				wait(&status3);
				int id4 = fork();
				if(id4 == 0){
				for(int i = 300; i < 400; i++){
				sum4 = sum4 + arr[i];
				}	
					tSum = tSum + sum4;
					exit(0);				
				}
				else{
					wait(&status4);
					int id5 = fork();
					if(id5 == 0){
					for(int i = 400; i < 500; i++){
					sum5 = sum5 + arr[i];
					}	
					tSum = tSum + sum5;

					exit(0);
					}
					else{	
						wait(&status5);
						int id6 = fork();
						if(id6 == 0){
						for(int i = 500; i < 600; i++){
						sum6 = sum6 + arr[i];
						}	
						tSum = tSum + sum6;
						exit(0);
						}
						else{
							wait(&status6);
							int id7 = fork();
							if(id7 == 0){
							for(int i = 600; i < 700; i++){
								sum7 = sum7 + arr[i];
							}	
							tSum = tSum + sum7;
							exit(0);
							}
							else{
								wait(&status7);
								int id8 = fork();
								if(id8 == 0){
								for(int i = 700; i < 800; i++){
								sum8 = sum8 + arr[i];
								}	
								tSum = tSum + sum8;
								exit(0);
								}
								else{	
									wait(&status8);
									int id9 = fork();
									if(id9 == 0){
									for(int i = 800; i < 900; i++){
										sum9 = sum9 + arr[i];
									}	
										tSum = tSum + sum9;
										exit(0);
									}
									else{
										wait(&status9);
										int id10 = fork();
										if(id10 == 0){
										for(int i = 900; i < 1000; i++){
										sum10 = sum10 + arr[i];
										
										}	
										tSum = tSum + sum10;
										exit(0);									
									}
									else{
										wait(&status10);
										printf("Sum: %d", tSum);
									}
	return 0;
}
