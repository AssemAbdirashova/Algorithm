// O(n+m)
// поиск в глубину
#include <iostream>
#include <vector>
#include <queue>
using namespace std;
vector<int> adj[100];
bool visited[100];
void dfs(int s){
    if(visited[s]) return;
    visited[s] = true;
    // 
    for (auto u: adj[s]){
        dfs(u);
    }
}
int main(){
	
	int a;
	cin>>a;
	dfs(a);
}