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
    //vector<int> check; 
    for(int i = 0; i<n; i++){
        cout << i << endl;
        check[i] = a[i];
        for(int j = i; j< n; j++){
            cout << j << endl;
            sum = 0;
            for(int k = i; k <= j; k++){
               // check[i] = check[i] + a[k];
                 sum += a[k];
            }
            cout << a[i] << "  ";
            cout << a[j] << "  ";
            cout << sum << " ";
            cout << endl;
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