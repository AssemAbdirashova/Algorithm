#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include<unordered_map>
using namespace std;

int main(){
    int x;
    cin >> x;
    int a[20];
    a[0] = 1;
    a[1] = 3;
    for(int i = 2; i<= x; i++){
        a[i] = 2*(a[i-1] + a[i-2]);
    }
    cout << a[x];
    return 0;
}
