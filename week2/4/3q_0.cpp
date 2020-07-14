#include<iostream>

using namespace std;

bool findElement(int arr[], int n) 
{   bool ok = false;
   
    int prefixSum[n]; 
    prefixSum[0] = arr[0]; 
    for (int i = 1; i < n; i++) 
        prefixSum[i] = prefixSum[i - 1] + arr[i]; 
  
   
    int suffixSum[n]; 
    suffixSum[n - 1] = arr[n - 1]; 
    for (int i = n - 2; i >= 0; i--) 
        suffixSum[i] = suffixSum[i + 1] + arr[i]; 
  
    
    for (int i = 1; i < n - 1; i++) 
        if (prefixSum[i] == suffixSum[i]) 
            ok = true; 
    return ok;
} 

int main(){
    int T;
    int n;
    cin >> T;
    for (int i = 0; i < T; i++){
        cin >> n;
        int a[n];
        int sum[10000];
        for (int j = 0; j < n; j++){
            cin >> a[j];
            if ( j == n-1){
                if (findElement(a,n)){
                    cout << "YES";
                }
                else cout << "NO";
            }
        }
    }
    return 0;
}
