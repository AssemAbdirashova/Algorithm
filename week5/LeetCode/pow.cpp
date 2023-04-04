#include<iostream>
#include<vector>
#include<queue>

using namespace std;
double myPow(double x, int n) {
    if(n == 1 ){
        return double(x);
    }   
    else{
        return double(x) * myPow(x, n-1);
    }
}

int main(){
    int n = 10;
    int x = 2;
    cout << myPow(x,n);
    return 0;
}