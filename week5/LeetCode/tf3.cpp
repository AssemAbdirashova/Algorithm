#include<iostream>
#include<math.h>

using namespace std;

double convert(double degree){
    double pi = 3.14159265359;
    return (degree * (pi / 180));
}

double cot (double a){
	return cos(a)/sin(a);
}

int main(){
    int n;
    cin >> n;
    cout.precision(7);
    double fori = 180/double(n);
    double R = double(1) / (sin(convert(fori)) * double(2));

    if(n  == 3 ){
        double S = sqrt(3)/4;
        cout.precision(6);
        cout << S;
    }else {
        int y = n/3 + 1; // count of edges of 2 diagonal sides of big triangle

        double global_each = 180* (double(n)-2)/double(n);
        double local_all = 180 * (double(y)-2);
       
        double side_diagonal = (local_all - (double((y-2))*global_each)) / double(2);
        double triangle_top_angle = global_each -  side_diagonal * double(2);
        
        double main_angle  = double(180) - triangle_top_angle;
        double third_angle = double(360) - double(2) * main_angle;

        double S_MAX =  R * R * sin(convert(main_angle)); // 2 triangle area in big triangle
        double S_MIN = double(0.5) * R * R * sin(convert(third_angle)); // third triangle area in big triangle



        double trapezoid_edge = double(2) * R * sin(convert(third_angle/double(2)));
        double triangle_bottom = (double(180) - triangle_top_angle)/double(2);
        double trapezoid_angle = global_each - (side_diagonal + triangle_bottom);
        
        double trapezoid_edge2 = trapezoid_edge - double(2) * cos(convert(trapezoid_angle)); // bottom of min triangle

        double min_triangle_angle = global_each - (double(180) - trapezoid_angle);
        double S_TRIANGlE2 = double(0.5) * trapezoid_edge2 * sin(convert(min_triangle_angle)); // area of second triangle

        if(n == 5){
            double S_5edge = double(1.25)*cot(convert(36));
            cout.precision(6);
            cout << S_5edge - ((S_MAX+S_MIN + S_TRIANGlE2) * double(2)) << std::fixed;
        }else{
            cout.precision(7);
            cout << S_MAX+S_MIN + S_TRIANGlE2  << std::fixed;
        }
       
    }
    
    return 0;
}