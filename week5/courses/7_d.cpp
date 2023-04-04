#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include<unordered_map>
using namespace std;

void rec(int i, vector<int>& v, vector<int>& ans, int target, int n , vector<vector<int>>& result){
    if(i == n){
        if(target == 0){
            result.push_back(ans);
        }
        return;
    }
    if(v[i] <= target){
        ans.push_back(v[i]);
        rec(i, v, ans, target - v[i], n, result);
        ans.pop_back();
    }
    rec(i+1, v, ans, target, n,result);
}

int main(){
    int n;
    cin >> n;
    vector<vector<int>> result;
    vector<int> candidates;

    for(int i = n; i >= 1; i--){
        candidates.push_back(i);
    }
    vector<int> ans;
    rec(0, candidates,ans, n,n,result );
    for(int i = result.size()-1; i >= 0 ; i--){
        for(int j = 0; j < result[i].size(); j++){
            cout << result[i][j] << " ";
        }
        cout << endl;
    }
}