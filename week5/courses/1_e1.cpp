#include <iostream>
#include <cstdio>
#include <cmath>
using namespace std;

double a, b, c, d;

double func(double x) {
    return a * x * x * x + b * x * x + c * x + d;
}

int main() {
  
    cin >> a >> b >> c >> d;
    double r = 1;
    while (func(r) * func(-r) >= 0) {
        r *= 2;
    }
    double l = -r;
    while (r - l > 1e-6) {
        double mid = (l + r) / 2;
        if (func(mid) * func(r) > 0) {
            r = mid;
        } else {
            l = mid;
        }
    }

    cout << l;
    return 0;
}
