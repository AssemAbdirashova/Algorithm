#include <iostream>

using namespace std;
int p[10000002];
int main(){
    int n ;
    int cnt = 0;
    cin >> n;
    for(int i = 2 ; i * i <= n; i++ ){
        if(p[i]  == 0 ){
            int k = i;
            while( k + i <= n){
                k += i;
                p[k] = 1;
                
            }
        }

    }
    int y[100000];
    for(int i = 2 ; i <= n; i++){
        if(p[i] == 0 ){
         y[i] = i;
          
        }
       
    }
    int a,b;
    for(int i = 2 ; i<= n;i++){
        if(y[i] != 0){
            for( int j = 2 ; j<= n;j++){
                if(y[i] + y[j] == n){
                    a= y[i];
                    b = y[j];
                    break;

                }
            }
        }
    }
    if(a<b){
        cout << a << " " << b;
    }
    else {
        cout << b << " " << a;
    }
    return 0;
}