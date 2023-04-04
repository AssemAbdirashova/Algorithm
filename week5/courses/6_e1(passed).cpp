#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include<unordered_map>
using namespace std;

int main(){
    int n,m;
    cin >> n >> m;

    int x[n][m];
    int a[n+1][m+1];
    for (int i = 0; i <= n; ++i){
        for (int j = 0; j <= m; ++j){
            a[i][j] = 0;
        }
    }

    for (int i = 0; i < n; ++i){
        for (int j = 0; j < m; ++j){
            cin >> x[i][j];
        }
    }
    int max_side = 0;
    int ix = 0;
    int jx = 0;
    for (int i = 0; i < n; ++i){
        for (int j = 0; j < m; ++j){
            if(x[i][j] == 1){
                a[i+1][j+1] = min({a[i+1][j], a[i][j], a[i][j+1]}) + 1;
                if(max_side < a[i+1][j+1]){
                    ix = i  - max_side + 1;
                    jx = j  - max_side + 1;
                    max_side = a[i+1][j+1];
                }
            }
        }
    }
    cout << max_side << endl;
    cout << ix << " " << jx << endl;
    return 0;
}