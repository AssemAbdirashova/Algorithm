#define _GLIBCXX_DEBUG
#include <iostream>
#include <vector>
using namespace std;

int main(){
    int n;
    cin >> n;
    
    int x;
    cin >> x;
    
    int y[n];
    long long int sum = 0;
    for(int i= 0; i<n ;i++){
        cin >> y[i];
    }
    for(int i = 0 ; i< n;i++){
        
        while(x!=0 && x > y[i]){
            sum = sum + y[i]*y[i];
            x = x - y[i];
            i++;
        }
        if(x < y[i]){
        sum = sum + x*y[i];
        break;
        }
        //
        
        
    }
    
    cout << sum;
    
    return 0;

}