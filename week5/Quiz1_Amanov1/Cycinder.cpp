#include <iostream>
#include <vector>
#include <stack>
using namespace std;

int main(){
    int n,m,k,r;

    cin >> n >> m>> k;
    int a[n],b[m],c[k];
    stack<int> s1,s2,s3;
    int sum1 = 0;
    int sum2 = 0;
    int sum3 = 0;
    
    for(int i = 0 ; i < n ; i++){
        cin >>a[i];
        s1.push(a[i]);
        sum1 += a[i];
    }
   

    for(int i = 0 ; i < m ; i++){
        cin >>b[i];
        s2.push(b[i]);
        sum2 += b[i];
    }
    for(int i = m-1; i >= 0 ; i--){
        s2.push(b[i]);
    }
    for(int i = 0 ; i < k ; i++){
        cin >>c[i];
        s3.push(c[i]);
        sum3 += c[i];
    }
    for(int i = k-1; i >= 0 ; i--){
        s3.push(c[i]);
    }
     for(int i = n-1; i >= 0 ; i--){
        s1.push(a[i]);
    }
    
    while(sum1 != sum2){
        if(sum1> sum2){
        sum1 = sum1 -s1.top();
        s1.pop();
        }
        else{
        sum2 = sum2- s2.top();
        s2.pop();
        }
        
    }


    while(sum2 != sum3){
        if(sum3> sum2){
            sum3= sum3 - s3.top();
            s3.pop();
        }
        else{
            sum2 = sum2- s2.top();
            s2.pop();
        }
    }
    while(sum1 != sum2){
        if(sum1> sum2){
        sum1 = sum1 -s1.top();
        s1.pop();
        }
        else{
        sum2 = sum2- s2.top();
        s2.pop();
        }
        
    }
    cout << sum1;

return 0;

}