// #include <iostream>
// #include <vector>

// using namespace std;


// vector<int> prefix_func(string s) {
//     int n = s.size();
//     vector<int> p(n);
//     p[0] = 0;
//     for (int i = 1; i < n; i++) {
//         int j = p[i - 1];
//         while (j > 0 && s[j] != s[i]) 
//             j = p[j - 1];
//         if (s[j] == s[i])
//             j++;
//         p[i] = j;
//     }
//     return p;
// }

// int main() {
//     string s, t;
//     cin >> s ;
//     string s1 = s  +  "#" + t;
//     string s2 = t + s;
//     int max = -100000;
//     vector<int> p = prefix_func(s);
//     vector<int> p1 = prefix_func(s2);
//     for(int i = 0; i < p.size() ; i++){
//         cout << p[i]<< " ";
//     }

        
//     return 0;
// }

#include <iostream>
#include <vector>
using namespace std;


vector<int> prefix_function (string s) {
 int n = (int) s.length();
 vector<int> pi (n);
 for (int i=1; i<n; ++i) {
  int j = pi[i-1];
  while (j > 0 && s[i] != s[j])
   j = pi[j-1];
  if (s[i] == s[j])  ++j;
  pi[i] = j;
 }
 return pi;
}


    
int main(){
  string s = "abcababcbabcabababcaabc";
  vector<int> v = prefix_function(s);
  for(int i = 0; i < v.size(); i++){
   cout << v[i] << " ";
  }
  return 0;
}