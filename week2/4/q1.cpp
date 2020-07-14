#include <iostream>
#include<cmath>

using namespace std;

int sumOfDigits(int n){
    int sum = 0;
    while (n>0){
        sum = sum + n % 10;
        n = n/10;
    }
    return sum;
}

bool isPrime(int n){
    if (n == 2) return true;
    if (n == 3) return true;
    if ((n*n) % 24 == 1) return true;
    return false;
}

int sumOfDividers(int n){
    int sum = 0;
    int i = 2;
    int tmp = n;
    while (i <= n){
        if (n % i == 0){
            if (isPrime(i)){
            sum = sum + sumOfDigits(i);
            } 
            n = n / i;
        }
    else  i++;
    }
    cout << sum << endl;
    return sum;
}

int main(){
    int n;
    cin >> n;
    if (sumOfDigits(n) == sumOfDividers(n))
        cout << 1;
    else cout << 0;
    return 0;
}