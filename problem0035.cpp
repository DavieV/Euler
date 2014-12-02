/*
Find all of the circular primes below 1 million
*/

#include <iostream>
#include <cstring>
#include <cmath>

#define MAX 1000000

using namespace std;

string circulate(string);
int isValid(string, bool[]);
int handlemultiples(int, bool[]);
int nextPrime(int, bool[]);

int main(void){
	bool primes[MAX];
	memset(primes, true, sizeof(primes));
	primes[0] = false;
	primes[1] = false;

	int prime = 2;
	for(int i = 0; i < sqrt(MAX) + 1; i++){
		handlemultiples(prime, primes);
		prime = nextPrime(prime, primes);
	}

	int count = 0;
	for(int j = 0; j < MAX; j++){
		if(isValid(to_string(j), primes)) count++;
	}

	cout << count << endl;
}

string circulate(string num){
	string tmp = num;
	tmp[0] = num[num.length()-1];
	for(int i = 0; i < num.length() - 1; i++){
		tmp[i+1] = num[i];
	}
	return tmp;
}

int isValid(string num, bool primes[]){
	for(int i = 0; i < num.length(); i++){
		if(primes[stoi(num)] == false) return false;
		num = circulate(num);
	}
	return true;
}

int handlemultiples(int prime, bool primes[]){
	for(int i = prime * prime; i < MAX; i+=prime){
		primes[i] = false;
	}
}

int nextPrime(int prime, bool primes[]){
	while(primes[++prime] == false);
	return prime;
}