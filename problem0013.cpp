/*
* Output the first 4 digits of the sum of 100 50-digit numbers
*/

#include <iostream>

using namespace std;

string addRows(string, string);
string addZeroes(string, int);

int main(void){
	string nums[100];
	string tmp;
	for(int i = 0; i < 100; i++){
		cin >> tmp;
		tmp[tmp.length() - 1] = '\0';
		nums[i] = tmp;
	}

	string sum = addRows(nums[0], nums[1]);
	for(int j = 2; j < 100; j++){
		sum = addRows(sum, nums[j]);
	}
	cout << sum << endl;
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