/*
Return the sum of the digits of 2^1000
*/

#include <iostream>

using namespace std;

string addRows(string, string);
string addZeroes(string, int);

int main(void){
	string start = "2";
	int power = 999;
	for(int i = 0; i < power; i++){ /* Calculates the integer value of 2 with the exponent of power + 1*/
		start = addRows(start, start);
	}

	int sum = 0;
	for(int j = 0; j < start.length(); j++){
		sum += start[j] - '0';
	}
	cout << sum << endl;
}

/*
* This function is capable of calculating the sum of very large integers by storing them in strings and then
* calculating the sum using long addition
*/
string addRows(string a, string b){
	string sum;
	int carry = 0;
	int digit;
	char tmp;
	if(a.length() < b.length()) a = addZeroes(a, b.length() - a.length());
	if(b.length() < a.length()) b = addZeroes(b, a.length() - b.length());

	for(int i = a.length() - 1; i >= 0; i--){
		digit = ((a[i] - '0') + (b[i] - '0') + carry) % 10;
		carry = ((a[i] - '0') + (b[i] - '0') + carry) / 10;
		tmp = digit + '0';
		sum = tmp + sum;
	}
	if(carry != 0){
		tmp = carry + '0';
		sum = tmp + sum;
	}
	return sum;
}

string addZeroes(string num, int amount){
	for(int i = 0; i < amount; i++){
		num = '0' + num;
	}
	return num;
}