/*
Find out the total number of letters used if all of the numbers from 1 to 1000 were written out in words
*/

#include <iostream>

using namespace std;

int numLetters(int);

int main(void){
	int total = 0;
	for(int i = 1; i <= 1000; i++){
		total += numLetters(i);
	}
	cout << total << endl;

	cout << numLetters(900) << endl;
}

int numLetters(int n){
	string ones[10] = {"", "one", "two", "three", "four", "five", "six", "seven", "eight", "nine"};
	string teens[10] = {"eleven", "twelve", "thirteen", "fourteen", "fifteen", "sixteen", "seventeen", "eighteen", "nineteen"};
	string tens[10] = {"ten", "twenty", "thirty", "forty", "fifty", "sixty", "seventy", "eighty", "ninety"};
	string thousand = "thousand";
	string hundred = "hundred";

	int size = 0;
	if(n == 1000) return 3 + thousand.length();
	if(n == 100) return 3 + hundred.length();
	if(n > 100){
		if(n % 100 != 0) size += 3;
		size += ones[n / 100].length() + hundred.length();
		n %= 100;
	}
	if(n < 10) size += ones[n].length();
	else if(n == 10) size += tens[0].length();
	else if(n > 10 && n < 20) size += teens[n-11].length();
	else size += tens[n / 10 - 1].length() + ones[n % 10].length();

	return size;
}