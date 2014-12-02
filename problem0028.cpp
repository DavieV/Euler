#include <iostream>

using namespace std;

int main(void){
	int sum = 1;
	int sub = 2;
	int square;
	for(int i = 3; i <= 1001; i += 2){
		square = i * i;
		sum += (square + (square - sub) + (square - 2 * sub) + (square - 3 * sub));
		sub+=2;
	}
	cout << sum << endl;
}