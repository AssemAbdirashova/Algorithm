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
void rec(int i, vector<int> v, vector<int>& ans){
    if(i == v.size()){
        print(ans);
        return;
    }
    ans.push_back(v[i]);
    rec(i+1, v, ans);
    ans.pop_back();
    rec(i+1, v, ans);
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
    rec(0, v, ans);
   
}