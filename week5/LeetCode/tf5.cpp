#include <iostream>
#include <vector>
 
using namespace std;

void dfs(const vector<vector<pair<int, int>>>& graph, int i,
    vector<bool> &used, vector<int>& dp, vector<int>& workTime) {
    used[i] = true;

    for(const auto& child : graph[i]){
        if (!used[child.first]) {
            dfs(graph, child.first, used, dp, workTime);
        }
    }
    int dp0 = 1000000, dp1 = 1000000;

    for(const auto& child : graph[i]){
        if(child.second == 0){
            dp0 = min(dp0, dp[child.first] + 1);
        }else{
            dp1 = min(dp1, dp[child.first] + 1);
        }
    }

    if(dp0 > dp1){
        workTime[i] = 0;
        dp[i] = dp0;
    }else{
        workTime[i] = 1;
        dp[i] = dp1;
    }
}
 
int main() {
    int n, m;
    cin >> n >> m;
    
    vector<vector<pair<int, int>>> graph(n);
    for(int i = 0; i < m; ++i){
        int from, to, ok;
        cin >> from >> to >> ok;
        --from;
        --to;
        graph[from].emplace_back(to, ok);
    }
    vector<int> dp(n, 1000000), workTime(n, 1);
    vector<bool> used(n, false);

    used[n - 1] = true;
    dp[n - 1] = 0;

    if(n > 1){
        dfs(graph, 0, used, dp, workTime);
        if(dp[0] >= 1000000){
            cout << -1 << endl;
        }else{
            cout << dp[0]<< endl;
        }
        for(const auto& i : workTime){
            cout << i;
        }
        cout << endl;
    }else{
        cout << "\n";
    } 

    return 0;
}
 