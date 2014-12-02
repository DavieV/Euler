/*
Find the sum of the route through a triangle
*/

#include <iostream>

using namespace std;

int maxSum(int [][15], int, int, int);
int max(int, int);

int main(void){
	int triangle[15][15];
	for(int i = 0; i < 15; i++){
		for(int j = 0; j < i + 1; j++){
			cin >> triangle[i][j];
		}
	}

	cout << maxSum(triangle, 0, 0, 0) << endl;
}

int maxSum(int triangle[][15], int sum, int i, int j){
	sum += triangle[i][j];
	if(i == 14) return sum;
	else{
		if(j > 0 && j < 14) return max(maxSum(triangle, sum, i+1, j+1), maxSum(triangle, sum, i+1, j));
		else if(j > 0) return maxSum(triangle, sum, i+1, j);
		else return maxSum(triangle, sum, i+1, j+1);
	}
}

int max(int x, int y){
	if(x > y) return x;
	else return y;
}