#include<iostream>
#include<math.h>

using namespace std;

int main(){
    int n;
    cin >> n;
    int a[n];
    for(int i = 0; i < n; i++ ){
        cin >> a[i];
    }
    for(int i =0 ; i< n-1; i++){
        if(a[i+1] > a[i] ){
            a[i+1] = a[i];
        }
        cout<< a[i]<< endl;
    }
    cout << a[n-1]<< endl;

    return 0;
}