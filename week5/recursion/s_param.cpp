#include <iostream>
#include <vector> 
#include <algorithm>
using namespace std;

void print(vector<int> v){
     for(int i = 0; i < v.size(); i++){
        cout << v[i] << " ";
    }
    cout << endl;
}
void rec(int i, vector<int> v, vector<int> ans, int sum, int n, int sumx){
    // if(sumx > sum){
    //     return;
    // }
    if(i == n){
        if(sumx == sum){
            print(ans);
        }
        return;
    }
    sumx += v[i];
    ans.push_back(v[i]);
    rec(i+1, v, ans, sum, n, sumx);
    sumx -= v[i];
    ans.pop_back();
    rec(i+1, v, ans, sum, n, sumx);
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
    rec(0, v, ans, x, n, 0);
   
}