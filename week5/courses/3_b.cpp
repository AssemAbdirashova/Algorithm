#include <iostream>
#include <vector> 
#include <queue> 
#include <algorithm>
using namespace std;


int main(){
    int n;
    cin >> n;
    int k;
    cin >> k;
    vector<int> v;

    for(int i = 0; i < n; i++){
        int x;
        cin>> x;
        v.push_back(x);
    }
    vector<int> ans;
    deque<int> dq;
    for(int i = 0; i < n; ++i) {
        int startIdx = i - k;
        if(!dq.empty() and dq.front() == startIdx){
            dq.pop_front();
        }

        while(!dq.empty() and v[i] < v[dq.back()])
            dq.pop_back();
    
        dq.push_back(i);
        if(i >= k - 1){ 
            ans.push_back(v[dq.front()]);
        }
    }
    for(int i = 0; i < ans.size(); i++){
        cout << ans[i] <<" ";
    }
}