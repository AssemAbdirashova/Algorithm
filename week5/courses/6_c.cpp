#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include<unordered_map>
using namespace std;

int rec(int i, int j, int n, int m, int a[15][15]){
    if(i >= 0 && j >= 0 && i < n && j < m){
        if(a[i][j] == -1){
            a[i][j] = rec(i-2, j-1, n, m, a) + rec(i-1, j-2, n, m, a) + rec(i-2, j+1, n, m, a) + rec(i+1, j-2, n, m, a);
        }
    }else{
        return 0;
    }
    //cout << a[i][j] << endl;
    return a[i][j];
}
int main(){
    int n, m;
    cin >> n >> m;
    int a[15][15];
    for(int i  =0 ; i< 15; i++){
        for(int j = 0; j < 15; j++){
            a[i][j] = -1;
        }
    }
    a[0][0] = 1;
    cout<< rec(n-1,m-1,n,m,a) << endl;
    return 0;
}
