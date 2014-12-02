/*
Starting with 1 and spiralling anticlockwise in the following way, a square spiral with side length 7 is formed.

37 36 35 34 33 32 31
38 17 16 15 14 13 30
39 18  5  4  3 12 29
40 19  6  1  2 11 28
41 20  7  8  9 10 27
42 21 22 23 24 25 26
43 44 45 46 47 48 49

It is interesting to note that the odd squares lie along the bottom right diagonal, but what is more interesting is 
that 8 out of the 13 numbers lying along both diagonals are prime; that is, a ratio of 8/13 ≈ 62%.

If one complete new layer is wrapped around the spiral above, a square spiral with side length 9 will be formed. 
If this process is continued, what is the side length of the square spiral for which the ratio of primes along both 
diagonals first falls below 10%?
*/

#include <iostream>
#include <cstring>
#include <cmath>

#define MAX 8000000

using namespace std;

int nextPrime(int, bool[]);
void handleMultiples(int, bool[]);
bool isPrime(int);

int main(void){

	bool primes[MAX];
	memset(primes, true, sizeof(primes));
	primes[0] = false;
	primes[1] = false;

	int prime = 2;
	for(int i = 0; i < sqrt(MAX) + 1; i++){
		handleMultiples(prime, primes);
		prime = nextPrime(prime, primes);
	}

	int numPrimes = 0;
	int diagonals = 1;
	int sub = 2;
	int square;
	int val;
	int base = 1;

	do{
		base += 2;
		diagonals += 4;
		square = base * base;
		for(int j = 0; j < 4; j++){
			val = square - (sub * j);
			if(val < MAX){
				if(primes[val]) numPrimes++;
			}
			else{
				if(isPrime(val)) numPrimes++;
			}
		}
		sub += 2;
	}while(((double)numPrimes / (double)diagonals) > 0.1);

	cout << (double)numPrimes / (double)diagonals << endl;
	cout << numPrimes << " " << diagonals << endl;
	cout << base << endl;
}

int nextPrime(int prime, bool primes[]){
	prime++;
	while(!primes[prime]) prime++;
	return prime;
}

void handleMultiples(int prime, bool primes[]){
	for(int i = prime * prime; i < MAX; i+=prime){
		primes[i] = false;
	}
}

bool isPrime(int n){
	if((n & 1) != 1) return false;
	for(int i = 3; i < sqrt(n) + 1; i+=2)
		if(n % i == 0) return false;
	return true;
}