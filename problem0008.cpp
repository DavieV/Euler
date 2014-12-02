/*
* Find 13 adjacent digits in a 1000 digit string that have the largest product
*/

#include <iostream>
#include <cstdlib>

using namespace std;

long long findProd(string);

int main(void){
	string nums;
	cin >> nums;
	long long product = findProd(nums);
	cout << product << endl;
}

/*
Loops through the 1000 character long string, with a variable keeping the track of the maximum product which has been encountered.
In order to speed the process up, any sequence containing 0 is immediately skipped once any zero has been found.
*/
long long findProd(string nums){
	long long max = 1;
	long long current = 1;
	int numTerms = 0;
	int digit;
	for(int i = 0; i < nums.length() - 13; i++){
		digit = nums[i] - '0';
		if(digit != 0){
			if(numTerms == 13){
				current /= nums[i - 13] - '0'; /* divide out the oldest digit in the sequence */
				current *= digit; /* multiply in the newest digit */
			}
			else{
				current *= digit;
				numTerms++;
			}
		}
		else{
			numTerms = 0;
			current = 1;
		}
		if(current > max) max = current;
	}
	return max;
}
