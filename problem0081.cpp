/*
Find the minimum path from the top left to the bottom right of an 80x80 matrix. Only moving right or down.
*/
#include <iostream>

#define MAX 80

using namespace std;

int main(void){
	int nums[MAX][MAX];
	int paths[MAX][MAX];

	for(int i = 0; i < MAX; i++){
		for(int j = 0; j < MAX; j++){
			cin >> nums[i][j];
		}
	}

	paths[MAX-1][MAX-1] = nums[MAX-1][MAX-1]; //set the min path at the bottom right equal to itself


	/*
	* Loop through the bottom and left edges and set value of the min path equal to the value at its current
	* position plus the min path at the previous position
	*/
	for(int i = 78; i >= 0; i--){
		paths[i][MAX-1] = nums[i][MAX-1] + paths[i+1][MAX-1];
		paths[MAX-1][i] = nums[MAX-1][i] + paths[MAX-1][i+1];
	}

	/*
	* Fill in the rest of the min path array, the min path from the current position is value at the current
	* position plus the min between the path going right and the path going left
	*/
	for(int i = 78; i >= 0; i--){
		for(int j = 78; j >= 0; j--){
			paths[i][j] = nums[i][j] + min(paths[i+1][j], paths[i][j+1]);
		}
	}

	cout << paths[0][0] << endl;
}

int min(int a, int b){
	return (a < b) ? a : b;
}