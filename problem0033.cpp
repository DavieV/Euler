/*
The fraction 49/98 is a curious fraction, as an inexperienced mathematician in attempting to simplify it may incorrectly believe that 49/98 = 4/8, which is correct, is obtained by cancelling the 9s.

We shall consider fractions like, 30/50 = 3/5, to be trivial examples.

There are exactly four non-trivial examples of this type of fraction, less than one in value, and containing two digits in the numerator and denominator.

If the product of these four fractions is given in its lowest common terms, find the value of the denominator.
*/

#include <iostream>

int shareDigit(int, int);
int removeDigit(int, int);

int main(void){
	int tmp;
	int numerator = 1;
	int denominator = 1;
	for(int i = 10; i < 100; i++){
		for(int j = i; j < 100; j++){
			tmp = shareDigit(i, j);
			if(tmp != -1 && tmp != 0 && ((double)removeDigit(i, tmp) / (double)removeDigit(j, tmp)) == (double)i / (double)j && i != j){
				numerator *= i;
				denominator *= j;
			}
		}
	}
	std::cout << denominator / numerator << std::endl;
}

int shareDigit(int a, int b){
	if(a/10 == b/10) return a/10;
	if(a/10 == b%10) return a/10;
	if(a%10 == b/10) return a%10;
	if(a%10 == b%10) return a%10;
	return -1;
}

int removeDigit(int a, int dig){
	if(dig == a%10) return a/10;
	if(dig == a/10) return a%10;
	return -1;
}