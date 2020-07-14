#include <iostream>

using namespace std;
int main()
{
  int T;
  cin >> T;
  for( int qwe = 1; qwe <= T; qwe++)
  {
    int a[111111];
    int sum[111111];
    
    for( int i = 0; i <= 100000; i++)
    {
      sum[i] = 0;
      a[i] = 0;
    }
    int n;
    bool ok = false;  
    cin >> n;
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
  }
  return 0;
}