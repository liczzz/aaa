#include <iostream>
using namespace std;

int MinInOrder(int* numbers, int start, int end) {
	int min = numbers[end];
	for (int i = start; i < end; ++i) {
		if (numbers[i] < min)
			min = numbers[i];
	}
	return min;
}

int Min(int* numbers, int length) {
	if (numbers == nullptr || length <= 0)
		throw exception();

	int index0 = 0;
	int index1 = length - 1;
	int indexMid = index0;
	while (numbers[index0] >= numbers[index1]) {
		if (index1 - index0 == 1) {
			indexMid = index1;
			break;
		}
		indexMid = (index0 + index1)/2;
		if (numbers[indexMid] == numbers[index0] && numbers[indexMid] == numbers[index1])
			return MinInOrder(numbers, index0, index1);
		if (numbers[indexMid] >= numbers[index0])
			index0 = indexMid;
		else if (numbers[indexMid] <= numbers[index1])
			index1 = indexMid;
	}
	return numbers[indexMid];
}

int main(void) {
	int n;
	cin >> n;
	int* numbers = new int[n];
	for (int i = 0; i < n; ++i)
		cin >> numbers[i];
	cout << Min(numbers, n) << endl;
	delete [] numbers;
	return 0;
}
