#include<iostream>
#include<math.h>

using namespace std;
int cnt(int n){
    int cnt = 0;
    if(n ==1){
        return 1;
    }
    for(int i = n; i > sqrt(n); i-- ){
        if(n % i == 0){
            cnt +=2;
        }
    }
    return cnt;
}
int main(){
    int n;
    cin >> n;
    int maxx = 0;
    int x = 0;
    for(int i =1 ; i< n+1; i++){
        if(cnt(i) >= maxx){
            maxx = cnt(i);
            x = i;
        }
    }
    cout << x << endl  << maxx;
    return 0;
}