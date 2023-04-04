#include <iostream>
#include <vector>

using namespace std;

long long int countSubstrings(string s) {
    long long int count = 0;
    for(int i = 0; i < s.size(); i++) {
      // odd
      long long int l = i, r = i;
      while(l >= 0 && r < s.size() && s[r] == s[l]) {
        count++; l--; r++;
      }
      // even
        l = i, r = i+1;
      while(l >= 0 && r < s.size() && s[r] == s[l]) {
        count++; l--; r++;
      }
    }
    return count;
}

int main(){
    string s;
    cin >> s;
    cout << countSubstrings(s);
    return 0;
}