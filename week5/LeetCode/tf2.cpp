#include<iostream>
#include<vector>
#include<math.h>

using namespace std;

vector<int> findPrimeFactors(int n){
    vector<int> check;
    for (int i = 3; i <= sqrt(n); i = i + 2){
        while (n % i == 0){ 
            check.push_back(i);
            n = n/i; 
        } 
    }
    if (n > 2) {
        check.push_back(n);
    }
    return check;
}

int main(){
    int n;
    cin >> n;
    
    if(n % 2 == 0){
        cout << n/2 << " " << n/2;
    }
    else {
        vector<int> div = findPrimeFactors(n) ;
        int x = div[0];
        int y = 1;
        for(int i = 1; i < div.size(); i++){
            y = y * div[i];
        }
        int ans = (x - 1) * y;
        cout << y << " " << ans ;
    }
    
    return 0;
}