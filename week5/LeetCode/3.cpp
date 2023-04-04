#include<iostream>
#include<vector>
#include<cstring>

using namespace std;

int main(){
    string s;
    getline(cin, s); 
    bool ok = false;
    int length = s.size();
    int r = length - 1;
    int l = 0;
    cout<< length<< endl;
    while( l < r){
        while((!isdigit(s[l]) || !isalpha(s[l])) && l<r ){
            l++;
        }
        while((!isdigit(s[r]) || !isalpha(s[r])) && r> l){
            r--;
        }
        if(tolower(s[l]) == tolower(s[r])){
            l++;
            r--;
            cout<< s[l] << "good";
        }else{
            cout << s[l]<< " "<< l<< endl;
            cout << s[r] << " " << r << endl;
        }
    }
return 0;
}

// (!isdigit(s[l]) || !isalpha(s[l]))

