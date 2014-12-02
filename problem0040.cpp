/*
An irrational decimal fraction is created by concatenating the positive integers:
0.123456789101112131415161718192021...
It can be seen that the 12th digit of the fractional part is 1.
If dn represents the nth digit of the fractional part, find the value of the following expression.
d1 × d10 × d100 × d1000 × d10000 × d100000 × d1000000
*/
#include <iostream>

int main(void){

	int pos = 0;
	int tmp;
	int prod = 1;
	int dn = 1;
	int cur;
	int digit;
	for(int i = 1; dn <= 1000000; i++){
		if(i >= 100000) pos+=6;
		else if(i >= 10000) pos+=5;
		else if(i >= 1000) pos+=4;
		else if(i >= 100) pos+=3;
		else if(i >= 10) pos+=2;
		else pos++;

		tmp = pos;
		cur = i;

		if(tmp >= dn){
			if(tmp == dn) digit = cur % 10;
			while(tmp >= dn){
				digit = cur % 10;
				cur /= 10;
				tmp--;
			}
			dn *= 10;
			prod *= digit;
		}
	}

	std::cout << prod << std::endl;
}