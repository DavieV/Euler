#include <iostream>
#include <cmath>

using namespace std;

bool isValid(int);

int main(void){
	int sum = 0;
	for(int i = 2; i < 1000000; i++){
		if(isValid(i)) sum += i;
	}
	cout << sum << endl;
}

bool isValid(int num){
	int tmp = num;
	int sum = 0;
	while(tmp > 0){
		sum += pow(tmp % 10, 5);
		tmp /= 10;
	}
	return sum == num;
}