/*
Find the sum of all numbers that are equal to the sum of their digits
*/

#include <iostream>

using namespace std;

int fact(int);
int factDigits(int);

int main(void){
	int sum = 0;
	for(int i = 10; i < 50000; i++){
		if(factDigits(i) == i) sum += i;
	}
	cout << sum << endl;
}

int fact(int num){
	int fact = 1;
	for(int i = 2; i <= num; i++){
		fact *= i;
	}
	return fact;
}

int factDigits(int num){
	int sum = 0;
	while(num > 0){
		sum += fact(num%10);
		num/=10;
	}
	return sum;
}