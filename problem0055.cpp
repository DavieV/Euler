/*
If we take 47, reverse and add, 47 + 74 = 121, which is palindromic.

Not all numbers produce palindromes so quickly. For example,

349 + 943 = 1292,
1292 + 2921 = 4213
4213 + 3124 = 7337

That is, 349 took three iterations to arrive at a palindrome.

Although no one has proved it yet, it is thought that some numbers, like 196, never produce a palindrome. A number that never forms a palindrome through the reverse and add process is called a Lychrel number. Due to the theoretical nature of these numbers, and for the purpose of this problem, we shall assume that a number is Lychrel until proven otherwise. In addition you are given that for every number below ten-thousand, it will either (i) become a palindrome in less than fifty iterations, or, (ii) no one, with all the computing power that exists, has managed so far to map it to a palindrome. In fact, 10677 is the first number to be shown to require over fifty iterations before producing a palindrome: 4668731596684224866951378664 (53 iterations, 28-digits).

Surprisingly, there are palindromic numbers that are themselves Lychrel numbers; the first example is 4994.

How many Lychrel numbers are there below ten-thousand?
*/

#include <iostream>

using namespace std;

string reverse(string);
bool isPalindrome(string);
string addRows(string, string);
string addZeroes(string, int);
bool isLychrel(string);

int main(void){

	int count = 0;
	for(int i = 0; i < 10000; i++){
		if(!isLychrel(to_string(i))) count++;
	}

	cout << count << endl;
}

bool isLychrel(string a){
	for(int i = 0; i < 55; i++){
		a = addRows(a, reverse(a));
		if(isPalindrome(a)) return true;
	}
	return false;
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

string reverse(string a){
	string tmp = "";
	for(int i = 0; i < a.length(); i++){
		tmp = a[i] + tmp;
	}
	return tmp;
}

bool isPalindrome(string a){
	return a == reverse(a);
}

