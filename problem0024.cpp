/*
A permutation is an ordered arrangement of objects. For example, 3124 is one possible permutation of the digits 
1, 2, 3 and 4. If all of the permutations are listed numerically or alphabetically, we call it lexicographic order.
The lexicographic permutations of 0, 1 and 2 are:

012   021   102   120   201   210

What is the millionth lexicographic permutation of the digits 0, 1, 2, 3, 4, 5, 6, 7, 8 and 9?
-----------------------------------------------------------------------------------------------------------------------
I solved this problem with a somewhat optimized brute force approach. Since I know that the permutations are going to
be sorted in numerical order, I figured out what starting digit would be have the 1 millionth lexicographic permutation
within its range. I realized that this starting digit would be 2 and it's range of permutations would be 725761-1088640.
I then generated the permutations of the remaining digits and saved them to a text file. After reading in these
permutations and sorting them using a vector, I looped through the vector, using an offset in order to find the
millionth lexicographic permutation.
*/

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void permute(string, int, int);
void swap(char *, char *);

int main(void){

	vector<string> permutations;

	string tmp;
	while(cin >> tmp)
		permutations.push_back(tmp);

	sort(permutations.begin(), permutations.end());

	int start = 725761; //offset, start of the range of permutations
	int count = 725761;

	while(count < 1000000){
		count++;
	}

	cout << 2 << permutations[count - start] << endl;

	//used these to pass permutations into a text file
	//string base = "013456789";
	//permute(base, 0, base.length() - 1);

}

void swap(char * a, char * b){
	char tmp = *a;
	*a = *b;
	*b = tmp;
}

void permute(string num, int start, int end){
	if(start == end){
		cout << num << endl;
		return;
	}

	for(int i = start; i <= end; i++){
		swap(num[start], num[i]);
		permute(num, start+1, end);
		swap(num[start], num[i]);
	}
	return;
}