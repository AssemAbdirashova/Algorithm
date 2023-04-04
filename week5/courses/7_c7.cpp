#include <iostream>
#include <unordered_map>
using namespace std;

unordered_map<int, int> fib_map;

int fib(int n) {
    if (n <= 1) return n;
    if (fib_map.find(n) != fib_map.end()) {
        return fib_map[n];
    }
    int res = fib(n-1) + fib(n-2);
    fib_map[n] = res;
    return res;
}

int count_ways(int n) {
    if (n <= 1) return 1;
    int res = 0;
    for (int i = 1; fib(i) <= n; i++) {
        res += count_ways(n / fib(i));
    }
    return res;
}

int main() {
    int n = 64;
    int ways = count_ways(n);
    cout << "The number of ways to represent " << n << " as a product of Fibonacci numbers is: " << ways << endl;
    return 0;
}
