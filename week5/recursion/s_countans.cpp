#include <iostream>
#include <vector> 
#include <algorithm>
using namespace std;

int rec(int i, vector<int> v, int sum, int n, int sumx){
    if(i == n){
        if(sumx == sum){
           return 1;
        }
        return 0 ;
    }
    sumx += v[i];
    int l = rec(i+1, v, sum, n, sumx);
    sumx -= v[i];
    int r = rec(i+1, v, sum, n, sumx);
    return l + r;
}

int main(){
    int n;
    cin >> n;
    vector<int> v;
    vector<int> ans;
    for(int i = 0; i < n; i++){
        int x;
        cin>> x;
        v.push_back(x);
    }
    int x;
    cin >> x;
    cout << rec(0, v, x, n, 0);
   
}