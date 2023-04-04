#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include<unordered_map>
using namespace std;

vector<long long int> fib(long long int n){
    vector<long long int> v;
    long long int i;
    v.push_back(1);
    v.push_back(1);

    for(i = 2; i <= n; i++){
        v.push_back(v[i - 1] + v[i - 2]);
    }
    return  v;
};
void rec(int i, vector<long long int>& v, vector<long long int>& ans, long long int target,long long int n , vector<long long int> result){
    if(i == n){
        if(target == 1){
            result.push_back(ans.size());
        }
        return;
    }
    if(target % v[i] == 0){
        ans.push_back(v[i]);
        long long int x = target/v[i];
        rec(i, v, ans, x, n, result);
        ans.pop_back();
    }
    rec(i+1, v, ans, target, n,result);
}


int main(){
    long long int target,n;
    cin  >> n;
    vector<long long int> candidates;
    vector<long long int> v;
    long long int sum = 0;
    long long int maxx = 0;

    for(long long int i = 0 ; i < n; i++){
        long long int r;
        cin>>r;
        candidates.push_back(r);
        maxx = max(r, maxx);
    }
    int k = sqrt(maxx);
    v = fib(k);
    //cout << v[0] << v[1] << v[2] << v[3];
    // for(long long int i = 0; i < n; i++){
    //     vector<long long int> ans;
    //     vector<long long int> result;
    //     rec(0, v, ans, candidates[i],v.size(), result);
    //     if(!result.empty()){
    //         sort(result.begin(), result.end());
    //         cout << result[0] << endl;
    //     }else{
    //         cout << 0 << endl;
    //     }
    // }
    vector<long long int> ans;
        vector<long long int> result;
        rec(0, v, ans, 8,v.size(), result);
       // sort(result.begin(), result.end());
        cout << result[0] << endl;
}