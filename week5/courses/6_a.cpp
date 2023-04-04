#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include<unordered_map>
using namespace std;

int main(){
    int x;
    cin >> x;
    int a[x];
    for(int i = 0; i < x; i++){
        cin >> a[i];
    }
    for(int i = 2; i< x; i++){
        a[i] += min(a[i-1], a[i-2]);
    }
    cout << a[x-1];
    return 0;
}