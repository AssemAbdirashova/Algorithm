#include<iostream>
#include<math.h>

using namespace std;

int main(){
    int n;
    cin >> n;
    if(n % 3 == 0){
        cout <<  pow(2,n/3);
    }else{
        cout << 0;
    }

    return 0;
}