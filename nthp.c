#include <stdlib.h>
#include <stdio.h>
#include <math.h>

#define MAXLISTSIZE 1500000
#define MIN(X, Y) (((X) < (Y)) ? (X) : (Y))

int main(int argc, char** argv){
//Calculate the nth prime number. n = newargv[1]
int i = 1; 
int j;
int isPrime;
int n = atoi(argv[1]);
int prime = 0;
int nextprime;
int upto;
int upperbound = MIN(n, MAXLISTSIZE);
int primes[upperbound];
int *nthprime = &primes[upperbound - 1];
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
n -= upperbound;
//Continue if we're out of list space but don't know the nth prime
//yet
while (n  > 0){
	i += 2; 
	upto = (int) sqrt(i);
	isPrime = 1;
	//Check the numbers on the list first
	for (j = 1; j < upperbound; j++){
		nextprime = primes[j];
		if (nextprime > upto) break;
		if (i % nextprime == 0){
			isPrime = 0;
			break;
		}
	}
	//If it still might be prime, keep checking odd numbers
	if (isPrime) for (j = primes[upperbound - 1] + 2; j <= upto; 
			  j += 2){
		if (i % j == 0){
			isPrime = 0;
			break;
		}	
	}
	//No space to save primes, so use n to keep track of which
	//prime we're on
	if (isPrime){
		*nthprime = i;
		n--;
	}
}
//print the n'th prime
printf("%d\n", *nthprime);
}
