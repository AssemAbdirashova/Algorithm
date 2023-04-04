#include <iostream>
using namespace std;

void f1(int n){
    if(n < 0){
        return;
    }
    cout << "Before function ends ";
    cout << n << endl;
    f1(n-1);
}
void f(int i, int n){
    if(i > n){
        return;
    }
    f(i+1, n);
    cout << "After function ends ";
    cout << i << endl;
}
void x(int i, int n){
    if(i < 0){
        return;
    }
    x(i-1, n);
    cout << "After function ends ";
    cout << i << endl;
}
int sumf(int n){
    if(n < 0){
        return 0;
    }
    return  n + sumf(n-1); // bactrace

}
void sump(int n, int sum){
    if(n < 0){
        cout << sum;
        return;
    }
    sump(n-1, sum+n); // simple parametrized

}


int main(){
    x(3, 3);
    f(0, 3);
    cout << sumf(4) << endl;
    sump(4, 0);
    return 0;
}