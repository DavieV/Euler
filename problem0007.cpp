/*
* Find the 10001 prime number
*/

#include <iostream>
#include <cmath>

using namespace std;

bool isPrime(int n);

int main(void){
	int num = 1;
	int term = 1;

	while(term < 10001){
		num+=2;
		if(isPrime(num)){
			term++;
		}
	}
	cout << term << ", " << num << endl;
}

bool isPrime(int n){
	if(n % 2 == 0) return false;
	for(int i = 3; i < sqrt(n) + 1; i+=2){
		if(n % i == 0) return false;
	}
	return true;
}