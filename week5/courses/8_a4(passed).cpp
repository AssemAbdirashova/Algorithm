#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

const int MAXN = 100000;

int n, m;
vector<int> g[MAXN];
bool used[MAXN];
vector<int> comp;

void dfs(int v){
    used[v] = true;
    comp.push_back(v);
    for (int i = 0; i < g[v].size(); ++i) {
        int to = g[v][i];
        if (!used[to])
            dfs(to);
    }
}

int main(){
    cin >> n >> m;
    for (int i = 0; i < m; ++i) {
        int u, v;
        cin >> u >> v;
        --u, --v;
        g[u].push_back(v);
        g[v].push_back(u);
    }

    int num_components = 0;
    vector<vector<int>> components;

    for (int i = 0; i < n; ++i) {
        if (!used[i]) {
            comp.clear();
            dfs(i);
            ++num_components;
            sort(comp.begin(), comp.end());
            components.push_back(comp);
        }
    }

    cout << num_components << "\n";
    for (int i = 0; i < num_components; ++i) {
        cout << components[i].size() << "\n";
        for (int j = 0; j < components[i].size(); ++j)
            cout << components[i][j] + 1 << " ";
        cout << "\n";
    }

    return 0;
}
