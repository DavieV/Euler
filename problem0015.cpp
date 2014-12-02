#include <iostream>

using namespace std;

int main(void){
	long long paths[21][21]; //array of edges

	for(int i = 0; i < 21; i++){
		paths[20][i] = 1;
		paths[i][20] = 1;
	}

	for(int i = 19; i >= 0; i--){
		for(int j = 19; j >= 0; j--){
			paths[i][j] = paths[i+1][j] + paths[i][j+1];
		}
	}

	cout << paths[0][0] << endl;
}