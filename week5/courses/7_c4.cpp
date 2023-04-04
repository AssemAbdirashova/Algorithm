#include <iostream>
#include <unordered_map>
using namespace std;

unordered_map<int, int> fib; // Memoization for Fibonacci numbers

int count_ways(int n) {
    if (n == 0 || n == 1) {
        return 1; // Base case
    }
    if (fib.count(n)) { // Check if already computed
        return fib[n];
    }
    int ways = 0;
    for (int i = 1; i <= n; i++) {
        int j = n - i;
        if (fib[i] && count_ways(j)) { // Check if both i and j are Fibonacci
            ways += count_ways(i) * count_ways(j);
        }
    }
    fib[n] = ways; // Memoize result
    return ways;
}

int main() {
    int x;
    cout << "Enter a natural number: ";
    cin >> x;
    int ways = count_ways(x);
    cout << "The number of ways to represent " << x << " as a product of Fibonacci numbers is: " << ways << endl;
    return 0;
}
