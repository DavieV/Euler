/*
The number, 1406357289, is a 0 to 9 pandigital number because it is made up of each of the digits 0 to 9 in some order, but it also has a rather interesting sub-string divisibility property.

Let d1 be the 1st digit, d2 be the 2nd digit, and so on. In this way, we note the following:

d2d3d4=406 is divisible by 2
d3d4d5=063 is divisible by 3
d4d5d6=635 is divisible by 5
d5d6d7=357 is divisible by 7
d6d7d8=572 is divisible by 11
d7d8d9=728 is divisible by 13
d8d9d10=289 is divisible by 17
Find the sum of all 0 to 9 pandigital numbers with this property.
------------------------------------------------------------------------
In order to solve this particular problem I had to first make a number of smaller programs in order to build up useable data.
First I generated all the permutations of the string "0123456789" in order to find all of the 1 to 9 pandigital number. After
doing this I read in each permutation and checked if they met the requirements set by the problem at hand, if they did I saved them
into a text file.
*/

#include <iostream>

using namespace std;

bool isValid(string);
void permute(string, int, int);
void swap(char *, char *);

int main(void){
	long long tmp;
	long long sum = 0;
	cin >> sum;
	while(cin >> tmp)
		sum += tmp;

	cout << sum << endl;
}

bool isValid(string num){
	if(stoi(num.substr(1,3)) % 2 != 0) return false;
	if(stoi(num.substr(2,3)) % 3 != 0) return false;
	if(stoi(num.substr(3,3)) % 5 != 0) return false;
	if(stoi(num.substr(4,3)) % 7 != 0) return false;
	if(stoi(num.substr(5,3)) % 11 != 0) return false;
	if(stoi(num.substr(6,3)) % 13 != 0) return false;
	if(stoi(num.substr(7,3)) % 17 != 0) return false;

	return true;
}

void swap(char * a, char * b){
	char tmp = *a;
	*a = *b;
	*b = tmp;
}

void permute(string num, int start, int end){
	if(start == end){
		cout << num << endl;
		return;
	}

	for(int i = start; i <= end; i++){
		swap(num[start], num[i]);
		permute(num, start+1, end);
		swap(num[start], num[i]);
	}
	return;
}