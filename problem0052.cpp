/*
It can be seen that the number, 125874, and its double, 251748, contain exactly the same digits, but in a different order.

Find the smallest positive integer, x, such that 2x, 3x, 4x, 5x, and 6x, contain the same digits.
*/

#include <iostream>
#include <cstring>

using namespace std;

bool sameDigits(int, int);

int main(void){
	int n = 1;

	while(!(sameDigits(n, n * 2) && sameDigits(n, n * 3) && sameDigits(n, n * 4) && sameDigits(n, n * 5) && sameDigits(n, n * 6)))
		n++;

	cout << n << endl;
}

bool sameDigits(int a, int b){
	int occur[10];
	memset(occur, 0, sizeof(occur));

	while(a > 0){
		occur[a % 10]++;
		a /= 10;
	}

	while(b > 0){
		occur[b % 10]--;
		b /= 10;
	}

	for(int i = 0; i < 10; i++){
		if(occur[i] != 0) return false;
	}
	return true;
}