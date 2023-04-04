#include<iostream>
#include<vector>
#include<unordered_map>

using namespace std;

int main(){
    int n, k;
    cin >> n >> k;
    bool ok =false;
    int a[n];
    vector<int> res;
    int sum = 0;
    for(int i= 0; i< n;i++){
        cin >> a[i];
    }

    // for (int i = 0; i < n; i++) {
    //     int sum = a[i];
    //     for (int j = i+1; j < n; j++) {
    //         sum = sum + a[j];
    //         if(sum % k == 0){
    //             ok = true;
    //         }
    //         cout << sum << " ";
    //     }
    // }
    unordered_map<int, int> m;
     for (int i = 0; i < n; i++) {
            sum = sum + a[i];
            if(sum % k == 0 && a[i] != 0){
                cout << "check";
            }
            int y = sum% k;
            if(!m.count(sum%k) ){
                m[sum%k] = i;
            }
            else{
                cout<< "hereoooo";
            }
        }
       cout<< "here";
  return 0;
}   