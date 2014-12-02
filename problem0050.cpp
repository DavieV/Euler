#include <iostream>
#include <cstring>
#include <cmath>
#include <vector>

#define MAX 1000000

using namespace std;

int nextPrime(int, bool[]);
void handleMultiples(int, bool[]);
int numTerms(int, vector<int>);

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

	vector<int> consec;
	for(int i = 0; i < MAX; i++){
		if(primes[i]) consec.push_back(i);
	}

	int max;
	int terms = 0;
	int tmp;
	for(int i = 0; i < 100; i++){
		tmp = numTerms(i, consec);
		if(tmp != -1){
			if(tmp > terms){
				terms = tmp;
				max = i;
			}
		}
	}
	cout << max << endl;
}

int numTerms(int num, vector<int>consec){
	int sum = 0;
	int pos = 0;
	while(sum < num && pos < consec.size()){
		sum += consec[pos];
	}
	if(sum == num) return pos + 1;
}

int nextPrime(int prime, bool primes[]){
	while(primes[++prime] != true) prime++;
	return prime;  
}

void handleMultiples(int prime, bool primes[]){
	for(int i = prime * prime; i < MAX; i+=prime)
		primes[i] = false;
}