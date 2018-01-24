#include <iostream>
using namespace std;

void ReplaceBlank(char string[], int length) {
	if (string == nullptr || length <= 0) 
		return;
	int originLength = 0;
	int numOfBlanks = 0;
	int i = 0;
	while (string[i] != '\0') {
		++originLength;
		if (string[i] == ' ') {
			++numOfBlanks;
		}
		++i;
	}

	int newLength = originLength + 2 * numOfBlanks;
	if (newLength >= length)
		return;
	int j = newLength;
	while (i >= 0 and j > i) {
		if (string[i] == ' ') {
			string[j--] = '0';
			string[j--] = '2';
			string[j--] = '%';
		}
		else {
			string[j--] = string[i];
		}
		--i;
	}
}

int main(void) {
	char str[18] = "We are happy.";
	ReplaceBlank(str, 18);
	cout << str << endl;
	return 0;
}
