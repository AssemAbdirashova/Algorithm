#include <iostream>
#include <queue>
#include <vector>
using namespace std;
int main(){
    string s;
    cin>> s;
    int start = 0;
    int end = start + 1;
    int max = 1;
    vector<int> ans;
    ans.push_back(1);
    while(end!= s.size()){
        if(s[start] != s[end]){
            cout<< "первое условие" << s[start] << " " << s[end] << endl;
            max = max+1;
            cout<< max<< endl;
        }else{
            ans.push_back(max);
            cout<< "второе условие" << s[start] << " " << s[end] << endl;
            start = end;
            max= 0;
        }
        end++;
    }
    int res = 0;
    for(int i = 0; i< ans.size()-1; i++){
          cout << "f"<< ans[i] << endl;
        if(res < ans[i]){
            res = ans[i];
            cout << ans[i] << endl;
        }
    }
    cout<< endl << res;
    return 0;
}