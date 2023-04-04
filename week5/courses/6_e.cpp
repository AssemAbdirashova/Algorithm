#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include<unordered_map>
using namespace std;

int main(){
    int n,m;
    cin >> n >> m;

    int x[n+1][m+1];
    int a[n+1][m+1];

    for (int i = 1; i <= n; ++i){
        for (int j = 1; j <= m; ++j){
            cin >> x[i][j];
        }
    }
    int max_side = 0;
    int ix = 0;
    int jx = 0;
    for (int i = 1; i <= n; ++i){
        for (int j = 1; j <= m; ++j){
            if(x[i-1][j-1] == 1){
                a[i][j] = min({a[i - 1][j], a[i - 1][j - 1], a[i][j - 1]}) + 1;
                max_side = max(max_side, a[i][j]);
                ix = i + 1 - max_side;
                jx = j + 1 - max_side;
            }
            if(m == 1){
                if(x[i][j] == 1){
                    a[i][j] = min({a[i - 1][j], a[i - 1][j - 1], a[i][j - 1]}) + 1;
                    max_side = max(max_side, a[i][j]);
                    ix = i + 1 - max_side;
                    jx = j + 1 - max_side;
                }
            }
        }
    }
    cout << max_side << endl;
    cout << ix << " " << jx;

    return 0;
}