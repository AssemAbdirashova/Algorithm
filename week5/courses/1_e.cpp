#include<iostream>
#include<vector>
#include<math.h>

using namespace std;

double func(double n, double m, double k, double l , double x1){
    double y = x1*x1*x1*n + m*x1*x1 + k*x1 + l;
    return y;
}

int main(){
    double n, m,k, l;
    cin >> n;
    cin >> m;
    cin >> k>> l;
    
    int a = 3* n;
    int b = 2 * m;
    int c = k;

    double x1, x2, discriminant, realPart, imaginaryPart;
    discriminant = b*b - 4*a*c;
    
    if (discriminant > 0) {
        x1 = (-b + sqrt(discriminant)) / (2*a);
        x2 = (-b - sqrt(discriminant)) / (2*a);
        cout << "Roots are real and different." << endl;
        cout << "x1 = " << x1 << endl;
        cout << "x2 = " << x2 << endl;
    }
    else if (discriminant == 0) {
        cout << "Roots are real and same." << endl;
        x1 = -b/(2*a);
        cout << "x1 = x2 =" << x1 << endl;
    }
    else {
        realPart = -b/(2*a);
        imaginaryPart =sqrt(-discriminant)/(2*a);
        cout << "Roots are complex and different."  << endl;
        cout << "x1 = " << realPart << "+" << imaginaryPart << "i" << endl;
        cout << "x2 = " << realPart << "-" << imaginaryPart << "i" << endl;
    }
    
    double res1 = x1*x1*x1*n + m*x1*x1 + k*x1 + l;
    double res2 = x2*x2*x2*n + m*x2*x2 + k*x2 + l;

    double minx = 0;
    double xx = 0;

    if(res1 < res2){
        xx = x1;
        minx = res1;
    }else{
        xx = x2;
        minx = res2;
    }
    double r = xx;
    double t;
    while(true){
        t = func(n, m, k, l, r);
        if(t>=1){
            break;
        }
        r+=1;
    }
    double left = xx;
    double right = r;
    double mid;
    double ans;
    while (left <= right) {
        mid = left + (right - left) / 2;
        ans = func(n, m, k, l, mid);
        cout << left << " " << ans << " " << right;
        if (ans >= -0.001 && ans <= 0.001) {
            cout << mid << endl;
            break;
        }
        if (ans < 0.1)
            left = mid + 1;
        else
            right = mid - 1;
    }
    cout << "NA";
    // while(r > xx){
    //     double check =func(n, m,k, l, r);
    //     cout<< r<< " " << check <<endl;
    //     if(check < -0.001){
    //         reun = check;
    //         cout << "nhg";
    //         break;
    //     }
    //     r = r/2;
    // }
    
    return 0;
}