/*
Find the total amount of non-distinct values of nCr that are over 1million for 1 <= n <= 100
*/

#include <iostream>

bool isOver(int, int, int);

int main(void){
	int total = 0;
	for(int n = 1; n <= 100; n++){
		for(int r = 1; r <= n; r++){
			if(isOver(r + 1, n, n - r)) total++;
		}
	}
	std::cout << total << std::endl;
}

bool isOver(int start, int end, int divisor){
	double prod = 1;
	for(int i = 0; i < end - start + 1; i++){
		prod *= (double)(start + i) / (double)(i + 1);
		if(prod > 1000000) return true;
	}
	
	return false;
}