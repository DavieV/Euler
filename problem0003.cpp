#include <iostream>
#include <cmath>

using namespace std;

long long largestPFactor(long long);

int main(void){
	long long n;
	cin >>  n;
	cout << largestPFactor(n) << endl;
}

long long largestPFactor(long long n){
	long long current = n;
	long long max = 0;
	for(int i = 2; i < sqrt(n) + 1; i++){
		if(current % i == 0){
			if(i > max) max = i;
			while(current % i == 0){
				current /= i;
			}
		}
	}
	return max;
}