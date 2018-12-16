#include <stdlib.h>
#include <stdio.h>
#include <math.h>

#define MAXLISTSIZE 1000000000
#define MIN(X, Y) (((X) < (Y)) ? (X) : (Y))

int main(int argc, char** argv){
//Calculate the nth prime number. n = newargv[1]
int isPrime;
int n = atoi(argv[1]);
int upperbound = MIN(n, MAXLISTSIZE);
int prime = 0;
int upto;
int i = 1; 
int j;
int nextprime;
int *primes = malloc(sizeof(int) * upperbound);
long nthprime;
//Define first prime number as 2
primes[prime++] = 2;
while (prime < upperbound){
	//Only check if odd numbers are prime
	i += 2;
	//Stop checking factors when they are more than sqrt(i)
	upto = (int) sqrt(i);
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
nthprime = (long) primes[upperbound - 1];
long iLong = (long) i;
n -= upperbound;
//Continue if we're out of list space but don't know the nth prime
//yet
while (n  > 0){
	iLong += 2; 
	upto = (int) sqrt(iLong);
	isPrime = 1;
	//Check the numbers on the list first
	for (j = 1; j < upperbound; j++){
		nextprime = primes[j];
		if (nextprime > upto) break;
		if (iLong % nextprime == 0){
			isPrime = 0;
			break;
		}
	}
	//If it still might be prime, keep checking odd numbers
	if (isPrime) for (j = primes[upperbound - 1] + 2; j <= upto; 
			  j += 2){
		if (iLong % j == 0){
			isPrime = 0;
			break;
		}	
	}
	//No space to save primes, so use n to keep track of which
	//prime we're on
	if (isPrime){
		nthprime = iLong;
		n--;
	}
}
//print the n'th prime
printf("%ld\n", nthprime);
free(primes);
}
