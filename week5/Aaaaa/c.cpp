#include<iostream>
#include<queue>

using namespace std;

int main(){
    int n;
    cin >> n;
    int a[n];
    queue<int> q;
    for(int i= 0; i< n;i++){
        cin >> a[i];
    }
    for(int i = 0; i < n; i++){      
        q.push(a[i]);

        while(q.front() < a[i] - 3000){
          q.pop();
        }

        cout << q.size() << " ";
    }
  return 0;
}