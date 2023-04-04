#include<iostream>
#include <vector>
using namespace std;

vector < vector<int> > g; // граф
int n; // число вершин

vector<char> used;

void dfs (int v) {
	used[v] = true;
	for (vector<int>::iterator i=g[v].begin(); i!=g[v].end(); ++i)
		if (!used[*i])
			dfs (*i);
}
int main(){
    return 0;
}