#include <iostream>

using namespace std;

int gcd(int a, int b) {
    if( a % b == 0) return b;
    return gcd(b, a % b);
}

int main(){
    int k;
    cin >> k;
    int a,b,c;
    cin>> a>> b >> c;
    int first = (a*b) / gcd(a,b);
    int second = first/a + first/b;

    int third = (first * c) / gcd(first,c);
    int fourth = (third/first) * second + third / c;

    
    int yeap = (k * third) / fourth;

    

    if( k/ fourth * fourth == k ){
        cout << yeap << " " ;
    }
    else {
        int cii = 1;
        int ooo= yeap/third ;
        int oo1 = 
        while( ooo == k / fourth){
            ooo = ooo + cii;
            cii++;
        }
        
        cout << ooo * third;
    }

    

    return 0;
}