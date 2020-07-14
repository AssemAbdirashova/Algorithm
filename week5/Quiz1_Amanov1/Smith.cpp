
#include <iostream>
#include <vector>
using namespace std;

int main(){
    int n,k;
    int sum =0;
    int sum2 =0;
    cin  >> n;
    k = n;
    for(int i= 2 ;i<=n;i++){
        while(n%i==0){
            sum+=i;
            n/=i;
        }
    }

    while(k>0){
        
        sum2 = sum2 + k% 10;
        k = k / 10;
    }
    
    if(sum == sum2){
        cout<<1;
    }
    else {
        cout << 0;
    }
    
return 0;

}