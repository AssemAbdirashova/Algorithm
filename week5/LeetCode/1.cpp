#include<iostream>
#include<vector>

using namespace std;

int main(){
    int n, target;
    cin >> n;
    int a[n];
    cin >> target;
    vector<int> res;
    for(int i= 0; i< n;i++){
        cin >> a[i];
    }
    for(int i = 0; i < n; i++){      
        for(int j = i+1; j < n; j++){
            if(a[i] + a[j] == target){
                res.push_back(i);
                res.push_back(j);
            }
        }
    }
    for(int i =0; i<res.size(); i++){
        cout << res[i] << " ";
    }
  return 0;
}