#include <iostream>
#include <vector> 
#include <algorithm>
using namespace std;

bool p(int i, string s){
    int n = s.size(); 
    if(i >= n/2){
        return true;
    }
    if(s[i] != s[n - i - 1]){
        return false;
    }
    return p(i + 1, s);
}

int main(){
    string s;
    cin >> s;
    cout << p(0, s);

return 0;
}