#include <iostream>
#include <vector>

using namespace std;

const int MAXN = 100005;

int n, m;
vector<int> g[MAXN];
bool used[MAXN];
int color[MAXN];

bool dfs(int v){
    used[v] = true;
    color[v] = 1;
    for(int to : g[v]){
        if(color[to] == 1){
            return true;
        }
        if(!used[to] && dfs(to)){
            return true;
        }
    }
    color[v] = 2;
    return false;
}

bool has_cycle(){
    for(int i = 1; i <= n; i++){
        if(!used[i] && dfs(i)){
            return true;
        }
    }
    return false;
}

int main(){
    cin >> n >> m;
    for(int i = 1; i <= m; i++){
        int u, v;
        cin >> u >> v;
        g[u].push_back(v);
    }
    if(has_cycle()){
        cout << 1 << endl;
    }else{
        cout << 0 << endl;
    }
    return 0;
}
