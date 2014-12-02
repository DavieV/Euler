/*
* Find the sum of all prime numbers under 2 million
*/

#include <iostream>
#include <cmath>

using namespace std;

#define MAX 2000000

bool isPrime(int);

int main(void){
	long long sum = 0;

	for(int i = 1; i < MAX; i++){
		if(isPrime(i)) sum += i;
	}
	cout << sum << endl;
}

bool isPrime(int n){
	if(n == 1) return false;
	//if(n % 2 == 0) return false;
	//for(int i = 3; i < sqrt(n) + 1; i+=2){
	for(int i = 2; i < n; i++){
		if(n % i == 0) return false;
	}
	return true;
}