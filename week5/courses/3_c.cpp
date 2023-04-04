#include <iostream>
#include <cstdio>
#include <vector>
#include <stack>
#include <queue>
#include <cmath>
using namespace std;


int main() {
    int n;
    cin >> n;
    queue<int> q;
    stack<int> s;
    vector<int> v;
    for(int i = 0; i < n; i++){
        int x;
        cin>> x;
        q.push(x);
    }
    int cnt = 0;
    int cnt1 = 0;
    
    if(q.front() == n){
        s.push(n);
        q.pop();
    }
    while(!s.empty() && q.front() == s.top()-1 && q.front() != 1){
        s.push(q.front());
        q.pop();
    }
    if(q.front() == 1){
        s.push(1);
        cout << 1 << " " << s.size() << endl;
        cout << 2 << " " << 1 << endl;
        q.pop();
    }
    while(!s.empty() && !q.empty() && q.front() == s.top() + 1){
        cout << 1 << " " << 1<< endl;
        cout << 2 << " " << 1 << endl;
        s.pop();
        s.push(q.front());
        q.pop();
        cnt++;
    }
        // while(cnt>= 0){
        //     s.pop();
        //     cnt--;
        // }

        // cout << 2 << " " << s.size();

    

    return 0;
}
