#include<iostream>
#include<vector>

using namespace std;

int main(){
    vector<int> v;
    int x;
    cin >> x;
    int result = 0;
    while(x/10 != 0){
        result = x % 10;
        v.push_back(result);
        x = x / 10;
    }
     
    int last = x % 10;
    v.push_back(last);
    if(x<0){
        cout << "false";
    }
    else{
        for(int i = 0; i< v.size(); i++){
            if(v[i] == v[v.size() - i - 1]){
                cout << "true";
            }
            else{
                cout<<"bad";
                break;
                
            }
        }

    }
    
  return 0;
}