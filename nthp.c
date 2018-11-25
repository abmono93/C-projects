#include <stdlib.h>
#include <stdio.h>

#define MAXLISTSIZE 1000000
#define MIN(X, Y) (((X) < (Y)) ? (X) : (Y))

int main(int argc, char** argv){
int i = 1; 
int j;
int isPrime;
int n = atoi(argv[1]);
int prime = 0;
int nextprime;
int upto;
int upperbound = MIN(n, MAXLISTSIZE);
int primes[upperbound];
primes[prime++] = 2;
while (prime < upperbound){
	i += 2;
	upto = i/2;//printf("%d: upto = %d\n", i, upto);	
	isPrime = 1;
	for (j = 1; j < prime; j++){
		nextprime = primes[j];
		if (nextprime > upto) break;
		//printf("testing %d/%d\n", i, nextprime);
		if (i % nextprime == 0){
			isPrime = 0;
			break;
		}
	}
	if (isPrime) {
		primes[prime++] = i;
	}
}
n -= upperbound;
while (n  > 0){
	i += 2; 
	upto = i/2;
	isPrime = 1;
	for (j = 1; j < upperbound; j++){
		nextprime = primes[j];
		if (nextprime > upto) break;
		if (i % nextprime == 0){
			isPrime = 0;
			break;
		}
	}
	if (isPrime) for (j = primes[upperbound - 1] + 2; j <= upto; j += 2){
		if (i % j == 0){
			isPrime = 0;
			break;
		}	
	}
	if (isPrime){
		n--;
	}
}
printf("%d\n", i);
}
