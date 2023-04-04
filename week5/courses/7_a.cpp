#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include<unordered_map>
#include <cmath>
using namespace std;


int main() {
    int n, m;
    cin >> n >> m;
    double sqrt5 = sqrt(5);
    int r = 0;
    for(int i = 1; i < 96; i++) {
        int x = int((1 + sqrt5)/2*i + 1);
        int y = int((3 + sqrt5)/2*i + 1);
        if((n == x && m == y) || (n == y && m == x)){
            r = 2;
            break;
        }else{
                r = 1;
        }
        if((x > n && y > m) || (x > m && y > n)){
            break;
        }
    }
    cout << r;
    return 0;
}
