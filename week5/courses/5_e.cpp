#include <iostream>
#include <vector>
#include <string>
#include <algorithm>


using namespace std;

bool isAnagram(vector<long long int> a,  vector< long long int> b) {
    long long int n = a.size();
    long long int m = b.size();
    sort(a.begin(), a.begin() + n);
    sort(b.begin(), b.begin() + m);
    if(n < m){
        for(long long int i = 0; i < a.size(); i++){
            if(!includes(b.begin(), b.end(), a.begin(), a.end())) return false;
            else return true;
        }
    }
    if(a==b){
       return true;
    }else{
        return false;
    }
}
void print(vector<long long int> v){
    for (long long int j = 0; j < v.size(); j++){
        cout << v[j] << " ";
    }
    cout << endl;
}

long long int longestSubstr(vector<long long int> s,  vector<long long int> t){
    long long int n = s.size();
        if (n == 0)
            return 0;
        // if (n == 1){
        //     if(isAnagram(s,t)){
        //         return 1;
        //     }
        //     else{
        //         return 0;
        //     }
        // }
        long long  int result = 0;
        for (long long int i = 0; i <= n; i++){
            for (long long int j = 0; j <= n - i; j++){
                vector<long long int> slice(s.begin() + i , s.begin() + j + i);
                print(slice);
                if (isAnagram(slice, t)){
                    if (result < j)
                        result = j;
                }
            }
        }
        return result;
}


int main(){
    string s, t;
   long long int n, m;
    cin >> n;
    vector<long long int> v1;
    vector<long long int> v2;
    for(long long int i =0 ; i< n; i++){
        long long int x;
        cin>>x;
        v1.push_back(x);
    }
    cin >> m;
    for(long long int i =0 ; i< m; i++){
        long long int x;
        cin>>x;
        v2.push_back(x);
    }
    
    long long int ans = longestSubstr(v2, v1);

    cout << ans<<endl;
    return 0;
} 