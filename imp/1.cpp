#include <vector>
#include <tuple>
#include <stdexcept>
#include <iostream>
#define ll long long
#define F first
#define S second

using namespace std;
typedef vector<int> vi;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin>>n;
    vector<int>adj[n]; //Списки смежности
    adj[1].push_back(2);
    

    vector<pair<int,int> > v[10]; //Для взвешенных графов
    v[1].push_back(make_pair(2,5));
    int adj3[n][n];//Матрица смежности

    vector<pair<int, int> > edges;
    edges.push_back(make_pair(1,2));

    //vector<tuple<int, int, int> > edg;//Для взвешенных графов 
    
    return 0;
}