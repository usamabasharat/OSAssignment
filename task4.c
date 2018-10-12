#include <stdio.h>
#include <sys/wait.h>
#include <unistd.h>
#include <sys/types.h>
#include <stdlib.h>
int main()
{
	int arr[1000];
	int value = 1;
	int sum1, sum2, sum3, sum4, sum5, sum6, sum7, sum8, sum9, sum10 = 0;	
	int tSum = 0;
	int tSum1 = 0;
	int p1[2], p2[2],p3[2],p4[2],p5[2],p6[2],p7[2],p8[2],p9[2],p10[2];
	pipe(p1);
	pipe(p2);
	pipe(p3);
	pipe(p4);
	pipe(p5);
	pipe(p6);
	pipe(p7);
	pipe(p8);
	pipe(p9);
	pipe(p10);
	for(int i = 0; i < 1000; i++){
	arr[i] = value;
	value++;
	}
		
	int id1 = fork();
	if(id1 == 0){
		for(int i = 0; i < 100; i++){
			sum1 = sum1 + arr[i];
		}		
		write(p1[1], &sum1, sizeof(sum1));
        	close(p1[1]);
		exit(0);
	}
	else{
		int id2 = fork();
		if(id2 == 0){
			for(int i = 100; i < 200; i++){
				sum2 = sum2 + arr[i];
			}	
			write(p2[1], &sum2, sizeof(sum2));
        		close(p2[1]);
			exit(0);
			}
			else{
				int id3 = fork();
				if(id3 == 0){
				for(int i = 200; i < 300; i++){
					sum3 = sum3 + arr[i];
				}	
				write(p3[1], &sum3, sizeof(sum3));
        			close(p3[1]);
				exit(0);
				}
				else{
					int id4 = fork();
					if(id4 == 0){
					for(int i = 300; i < 400; i++){
						sum4 = sum4 + arr[i];
					}	

					write(p4[1], &sum4, sizeof(sum4));
        				close(p4[1]);
					exit(0);
					}
					else{
						int id5 = fork();
						if(id5 == 0){
						for(int i = 400; i < 500; i++){
							sum5 = sum5 + arr[i];
						}	
						write(p5[1], &sum5, sizeof(sum5));
        					close(p5[1]);
						exit(0);
						}
						else{
							int id6 = fork();
							if(id6 == 0){
							for(int i = 500; i < 600; i++){
							sum6 = sum6 + arr[i];
							}
							write(p6[1], &sum6, sizeof(sum6));
        						close(p6[1]);
							exit(0);
							}
							else{
								int id7 = fork();
								if(id7 == 0){
									for(int i = 600; i < 700; i++){
										sum7 = sum7 + arr[i];
									}	
									write(p7[1], &sum7, sizeof(sum7));
        								close(p7[1]);
									exit(0);
								}
								else{
									int id8 = fork();
									if(id8 == 0){
										for(int i = 700; i < 800; i++){
											sum8 = sum8 + arr[i];
										}	
										write(p8[1], &sum8, sizeof(sum8));
        									close(p8[1]);
										exit(0);
									}
									else{
										int id9 = fork();
										if(id9 == 0){
											for(int i = 800; i < 900; i++){
												sum9 = sum9 + arr[i];
											}	
											write(p9[1], &sum9, sizeof(sum9));
        										close(p9[1]);
											exit(0);
										}
										else{
											int id10 = fork();
											if(id10 == 0){
												for(int i = 900; i < 1000; i++){
													sum10 = sum10 + arr[i];
												}	
												write(p10[1], &sum10, sizeof(sum10));
        											close(p10[1]);
												exit(0);
											}
											else{
												wait(NULL);
	        										wait(NULL);
	        										wait(NULL);
	        										wait(NULL);
	        										wait(NULL);
	        										wait(NULL);
	        										wait(NULL);
	        										wait(NULL);
	        										wait(NULL);
	        										wait(NULL);
	      
	  											read(p1[0], &tSum, sizeof(tSum));
	        										tSum1 = tSum1 + tSum;
        											close(p1[0]);
												tSum = 0;
        											read(p2[0], &tSum, sizeof(tSum));
	        										tSum1 = tSum1 + tSum;
        											close(p2[0]);
												tSum = 0;
        											read(p3[0], &tSum, sizeof(tSum));
	        										tSum1 = tSum1 + tSum;
        											close(p3[0]);
												tSum = 0;
        											read(p4[0], &tSum, sizeof(tSum));
	        										tSum1 = tSum1 + tSum;
       												close(p4[0]);
												tSum = 0;
        											read(p5[0], &tSum, sizeof(tSum));
	        										tSum1 = tSum1 + tSum;
        											close(p5[0]);
												tSum = 0;
        											read(p6[0], &tSum, sizeof(tSum));
	        										tSum1 = tSum1 + tSum;
        											close(p6[0]);
												tSum = 0;
        											read(p7[0], &tSum, sizeof(tSum));
	        										tSum1 = tSum1 + tSum;
       												close(p7[0]);
												tSum = 0;
        											read(p8[0], &tSum, sizeof(tSum));
	        										tSum1 = tSum1 + tSum;
        											close(p8[0]);
												tSum = 0;
        											read(p9[0], &tSum, sizeof(tSum));
	        										tSum1 = tSum1 + tSum;
        											close(p9[0]);
												tSum = 0;
        											read(p10[0], &tSum, sizeof(tSum));
	        										tSum1 = tSum1 + tSum;
        											close(p10[0]);
        
        											printf("Sum: %d", tSum1);


											}
	
										}	
									}
								}
							}
						}
					}
				}
			}
		}	
		return 0;	
	}
