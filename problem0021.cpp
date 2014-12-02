/*
Find the sum of all amicable numbers under 10000
Let d(n) be defined as the sum of proper divisors of n (numbers less than n which divide evenly into n).
If d(a) = b and d(b) = a, where a ≠ b, then a and b are an amicable pair and each of a and b are called amicable numbers.
*/

#include <iostream>

using namespace std;

int sumDivisors(int);

int main(void){
	int sum = 0;
	int current;
	for(int i = 1; i < 10000; i++){
		current = sumDivisors(i);
		if(i == sumDivisors(current) && i != current) sum += i;
	}
	cout << sum << endl;
}

int sumDivisors(int num){
	int sum = 0;
	for(int i = 1; i < (num / 2) + 1; i++){
		if(num % i == 0) sum+= i;
	}
	return sum;
}