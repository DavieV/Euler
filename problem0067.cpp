/*
By starting at the top of the triangle below and moving to adjacent numbers on the row below, the maximum 
total from top to bottom is 23.

3
7 4
2 4 6
8 5 9 3

That is, 3 + 7 + 4 + 9 = 23.

Find the maximum total from top to bottom in triangle.txt (right click and 'Save Link/Target As...'), 
a 15K text file containing a triangle with one-hundred rows.
*/

#include <iostream>

using namespace std;

int max(int, int);

int main(void){

	int triangle[100][100];

	for(int i = 0; i < 100; i++){
		for(int j = 0; j <= i; j++){
			cin >> triangle[i][j]; //fill the array with the numbers from the text file
		}
	}

	/*
	* Start from the second last row of the array, and add the maximum of the next two possible positions in the path.
	* Continue to build up from bottom to top in this way.
	*/
	for(int i = 98; i >= 0; i--){
		for(int j = 0; j <= i; j++){
			triangle[i][j] += max(triangle[i+1][j+1], triangle[i+1][j]);
		}
	}

	cout << triangle[0][0] << endl;
}

int max(int a, int b){
	return (a > b) ? a : b;
}