/*
A number chain is created by continuously adding the square of the digits in a number to form a new number until 
it has been seen before.

For example,

44 → 32 → 13 → 10 → 1 → 1
85 → 89 → 145 → 42 → 20 → 4 → 16 → 37 → 58 → 89

Therefore any chain that arrives at 1 or 89 will become stuck in an endless loop. What is most amazing is that EVERY 
starting number will eventually arrive at 1 or 89.

How many starting numbers below ten million will arrive at 89?
*/

#include <iostream>
#include <map>

#define MAX 10000000

using namespace std;

map<int, bool> fillMap(map<int, bool>);
int sumDigitSquares(int);

int main(void){
	map<int, bool> chains;

	chains = fillMap(chains);

	int count = 0;
	int num;
	for(int i = 1; i < MAX; i++){
		num = sumDigitSquares(i);
		if(chains[num]) count++;
	}

	cout << count << endl;
}

map<int, bool> fillMap(map<int, bool> chains){
	int num;
	for(int i = 1; i <= 648; i++){ //648 is the highest sum of squares of digits that can be achieved for #s under 10 million
		num = i;
		while(num != 1 && num != 89)
			num = sumDigitSquares(num);

		if(num == 1) chains[i] = false;
		if(num == 89) chains[i] = true;
	}
	return chains;
}

int sumDigitSquares(int num){
	int ans = 0;
	int tmp;
	while(num > 0){
		tmp = num % 10;
		ans += tmp * tmp;
		num /= 10;
	}
	return ans;
}