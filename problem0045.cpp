/*
Triangle, pentagonal, and hexagonal numbers are generated by the following formulae:

Triangle	 	Tn=n(n+1)/2	 	1, 3, 6, 10, 15, ...
Pentagonal	 	Pn=n(3n−1)/2	1, 5, 12, 22, 35, ...
Hexagonal	 	Hn=n(2n−1)	 	1, 6, 15, 28, 45, ...
It can be verified that T285 = P165 = H143 = 40755.

Find the next triangle number that is also pentagonal and hexagonal.
*/

#include <iostream>
#include <cmath>

using namespace std;

unsigned long long hexagonal(int);
bool isPentagonal(unsigned long long);

int main(void){

	int n = 144;
	while(!isPentagonal(hexagonal(n)))
		n++;

	cout << hexagonal(n) << endl;

}

unsigned long long hexagonal(int n){
	return n * (2 * n - 1);
}

bool isPentagonal(unsigned long long n){
	double tmp = ((1 + sqrt(24 * n + 1)) / 6.0);
	return floor(tmp) == ceil(tmp);
}