#include <iostream>
#include <queue>
#include <vector>
#include <cstring>
using namespace std;

const int MAXK = 100005;

int k;
bool vis[MAXK];
int digit[MAXK];
int dist[MAXK];

void bfs() {
    memset(vis, 0, sizeof(vis));
    memset(dist, -1, sizeof(dist));
    queue<int> q;
    q.push(1 % k);
    vis[1 % k] = true;
    digit[1 % k] = 1;
    dist[1 % k] = 0;
    while (!q.empty()) {
        int u = q.front();
        q.pop();
        int v1 = (u + 1) % k;
        int v2 = (u * 10) % k;
        if (!vis[v1]) {
            q.push(v1);
            vis[v1] = true;
            digit[v1] = 1;
            dist[v1] = dist[u] + 1;
        }
        if (!vis[v2]) {
            q.push(v2);
            vis[v2] = true;
            digit[v2] = 0;
            dist[v2] = dist[u] + 1;
        }
    }
}

int main() {
    cin >> k;
    bfs();
    vector<int> ans;
    int x = 0;
    while (x != 1) {
        ans.push_back(digit[x]);
        if (digit[x] == 0) x = (x * 10) % k;
        else x = (x + 1) % k;
    }
    ans.push_back(1); // add the last digit
    cout << dist[0] + 1 << endl; // output the distance + 1
    for (int i = ans.size() - 1; i >= 0; i--) {
        cout << ans[i];
    }
    cout << endl;
    return 0;
}
