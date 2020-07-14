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
        if(p[i] == 0 && n%i ==0){
         // cout <<  i <<" ";
          cnt++;
        }
       
    }

    /*for(int i = 2 ; i<= n;i++){
        if(n%y[i] == 0){
            cnt++;
        }
    }*/
    cout<< cnt;
    return 0;
}