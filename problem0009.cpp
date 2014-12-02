/*
Find the pythagorean triple for which a + b + c = 1000 and return the product abc
*/

#include <iostream>

using namespace std;

bool isPythagTriple(int, int, int);

int main(void){
	int k;
	for(int i = 1; i < 1000; i++){
		for(int j = i+1; j < 1000 - i; j++){
			k = 1000 - i - j;
			if(isPythagTriple(i,j,k)) cout << i * j * k << endl;
		}
	}
}

bool isPythagTriple(int a, int b, int c){
	return a * a + b * b == c * c;
}