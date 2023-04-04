#include <iostream>
#include <vector> 
#include <stack> 
#include <queue> 
#include <algorithm>
#include <climits>
using namespace std;


void nxtsml(vector<long long int>& nums,vector<long long int>&nsl){
    stack<int>s;
    for(int i=0;i<nums.size();i++){
        while(!s.empty() && nums[s.top()]>=nums[i]){
            s.pop();
        }
        if(s.empty()){
            nsl[i]=-1;
        }else{
            nsl[i]=s.top();
        }
        s.push(i);
    }
}
void nxtsmr(vector<long long int>& nums,vector<long long int>&nsr){
    long long int mod = 1e9 + 7;
    stack<int>s;
    for(int i=nums.size()-1;i>=0;i--){
        while(!s.empty() && nums[s.top()]>=nums[i]){
            s.pop();
        }
        if(s.empty()){
            nsr[i]=nums.size();
        }else{
            nsr[i]=s.top();
        }
        s.push(i);
    }
}

int main(){
    int n;
    cin >> n;
    vector<long long int> v;
    for(int i = 0; i < n; i++){
        int x;
        cin>> x;
        v.push_back(x);
    }
    long long int maxx=INT_MIN;

   
    vector<long long int>nsl(n);
    vector<long long int>nsr(n);
    nxtsml(v,nsl);
    nxtsmr(v,nsr);
    vector<long long int>prefixSum(n+1,0);
    for(int i=n-1;i>=0;i--){
        prefixSum[i]=v[i]+prefixSum[i+1];
    }
    for(int i=0;i<v.size();i++){
        maxx = max(maxx, (prefixSum[nsl[i]+1]-prefixSum[nsr[i]])*v[i]);
    }
    // while(i < ans.size()){
    //     int sum = 0;
    //     sum += prefixSum[res[i] - 1];
    //     if(ans[i] >= 0){
    //         sum -= prefixSum[ans[i]];
    //     }
    //     sum *= v[i];
    //     maxx = max(maxx, sum);
    //     i++;
    // }
    cout << maxx << " ";

}