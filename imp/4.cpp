#include <iostream>
using namespace std;
#define fori for(int i=0; i<n;i++)
int graph[100][100];
int n,m,x,y;
int main(){
    cin>>n>>m;
    fori{
        cin>>x>>y;
        x--;
        y--;
        graph[x][y]=1;
        graph[y][x]=1;
    }
    return 0;
}