/*
Find the sum of all numbers under 1million that are palindromes in both binary and decimal
*/

#include <iostream>
#include <cmath>

using namespace std;

bool isValid(int);
bool binPalindrome(int);

int main(void){
	int sum = 0;
	for(int i = 0; i < 1000000; i++){
		if(isValid(i)) sum += i;
	}
	cout << sum << endl;
}

bool isValid(int num){
	string numString = to_string(num);
	for(int i = 0; i < numString.length() / 2; i++){
		if(numString[i] != numString[numString.length() - i - 1]) return false;
	}
	return binPalindrome(num);
}

bool binPalindrome(int num){
	string bin;
	string flip;
	int max = log2(num);
	while(max >= 0){
		if(num - pow(2, max) >= 0){
			bin = "1" + bin;
			flip = flip + "1";
			num -= pow(2, max);
		}
		else{
			bin = "0" + bin;
			flip = flip + "0";
		}
		max--;
	}
	return bin == flip;
}