#include <iostream>
using namespace std;

bool duplicate(int numbers[], int length, int* duplication) {
	if (numbers == nullptr || length <= 0)
		return false;

	for (int i = 0; i < length;) {
		if (numbers[i] != i) {
			if (numbers[i] > length - 1 || numbers[i] < 0)
				return false;
			else if (numbers[i] != numbers[numbers[i]]) {
				int temp = numbers[i];
				numbers[i] = numbers[temp];
				numbers[temp] = temp;
			}
			else {
				*duplication = numbers[i];
				return true;
			}
		}
	        else
			i++;
	}
	return false;
}

int main(void){
	int* duplication = new int[1];
	int numbers[] = {2, 3, 1, 0, 4, 5, 6};
	int length = 7;
	if (duplicate(numbers, length, duplication)) {
		cout << *duplication << endl;
	}
	delete [] duplication;
	return 0;
}
