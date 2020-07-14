#include <iostream>
#include <vector>

using namespace std;

vector<int> get_hash(string s) {
    int n = s.size();
    vector<int> h(n);
    int p = 31;
    int p_pow = 1;
    h[0] = s[0];
    for (int i = 1; i < n; i++) {
        p_pow *= p;
        h[i] = h[i - 1] + s[i] * p_pow;
    }
    return h;
}

int main() {
    int n;
    cin >> n;
    string t[n];
    for(int i = 0; i< n;i++){
        cin >> t[i];
    }
    string s;
    cin >> s ;
    int cnt[n];
    for(int i = 0; i < n; i++){
        string patt;
        
        int n = s.size();
        int m = t[i].size();
        int p[n];
        p[0] = 1;
        
        for (int j  = 1; j < n; j++)
            p[j] = p[j - 1] * 31;
        int h_t = get_hash(t[i])[m - 1];
        vector<int> h_s = get_hash(s);
        for (int j = 0; j < n - m + 1; j++) {
            int k = j + m - 1;
            int hash_i_j = h_s[k];
            if (j > 0)
                hash_i_j = hash_i_j - h_s[j - 1];
            if (hash_i_j == h_t * p[j]) {
                //cout << i << " ";
                cnt[i]++;
            }
        } 
        
    }
    for(int i = 1;i < n ; i++){
        cout << cnt[i] << " ";
    }
    
    return 0;
}