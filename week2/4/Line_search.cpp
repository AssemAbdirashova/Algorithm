#include <iostream>
#include <cmath>

using namespace std;
int main(){
    int x, y; int count = 0, index, min;
 
    cin >> x;
    int mas[101];
    for (int i = 0; i < x; i++) {
        cin >> mas[i];
    }
    cin >> y;
    index = abs(mas[0] - y);
    min = 0;
    for (int i = 1; i < x; i++){
        if (abs(mas[i] - y)<index){ 
            index = abs(mas[i] - y); 
            min = i; 
            }
 
 
    }
    if(mas[min] > y){
    cout << mas[min];
    }
    else {
        cout << mas[min+1];
    }
 
    
    return 0;
}