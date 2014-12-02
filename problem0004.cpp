/*
* Finds the largest palindrome made by the product of two three-digit numbers
*/
#include <iostream>

using namespace std;

bool isPalindrome(string n);

int main(void){
	int max = 0;
	int prod;
	for(int i = 100; i < 1000; i++){
		for(int j = 100; j < 1000; j++){
			prod = i * j;
			if(isPalindrome(to_string(prod)) && prod > max) max = prod;
		}
	}
	cout << max << endl;
}

bool isPalindrome(string n){
	for(int i = 0; i < n.length() / 2; i++){
		if(n[i] != n[n.length() - i - 1]) return false;
	}
	return true;
}