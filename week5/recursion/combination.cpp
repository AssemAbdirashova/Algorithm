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

void rec(int i, vector<int> v, vector<int>& ans, int target, int n , vector<vector<int> >& result){
    if(i == n){
        if(target == 0){
            result.push_back(ans);
            print(ans);
        }
        return;
    }
    if(v[i] <= target){
        ans.push_back(v[i]);
        rec(i, v, ans, target - v[i], n, result);
        ans.pop_back();
    }
    rec(i+1, v, ans, target, n, result);
}

int main(){
    int n;
    cin >> n;
    vector<int> v;
    vector<int> ans;
    vector<vector<int> > result;
    for(int i = 0; i < n; i++){
        int x;
        cin>> x;
        v.push_back(x);
    }
    int x;
    cin >> x;
    rec(0, v, ans, x, n, result);
   
}