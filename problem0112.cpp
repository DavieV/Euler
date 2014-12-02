/*
Working from left-to-right if no digit is exceeded by the digit to its left it is called an increasing number; for example, 134468.

Similarly if no digit is exceeded by the digit to its right it is called a decreasing number; for example, 66420.

We shall call a positive integer that is neither increasing nor decreasing a "bouncy" number; for example, 155349.

Clearly there cannot be any bouncy numbers below one-hundred, but just over half of the numbers below one-thousand (525) are bouncy. 
In fact, the least number for which the proportion of bouncy numbers first reaches 50% is 538.

Surprisingly, bouncy numbers become more and more common and by the time we reach 21780 the proportion of bouncy numbers 
is equal to 90%.

Find the least number for which the proportion of bouncy numbers is exactly 99%.
*/

#include <iostream>
#include <iomanip>

using namespace std;

bool isBouncy(int);

int main(void){

	int total = 1000;
	int bouncyCount = 525;
	while(((double)bouncyCount / (double)total) != 0.99){
		total++;
		if(isBouncy(total)) bouncyCount++;
	}
	cout << bouncyCount << " " << total << endl;

}

bool isBouncy(int n){
	bool incr = true;
	bool decr = true;

	int dig1 = n % 10;
	int dig2;
	n /= 10;

	while(n > 0){
		dig2 = n % 10;
		if(dig2 < dig1)	decr = false;
		if(dig2 > dig1) incr = false;
		dig1 = dig2;
		n /= 10;
	}

	if(!incr && !decr) return true;
	return false;
}