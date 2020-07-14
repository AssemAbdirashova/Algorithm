#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;
vector<int> prefix_function(string s){
  int n = s.size();
  vector<int> pr(n);
  pr[0] = 0;
  for( int i = 1; i < n; i++){
    int j = pr[i - 1];
    while(j > 0 && s[j] != s[i])
      j = pr[j - 1];
    if(s[j] == s[i])
      j++;
    pr[i] = j;
  }
  return pr;
}
int main(){
  string s1, s2;
  cin >> s1 >> s2;
  vector<int> p1 = prefix_function(s1 + "#" + s2);
  vector<int> p2 = prefix_function(s2 + "#" + s1);
  cout << max(p1[p1.size() - 1], p2[p2.size() - 1]);
  return 0;
}