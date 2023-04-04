#include <iostream>
#include <vector> 
#include <algorithm>
using namespace std;


void rec(int i, vector<int>& v){
    int n = v.size();
    if(i >= n/2){
        return;
    }
    swap(v[i], v[n-i-1]);
    rec(i+1,v);
}

int main(){
    int n;
    cin >> n;
    vector<int> v;
    for(int i = 0; i < n; i++){
        int x;
        cin>> x;
        v.push_back(x);
    }
    rec(0, v);
    for(int i = 0; i < n; i++){
        cout << v[i] << " ";
    }
}