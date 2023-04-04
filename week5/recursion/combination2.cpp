#include <iostream>
#include <vector> 
#include <algorithm>
using namespace std;

void print(vector<int> v){
     for(int i = 0; i < v.size(); i++){
        cout << v[i] << " ";
    }
    cout << endl;
}

void rec(int i, vector<int>& v, vector<int>& ans, int target, int n , vector<vector<int> >& result){
 
        if(target == 0){
            result.push_back(ans);
            print(ans);
            return;
        }
  
    for(int j = i; j < v.size(); j++){
        if(j > i && v[j] == v[j-1]) continue;
        if(v[j] > target) continue;
        ans.push_back(v[j]);
        rec(j+1, v, ans, target - v[j], n, result);
        ans.pop_back();
    }
}

int main(){
    int n;
    cin >> n;
    vector<int> v;
    vector<int> ans;
    vector<vector<int> > result;
    for(int i = 0; i < n; i++){
        int x;
        cin>> x;
        v.push_back(x);
    }
    sort(v.begin(), v.end());
    int x;
    cin >> x;
    rec(0, v, ans, x, n, result);
   
}