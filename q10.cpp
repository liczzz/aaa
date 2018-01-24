#include <iostream>
using namespace std;

long long Fibonacci(unsigned n) {
    int result[2] = {0, 1};
    if (n < 2)
        return result[n];

    long long fibNMinusOne = 1;
    long long fibNMinusTwo = 0;
    long long fibN = 0;
    for (unsigned i = 2; i <= n; ++i) {
        fibN = fibNMinusOne + fibNMinusTwo;
        fibNMinusTwo = fibNMinusOne;
        fibNMinusOne = fibN;
    }
    return fibN;
}

void Fibonacci_alt_core(unsigned num, long long* result) {
    if (num == 1) {
        result[0] = 0;
        result[1] = 1;
        result[2] = 1;
        return;
    }

    long long pre_result[3] = {0};
    Fibonacci_alt_core(num/2, pre_result);
    result[0] = pre_result[1] * pre_result[1] + pre_result[0] * pre_result[0];
    result[1] = (pre_result[2] + pre_result[0]) * pre_result[1];
    result[2] = pre_result[2] * pre_result[2] + pre_result[1] * pre_result[1];
    if (num % 2 != 0) {
        long long temp = result[1];
        result[0] = temp;
        result[1] = result[2];
        result[2] += temp;
    }
}

long long Fibonacci_alt(unsigned n) {
    if (n == 0)
        return 0;
    if (n == 1)
        return 1;
    long long result[3] = {0};
    Fibonacci_alt_core(n - 1, result);
    return result[2];
}

int main(void) {
    cout << Fibonacci_alt(0) << endl;
    cout << Fibonacci_alt(1) << endl;
    cout << Fibonacci_alt(2) << endl;
    cout << Fibonacci_alt(3) << endl;
    cout << Fibonacci_alt(10) << endl;
    cout << Fibonacci_alt(100) << endl;
    return 0;
}
