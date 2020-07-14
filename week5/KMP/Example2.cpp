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

int main() {
    
    
     string s1;
     cin >> s1;
     string t;
     int n;
     cin >> n;
     string s[n];
     int i = 0;
     string maxstr[n];
     int max = -1;
     while(i< n){
        cin >> t;
        string d = s1 + t;
        int index;
        vector<int> p = prefix_func(d);
        for(int j = 0; j< p.size(); j++){
            if(max < p[j]){
                max = p[j];
                maxstr[i] = t;
            }
            else if(max == p[j] && max!= 0){
                 maxstr[i+1] = t;
            }
        }
        d = "";
        p.clear();
        i++;
    }
    for(int i = 0; i<n;i++){
        cout << maxstr[i];
    }
    //  string s = s1 + s2;
    //  string t = s2 + s1;
    //  vector<int> p = prefix_func(s);
    //  vector<int> p2 = prefix_func(t);
    //  int maxi = max(p[s.size() - 1], p2[t.size() - 1]);
    //  cout << maxi;
    //  return 0;
    
        // for(int k = index ; k > index - max;k++ ){
            
        // }
}
