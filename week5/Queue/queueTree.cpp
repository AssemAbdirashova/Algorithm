#include <iostream>
#include <queue>
using namespace std;
int main()
{
  queue <int> q;
  int t;
  int c = 0;
  cin >> t;
  for( int i = 1; i <= t; i++)
  {
    int a, b;
    cin >> a;
    if(a == 1)
    {
      cin >> b;
      q.push(b);
    }
    else if(a == 2)
    {
      cin >> b;
      c += b;
    }
    else
    {
      while(q.size() > 0 && q.front() <= c)
        q.pop();
      if(q.size() > 0)
      {
        cout << q.front() << endl;
      }
      else
      {
        cout << -1 << endl;
      }
    }
  }
}