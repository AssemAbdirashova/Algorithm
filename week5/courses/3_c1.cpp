#include <iostream>
#include <stack>
#include <queue>
 
using namespace std;

int main() {
    int n;
    cin >> n;
    stack<int> st;
    queue<int> queue;
    vector <pair<int,int> > v;
    int num = 1;

    for(int i = 0; i < n; i++){
        int x;
        cin >> x;
        if(!st.empty() && x > st.top()){
            cout << 0 << endl;
            return 0;
        }
        queue.push(1);
        st.push(x);
        while(!st.empty() && st.top() == num){
            queue.push(2);
            st.pop();
            num++;
        }
    }
 
    int val = queue.front();
    queue.pop();
    int count = 1;
  
    while(!queue.empty()){
        if(queue.front() == val){
            count++;
        }
        else{
            v.push_back(make_pair(val,count));
            val = queue.front();
            count = 1;
        }
        queue.pop();
    }

    cout << v.size() + 1 << endl;
    for(int i = 0; i < v.size(); i++) {
        cout<< v[i].first << " " << v[i].second << endl;
    }
    cout << val << " " << count << endl;
 
    return 0;
}