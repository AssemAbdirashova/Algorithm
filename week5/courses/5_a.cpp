#include <iostream>
#include <stack>
#include <vector>
 
using namespace std;

int main(){

    string s;
    cin >> s;
    int n;
    cin >> n;
    vector<bool> v;
    vector<string> v1;
    for(int i = 0; i< n;i++){
        int a, b, c, d;
        cin >> a >> b >> c >> d;
        if(s.substr(a-1, b-a+1) == s.substr(c-1, d-c+1) ){
            v.push_back(true);
        }else{
            v.push_back(false);
        }
    }
    for(int i = 0; i< n;i++){
        if(v[i] == true){
            cout << "Yes" << endl;
        }else cout << "No" << endl;
    }
    return 0;
}