/*
Find the total amount of triangle words based on the text file 'words.txt' provided by project euler.
A word is considered a triangle word if the sum of the value of its individual characters add up to a triangle number. 
*/
#include <iostream>
#include <cstring>

using namespace std;

int main(void){
	string n;
	bool triangles[10000];

	memset(triangles, false, sizeof(triangles));

	for(int i = 0; i < 141; i++){
		triangles[(i*(i+1))/2] = true;
	}

	int count = 0;
	int score = 0;

	while(cin >> n){
		for(int i = 0; i < n.length(); i++){
			score += n[i] - 'A' + 1;
		}
		if(triangles[score]) count++;
		score = 0;
	}
	
	cout << count << endl;
}