/*
Find the first term in the fibonacci sequence to contain 1000 digits
*/

#include <iostream>

using namespace std;

string addRows(string, string);
string addZeroes(string, int);

int main(void){
	string prev1 = "1";
	string prev2 = "1";
	int term = 2;
	string current = "";
	while(current.length() < 1000){
		current = addRows(prev1, prev2);
		prev2 = prev1;
		prev1 = current;
		term++;
	}
	cout << term << endl;
}

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