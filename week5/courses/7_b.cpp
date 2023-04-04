#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include<unordered_map>
using namespace std;

void rec(long long int i, vector<long long int>& v, vector<long long int>& ans, long long int target,vector<vector<long long int> >& result){
    if(target == 0){
        result.push_back(ans);
        return;
    }
    
    for(long long int j = i; j < v.size(); j++){
        if(j > i && v[j] == v[j-1]) continue;
        if(v[j] > target){
            break;
        } 
        ans.push_back(v[j]);
        rec(j+1, v, ans, target - v[j], result);
        ans.pop_back();
    }
}

int main(){
    long long int target,n;
    cin >> target>> n;
    vector<vector<long long int>> result;
    vector<long long int> candidates;
    long long int sum = 0;
    for(long long int i = n; i >= 1; i--){
        long long int r;
        cin>>r;
        candidates.push_back(r);
        candidates.push_back(r);
        sum = sum+r+r;
    }
    sort(candidates.begin(), candidates.end());
    vector<long long int> ans;
    rec(0, candidates,ans, target,result);
    long long int max = 1000000000;
    long long int save = 0;
    
    if(result.empty() && sum < target){
        cout << -1;
    }else if(result.empty() && sum > target){
        cout << 0;
    }else{
        for(long long int i = result.size()-1; i >= 0 ; i--){
            if(result[i].size() < max){
                max = result[i].size();
                save = i;
            }
        }
        cout << result[save].size() << endl;
        for(long long int j = 0; j < result[save].size(); j++){
                cout << result[save][j] << " ";
        }
        cout << endl;
    }
}