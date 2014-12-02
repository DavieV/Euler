/*
Using names.txt (right click and 'Save Link/Target As...'), a 46K text file containing over five-thousand first names, 
begin by sorting it into alphabetical order. Then working out the alphabetical value for each name, 
multiply this value by its alphabetical position in the list to obtain a name score.For example, when the list is sorted 
into alphabetical order, COLIN, which is worth 3 + 15 + 12 + 9 + 14 = 53, is the 938th name in the list. 
So, COLIN would obtain a score of 938 × 53 = 49714.

What is the total of all the name scores in the file?
*/

#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int strCompare(string, string);

int main(void){
	vector<string> names;
	string tmp;
	while(cin >> tmp){
		names.push_back(tmp);
	}
	sort(names.begin(), names.end());

	int sum = 0;
	int wordSum = 0;

	for(int i = 0; i < names.size(); i++){
		for(int j = 0; j < names[i].length(); j++){
			wordSum += names[i][j] - 'A' + 1;
		}
		sum += wordSum * (i + 1);
		wordSum = 0;
	}

	cout << sum << endl;
}

int strCompare(string a, string b){
	return a.compare(b) < 0;
}