#include <iostream>
#include <vector>
#include <algorithm>
#include <fstream>

using namespace std;

static const int MAXN = 100000;

int n;
vector<int> g[MAXN];
bool used[MAXN];
vector<int> comp;

void dfs(int v) {
    used[v] = true;
    comp.push_back(v);
    for (size_t i = 0; i < g[v].size(); ++i) {
        int to = g[v][i];
        if (!used[to])
            dfs(to);
    }
}

void find_comps(ofstream& out) {
    int num_comps = 0;
    for (int i = 0; i < n; ++i)
        used[i] = false;
    for (int i = 0; i < n; ++i)
        if (!used[i]) {
            comp.clear();
            dfs(i);
            num_comps++;

            // Output component
            out << comp.size() << endl;
            sort(comp.begin(), comp.end());
            for (size_t j = 0; j < comp.size(); ++j)
                out << comp[j] << " ";
            out << endl;
        }
    out.seekp(0);
    out << num_comps << endl;
}

int main() {
    // Create an undirected graph for testing
    n = 6;
    g[0].push_back(1);
    g[1].push_back(0);
    g[1].push_back(2);
    g[1].push_back(3);
    g[2].push_back(1);
    g[3].push_back(1);
    g[3].push_back(4);
    g[3].push_back(5);
    g[4].push_back(3);
    g[5].push_back(3);

    // Output connectivity components to file
    ofstream out("output.txt");
    find_comps(out);
    out.close();

    return 0;
}
