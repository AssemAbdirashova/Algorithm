#include <iostream>
#include <vector>

using namespace std;

vector<int> fibonacci(int n) {
    vector<int> fib;
    int a = 0, b = 1, c;
    while(b <= n) {
        fib.push_back(b);
        c = a + b;
        a = b;
        b = c;
    }
    return fib;
}

int countWays(int x, vector<int>& fib, vector<int>& memo) {
    if(x == 0) {
        return 1;
    }
    if(memo[x] != -1) {
        return memo[x];
    }
    int ways = 0;
    for(int i = 0; i < fib.size(); i++) {
        if(x >= fib[i] && x % fib[i] == 0) {
            ways += countWays(x / fib[i], fib, memo);
        }
    }
    memo[x] = ways;
    return ways;
}

int main() {
    int x = 64;
    vector<int> fib = fibonacci(x);
    vector<int> memo(x + 1, -1);
    int ways = countWays(x, fib, memo);
    cout << "The number of ways to represent " << x << " as a product of Fibonacci numbers is: " << ways << endl;
    return 0;
}
