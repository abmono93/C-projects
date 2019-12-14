#include <stdlib.h>
#include <stdio.h>
#include <math.h>

#define MAXLISTSIZE 100000000
#define MIN(X, Y) (((X) < (Y)) ? (X) : (Y))

int main(int argc, char** argv){
//Calculate the nth prime number. n = newargv[1]
int isPrime;
int n = atoi(argv[1]);
int upperbound = MIN(n, MAXLISTSIZE);
int prime = 0;
int upto;
unsigned int i = 1; 
int j;
int nextprime;
int keepgoing;
int *primes = malloc(sizeof(int) * upperbound);
unsigned int nthprime;
//Define first prime number as 2
primes[prime++] = 2;
while (prime < upperbound){
	//Only check if odd numbers are prime
	i += 2;
	//Stop checking factors when they are more than sqrt(i)
	upto = sqrt(i);
	isPrime = 1;
	//Loop through the list of prime numbers (skip first one
	//since none are even)
	for (j = 1; j < prime; j++){
		nextprime = primes[j];
		if (nextprime > upto) break;
		if (i % nextprime == 0){
			isPrime = 0;
			break;
		}
	}
	//If none of the previous primes are factors, add this to
	//the list of primes
	if (isPrime) {
		primes[prime++] = i;
	}
}
nthprime = (unsigned int) i;
while (prime < n){
	i += 2;
	upto = sqrt(i);
	isPrime = 1;
	for (j = 1; j < prime; j++){
		nextprime = primes[j];
		if (nextprime > upto) break;
		if (i % nextprime == 0){
			isPrime = 0;
			break;
		}
	}
	if (isPrime) {
		nthprime = i;
		prime++;
	}	
}
printf("%u\n", nthprime);
free(primes);
}
