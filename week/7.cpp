#include <iostream>

using namespace std;

bool isPalindrome(int x) {
        int y = 0;
        int r = x;

        if(x < 0){
            x = x*(-1);
        }
        while(x/10 != 0 ){
            int z = x% 10;
            // if(z==0 && x/10 != 1){
            //    y = y*10; 
            // }
            y = y*10 + z;
            x = x/10;
             cout<<y<<"  "<<"  x "  << x<<"  ";
        }
         y= y*10+x;
        cout<<y<<"  ";
        if(r == y){
            return true;
        }else {return false;
       
               }
    }

int main() {
    int a = 10;
    cout << isPalindrome(a);
    return 0;
}