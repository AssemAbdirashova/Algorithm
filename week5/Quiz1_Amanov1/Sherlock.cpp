#define _GLIBCXX_DEBUG
#include <iostream>
#include <vector>
using namespace std;

int main(){
     int n;
    bool ok = false;  
    cin >> n;
    int a[n];
    int sum[n];
    for( int i = 1; i <= n; i++)
    {
      cin >> a[i];
      sum[i] = sum[i - 1] + a[i];
    }
    for( int i = 1; i <= n; i++)
      if(sum[i - 1] - sum[0] == sum[n] - sum[i])
        ok = true;
    
    if(ok == true)
      cout << "YES\n";
    else
      cout << "NO\n";
      return 0;
  }





//     int n;
//     cin >> n;
    
//     for(int i=0;i<n;i++){
//         cin >> a[i];
//     }
//     int left=0;
//     int right = n-1;
    
//     int sum = 0;
//     int sum1 = 0;
//     int cur = 0;
    
//     for(int i = 0; i < cur ; i++){
//         sum += a[i];
//     }
//     for(int i = cur; i < n ; i++){
//         sum1 += a[i];
//     }
    
// return 0;
//}