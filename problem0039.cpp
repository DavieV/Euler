#include <iostream>

using namespace std;

bool isPythagTriple(int, int, int);

int main(void){

	int k;
	int p = 1;

	int max = 0;
	int current = 0;
	int maxPerim;
	for(int p = 1; p < 1000; p++){
		for(int i = 1; i < p; i++){
			for(int j = i; j < p - i; j++){
				k = p - j - i;
				if(isPythagTriple(i, j, k)) current++;
			}
		}
		if(current > max){
			max = current;
			maxPerim = p;
		}
		current = 0;
	}

	cout << maxPerim << endl;
}

bool isPythagTriple(int a, int b, int c){
	return (a * a) + (b * b) == (c * c);
}