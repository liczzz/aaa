#include <iostream>
#include <random>
#include <stdexcept>
using namespace std;

void swap(int& a, int& b) {
    int temp = a;
    a = b;
    b = temp;
}

int partition(int* data, int length, int start, int end) {
    if (data == nullptr || length <= 0 || start < 0 || end >= length || start > end)
        throw std::exception();

    int index = rand() % (end - start + 1) + start;
    swap(data[index], data[end]);
    int j = start;
    for (int i = start; i < end; ++i) {
        if (data[i] < data[end]) {
            if (i != j) {
                swap(data[i], data[j]);
            }
            ++j;
        }
    }
    swap(data[j], data[end]);
    return j;
}

void quickSort(int* data, int length, int start, int end) {
    if (start >= end)
        return;

    int index = partition(data, length, start, end);
    if (index > start)
        quickSort(data, length, start, index - 1);
    if (index < end)
        quickSort(data, length, index + 1, end);
}

int main(void) {
    int data[10] = {5, 2, 10, 33, 12, 45, 232, 88, 66, 2};
    quickSort(data, 10, 0, 9);
    for (int i = 0; i < 10; ++i)
        cout << data[i] << ", ";
    return 0;
}
