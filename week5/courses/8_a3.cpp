#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
int n, m;
const int MAXN = 100000;
vector<int> comp;
vector<int> g[MAXN];
bool used[MAXN];


void dfs(int v) {
    used[v] = true;
    comp.push_back(v);
    for (size_t i = 0; i < g[v].size(); ++i) {
        int to = g[v][i];
        if (!used[to])
            dfs(to);
    }
}
void print() {
    vector<vector<int>> components;
    for (int i = 1; i <= n; ++i)
        used[i] = false;
    for (int i = 1; i <= n; ++i)
        if (!used[i]) {
            comp.clear();
            dfs(i);
            sort(comp.begin(), comp.end());
            components.push_back(comp);
        }
    cout << components.size() << endl;
    for (const auto &component : components) {
        cout << component.size() << endl;
        for (const auto &v : component)
            cout << v << " ";
        cout << endl;
    }
}

int main() {
    cin >> n >> m;
    for (int i = 0; i < m; ++i) {
        int u, v;
        cin >> u >> v;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    print();
    return 0;
}
