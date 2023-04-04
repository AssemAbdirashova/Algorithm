#include <iostream>
#include <vector> 
#include <stack> 
#include <queue> 
#include <algorithm>
using namespace std;

class MinStack {
public:
    MinStack() {}
    stack<int> s;
    stack<int> min;
    
    void push(int val) {
        s.push(val);
        if(min.empty() || val <= min.top()) min.push(val);
    }
    
    void pop() {
        int y = s.top();
        s.pop();
        if(y == min.top()) min.pop();
    }
    
    int top() {
        return s.top();
    }
    
    int getMin() {
        return min.top();
    }
    bool empty(){
        return s.empty();
    }
};
void fillPrefixSum(vector<int> v, int n, int prefixSum[]){
    prefixSum[0] = v[0];
    // Adding present element with previous element
    for (int i = 1; i < n; i++)
        prefixSum[i] = prefixSum[i - 1] + v[i];
}

int main(){
    int n;
    cin >> n;
    vector<int> v;
    vector<int> res;
    vector<int> res2;
    vector<int> ans;
    MinStack st;
    
    for(int i = 0; i < n; i++){
        int x;
        cin>> x;
        v.push_back(x);
    }
    int sum = 0;
    int maxx = -1000000;

    int prefixSum[n];
    fillPrefixSum(v, n, prefixSum);

    stack<int> st1;
   
    for(int i = 0; i < n; ++i){
        cout << prefixSum[i] << " ";
    }
    cout << endl;

    for(int i = 0; i < n; i++) {
        while(!st1.empty() && v[i] <= v[st1.top()]){
           // cout << st.top() << "мы только что удалили" << endl;
            st1.pop();
        }

        if(st1.empty()){
            ans.push_back(-1);
            cout << -1 << " ";
        }else{
            ans.push_back(st1.top());
            cout << st1.top() << " ";
        }

        st1.push(i);
    }
    cout << endl;
    int i = 0;
    while(i < ans.size()-1){
        if(ans[i] == -1){
            //if(maxx < prefixSum[i] * v[ans[i]]){
                maxx = prefixSum[i] * v[i];
                cout << maxx << " ";
            //}
        }else{
            //if(maxx < prefixSum[i - ans[i] - 1] * v[ans[i]]){
            maxx = prefixSum[i - ans[i] - 1] * v[ans[i]];
            cout << maxx << " "; 
            //}
        }
        while(ans[i] == ans[i+1] && ans[i] != -1){
            i++;
        }
        i++;
    }
    cout << maxx << endl;
    for(int i = 0; i < n; i++) {
        st.push(v[i]);
        sum = v[i];
        for(int j = i + 1; j < n; j++){
            st.push(v[j]);
            res.push_back(st.getMin());
            sum = sum + v[j];
            res2.push_back(sum);
            if(maxx < sum * st.getMin()){
                maxx = sum * st.getMin();
            }
        }
        while(!st.empty()){
            st.pop();
        }
    }
    for(int i = 0; i < res.size(); ++i) {
        cout << res[i] << " ";
    }
    cout << endl;
    for(int i = 0; i < res2.size(); ++i) {
        cout << res2[i] << " " ;
    }
    cout << endl << maxx;
}