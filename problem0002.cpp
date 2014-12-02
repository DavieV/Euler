/*
* Calculate the sum of all even terms in the fibonacci sequence that do not exceed 4million
*/

#include <iostream>

using namespace std;

int main(void){
	int sum = 0;
	int tmp1 = 1;
	int tmp2 = 1;
	int tmp3;
	while(tmp1 + tmp2 < 4000000){
		if(tmp1 % 2 != 0 && tmp2 % 2 != 0) sum += (tmp1 + tmp2);
			tmp3 = tmp1;
			tmp1 = tmp1 + tmp2;
			tmp2 = tmp3;
	}
	cout << sum << endl;
}