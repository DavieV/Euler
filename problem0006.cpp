/*
* Calculate the difference between the sum of the squares of the first 100 natural numbers, and the square of the sum of the 
* first 100 natural numbers.
*/

#include <iostream>
#include <cmath>

using namespace std;

int main(void){
	int sum1 = 0;
	int sum2 = (100 * 101 / 2) * (100 * 101 / 2);
	for(int i = 1; i <= 100; i++){
		sum1 += (i * i);
	}
	cout << sum2 - sum1 << endl;
}