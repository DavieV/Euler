#include <iostream>
#include <cstring>
#include <cmath>
#include <cstring>

#define MAX 10000

using namespace std;

bool isPermutation(int, int);
void handleMultiples(int, bool[]);
int nextPrime(int, bool[]);

int main(void){
	bool primes[MAX];

	memset(primes, true, sizeof(primes));
	primes[0] = false;
	primes[1] = false;

	int prime = 2;
	for(int i = 2; i < sqrt(MAX) + 1; i++){
		handleMultiples(prime, primes);
		prime = nextPrime(prime, primes);
	}

	int limit = 9999 - 6660;
	for(int i = 0; i < limit; i++){
		if(primes[i] && primes[i+3330] && primes[i+6660] && isPermutation(i, i + 3330) && isPermutation(i, i + 6660))
			cout << i << i + 3330 << i + 6660 << endl;
	}

}

void handleMultiples(int prime, bool primes[]){
	for(int i = prime * prime; i < MAX; i+=prime){
		primes[i] = false;
	}
}

int nextPrime(int prime, bool primes[]){
	prime++;
	while(!primes[prime]){
		prime++;
	}

	return prime;
}

bool isPermutation(int a, int b){
	int occur[10];

	memset(occur, 0, sizeof(occur));

	while(a > 0){
		occur[a%10]++;
		a /= 10;
	}

	while(b > 0){
		occur[b%10]--;
		b /= 10;
	}

	for(int i = 0; i < 10; i++){
		if(occur[i] != 0) return false;
	}

	return true;
}