/*
Each character on a computer is assigned a unique code and the preferred standard is ASCII 
(American Standard Code for Information Interchange). For example, uppercase A = 65, asterisk (*) = 42, and lowercase k = 107.

A modern encryption method is to take a text file, convert the bytes to ASCII, then XOR each byte with a given value, 
taken from a secret key. The advantage with the XOR function is that using the same encryption key on the cipher text, 
restores the plain text; for example, 65 XOR 42 = 107, then 107 XOR 42 = 65.

For unbreakable encryption, the key is the same length as the plain text message, and the key is made up of random bytes. 
The user would keep the encrypted message and the encryption key in different locations, and without both "halves", it is 
impossible to decrypt the message.

Unfortunately, this method is impractical for most users, so the modified method is to use a password as a key. 
If the password is shorter than the message, which is likely, the key is repeated cyclically throughout the message. 
The balance for this method is using a sufficiently long password key for security, but short enough to be memorable.

Your task has been made easy, as the encryption key consists of three lower case characters. 
Using cipher.txt (right click and 'Save Link/Target As...'), a file containing the encrypted ASCII codes, and the 
knowledge that the plain text must contain common English words, decrypt the message and find the sum of the ASCII values 
in the original text.
*/

#include <iostream>
#include <vector>
#include <cstring>

using namespace std;

int mostCommon(vector<int>);

int main(void){

	vector<int> first;
	vector<int> second;
	vector<int> third;

	vector<int> line;

	int count = 1;
	int tmp;
	while(cin >> tmp){
		if(count > 3) count = 1;
		if(count == 1) first.push_back(tmp);
		if(count == 2) second.push_back(tmp);
		if(count == 3) third.push_back(tmp);

		count++; 
	}

	//assume that the space is the most occurring character in each group and XOR it out to retrieve the key
	int key1 = 32 ^ mostCommon(first);
	int key2 = 32 ^ mostCommon(second);
	int key3 = 32 ^ mostCommon(third);

	int sum = 0;
	for(int i = 0; i < first.size(); i++){
		sum += (key1 ^ first[i]);
		if(i < second.size()) sum += (key2 ^ second[i]);
		if(i < third.size()) sum += (key3 ^ third[i]);
	}

	cout << sum << endl;
}

int mostCommon(vector<int> chars){
	int charmap[256];
	memset(charmap, 0, sizeof(charmap));

	for (int i = 0; i < chars.size(); i++){
		charmap[chars[i]]++;
	}

	int max = 0;
	for(int i = 0; i < 256; i++){
		if(charmap[i] > max) max = i;
	}

	return max;
}