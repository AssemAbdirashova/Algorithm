#include <iostream>
#include <vector>


using namespace std;

vector<int> prefix_func(string s) {
    int n = s.size();
    vector<int> p(n);
    p[0] = 0;
    for (int i = 1; i < n; i++) {
        int j = p[i - 1];
        while (j > 0 && s[j] != s[i]) 
            j = p[j - 1];
        if (s[j] == s[i]) j++;
        p[i] = j;
    }

    return p;
}


int main(){
     string t, s;
     cin >> t >> s;
     string s1 = t + s ;
     string s2 = s + t;
     vector<int> p = prefix_func(s1);
     vector<int> p2 = prefix_func(s2);
     int maxx = max(p[s1.size() - 1], p2[s2.size() - 1]);
     cout << maxx;
    
     return 0;
}