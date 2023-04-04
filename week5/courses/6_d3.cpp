#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include<unordered_map>
using namespace std;

int main(){
    string s1, s2;
    cin >> s1 >> s2;
    int n = s1.length();
    int m = s2.length();
    int a[n+1][m+1];
    for (int i = 1; i <= n; ++i){
        a[i][0] = i;
    }
    for (int j = 1; j <= m; ++j){
        a[0][j] = j;
    }
    int cnt;
    for (int i = 1; i <= n; ++i){
        for (int j = 1; j <= m; ++j){
            if (s1[i-1] == s2[j-1]){
                a[i][j] = a[i - 1][j - 1];
            }else{
                a[i][j] = 1 + min({a[i][j-1], a[i-1][j], a[i-1][j-1]});
            }
        }
    }
    cout << a[n][m];

    return 0;
}