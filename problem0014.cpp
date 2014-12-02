/*
* Find a starting term in a *Collatz Sequence* under 1million that provideds the longest sequence
*/

#include <iostream>

using namespace std;

int numTerms(int, long long, int, int[]);

int main(void){
	int max = 0;
	int current;
	int len[1000001];

	for(int nik = 0; nik < 1000001; nik++){
		len[nik] = 0;
	}

	int val;
	for(int i = 0; i < 1000000; i++){
		current = numTerms(i, i, 0, len);
		if(current > max){
			max = current;
			val = i;
		}
	}

	cout << val << endl;
}

int numTerms(int orig, long long num, int steps, int len[]){
	if(num == 1 || num == 0){ 
		len[orig] = steps;
		return steps;
	}
	if(num < 1000000 && len[num] != 0) return numTerms(orig,1,steps+len[num],len);
	if(num % 2 == 0) return numTerms(orig, num / 2, steps + 1, len);
	else return numTerms(orig, 3 * num + 1, steps + 1, len);
}