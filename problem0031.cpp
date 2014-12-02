#include <iostream>
#include <cstring>

#define D 8 //8 denominations

using namespace std;

void fillAmounts(int [], int [], int);

int main(void){

	int denoms [] = {1, 2, 5, 10, 20, 50, 100, 200};
	int amount;

	cin >> amount;

	int amounts [amount+1]; //array of previous solutions
	memset(amounts, 0, sizeof(amounts));
	amounts[0] = 1;

	fillAmounts(amounts, denoms, amount);

	cout << amounts[amount] << endl;
}

void fillAmounts(int amounts[], int denoms[], int len){

	for(int i = 0; i < D; i++){ //loop through all denominations
		for(int j = amounts[i]; j <= len; j++){
			if(j >= denoms[i]) amounts[j] += amounts[j - denoms[i]]; //check if the denomination can be subtracted
		}
	}
}