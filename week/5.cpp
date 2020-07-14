#include <iostream>

using namespace std;

int main() {
    int n, k;
    cin >> n ;
    bool  ok = true;
    int a[n];
    for (int i = 0; i < n; i++){
        cin >> a[i];
    }
    cin >> k;


    for(int i = 0 ; i<n ;i++){
       if(k == a[i]){
        
         ok = false;
        break;
       }
       //
    }
    if(!ok){
        cout<< "Yes";
    }
    else{
        cout <<"No";
    }
    return 0;
}