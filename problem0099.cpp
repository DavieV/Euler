/*
Comparing two numbers written in index form like 211 and 37 is not difficult, as any calculator would confirm 
that 211 = 2048 < 37 = 2187.

However, confirming that 632382518061 > 519432525806 would be much more difficult, as both numbers contain over 
three million digits.

Using base_exp.txt (right click and 'Save Link/Target As...'), a 22K text file containing one thousand lines with 
a base/exponent pair on each line, determine which line number has the greatest numerical value.

NOTE: The first two lines in the file represent the numbers in the example given above.
*/
#include <iostream>
#include <cmath>

using namespace std;

int main(void){

	int maxLine = 1;
	int curLine = 1;
	int maxBase, maxExp;

	scanf("%d,%d", &maxBase, &maxExp);

	int tmpBase, tmpExp;

	while(scanf("%d,%d", &tmpBase, &tmpExp) != -1){
		curLine++;
		if(tmpExp * log(tmpBase) > maxExp * log(maxBase)){
			maxExp = tmpExp;
			maxBase = tmpBase;
			maxLine = curLine;
		}
	}
	cout << maxExp << " " << maxBase << " " << maxLine << endl;
}