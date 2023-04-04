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
bool rec(int i, vector<int> v, vector<int> ans, int sum, int n, int sumx){
    if(i == n){
        if(sumx == sum){
            print(ans);
            return true;
        }
        return false ;
    }
    sumx += v[i];
    ans.push_back(v[i]);
    if(rec(i+1, v, ans, sum, n, sumx) == true){
        return true;
    }
    sumx -= v[i];
    ans.pop_back();
    if(rec(i+1, v, ans, sum, n, sumx)){
        return true;
    }
    return false;
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