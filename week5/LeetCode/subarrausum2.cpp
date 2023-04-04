#include<iostream>
#include<vector>
#include<queue>

using namespace std;


int main(){
    int n,target;
    cin >> n;
    cin >> target;
    int a[n];
    int sum = 0;
    for(int i = 0; i< n; i++){
        cin>> a[i];
    }
    int ans = INT_MAX;
    vector<int> check(n); 
    check[0] = a[0];
    for(int i = 1; i<n; i++){
        check[i] = check[i-1] + a[i];
    }
    for(int i = 0; i<n; i++){
        cout << i << endl;
        for(int j = i; j< n; j++){
            int sum = check[j] - check[i] + a[i];
            cout<< sum;
            cout<< " " << (j-i + 1) << " ";
            if(sum >= target ){
                ans = min(ans, (j-i + 1));
                //break;
            }
            cout << ans;
            cout << endl;
        }
        cout << endl;
    }
    cout << endl;
    int x  = (ans!= INT_MAX) ? ans :  0;
    cout << x;

    return 0;
}