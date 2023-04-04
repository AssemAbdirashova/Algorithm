#include <iostream>
#include <vector>

using namespace std;

bool check(string s, string t){
    int cnt = 0;
    for(int i =0 ; i< s.size(); i++){
        if(s[i] == t[i] && (cnt == 0 || cnt == 1)){
            continue;
        }else{
            cnt++;
        }
    }
    if(cnt > 1){
        return false;
    }else{
        return true;
    }
}

int main() {
    string s, t;
    cin >> t >> s;
    int re = t.size() - s.size();
    if(re > 1){
        cout  << 0;
    }else{
        vector<int> ans1;
        for(int i = 1; i< s.size()-t.size()+1; i++){
            
        
        // cout << s.substr(i,t.size()) << " " << i << endl;
            // if(check(s.substr(i,t.size()), t)){
            //     ans1.push_back(i+1);
            // }
        }
        cout << ans1.size() << endl;
        for(int i = 0; i< ans1.size();i++){
                cout << ans1[i] << " ";
        }
    }
   
        
    return 0;
}