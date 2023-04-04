#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include<unordered_map>
#include<map>
using namespace std;
map<long long, long long> memo;

vector<long long int> fib1(int x){
    vector<long long int> v;
    long long int i;
    v.push_back(1);
    v.push_back(1);
    //1e5
    for(i = 2; i <= x ; i++){
        v.push_back(v[i - 1] + v[i - 2]);
    }
    reverse(v.begin(), v.end());
    return  v;
};


int main(){
    long long int target,n;
    cin  >> n;
    vector<long long int> candidates;
    vector<long long int> fib;
    long long int sum = 0;
    long long int maxx = 0;


    for(long long int i = 0 ; i < n; i++){
        long long int r;
        cin>>r;
        candidates.push_back(r);
    }

    
    for(long long int i = 0; i < n; i++){
        long long int cnt = 0;
        vector<vector<long long int>> dp(candidates[i], vector<long long int>(31));
        fib = fib1(candidates[i]);
        dp[0][0] = 1;
        for (int t = 0; t < fib.size(); t++) {
            for (int j = candidates[i]; j >= fib[t]; j--) {
                for (int k = 0; k < 31; k++) {
                    dp[j][k] += dp[j-fib[t]][k-1];
                }
            }
        }

        long long int ans = 0;
        for (int t = 1; t < 31; t++) {
            ans += dp[candidates[i]][t];
        }
        cout << ans << endl;
    }
}