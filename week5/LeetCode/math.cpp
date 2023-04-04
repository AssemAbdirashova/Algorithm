#include<iostream>
#include<math.h>

using namespace std;

int mode4(int x){
    if(x < 0){
        return x*(-1);
    }
    return x;
}
int main(){
    int y;
    int x;
    int a = 139;
    bool ok = false;
    while(a < 100000){

        for(int i = -100; i< 100000; i++){
            for(int j = -100; j < 100000; j++){
                int t = i+2;
                int u = j+9;
                int r = mode4(t);
                int e = mode4(u);
                int ans = ( r + e - 2)*(i*i + j*j - 3);
                int ans2 = i*i + 4*i + j*j + 8*j + 20;
                if(ans == 0 &&  ans2 == a){
                    ok = true;
                    cout << "a: " << a << " ";
                    cout << "x: " << i << " ";
                    cout << "y: " << j << " ";
                    
                }
            }
        }
        cout << a << endl;
        a++;
    }



    return 0;
}