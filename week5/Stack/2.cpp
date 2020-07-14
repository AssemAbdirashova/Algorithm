#include <iostream>
#include<vector>
#include <algorithm>


using namespace std;
int main(){
    int n;
    cin>>n;
    int sum = 0;
    vector<int> v;
    for (int i = 0; i < n; i++)
    {
        int x;
        cin>>x;
        v.push_back(x);
    }
    sort(v.begin(), v.end());
    for(int i =1 ; i< n; i++){
        sum = sum + (v[i] + v[0]);
    }
    cout << sum;
    
    return 0;
    
}