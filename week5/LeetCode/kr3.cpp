#include<iostream>
#include<math.h>

using namespace std;

int main(){
    string s;
    cin >> s;
    int r = 0;
    int c = 0;
    for(int i = 0; i < s.size(); i++){
        if(s[i] == '0'){
            cout << 1 << " " << c+1<< endl;
            r++;
            c++;
            if(r == 4){
                r =0 ;
            }
            if(c == 2){
                c= 0;
            }
        }else{
            cout << r << " " << c+1<< endl;
            c +=2;
            r++;
            if(r == 4){
                r =0 ;
            }
            if(c == 2){
                c= 0;
            }
        }

    }
    return 0;
}