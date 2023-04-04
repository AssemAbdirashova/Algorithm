#include<iostream>
#include<math.h>
#include <algorithm> 
#include<vector>
using namespace std;

int partion(int n){
    if(n < 5){
        return -1;
    }
    double sum = double(n) * (double(n+1)) / double(2);
    int summ = floor(sum);
    if(summ % 3 != 0){
        return -1;
    }
    summ = sum/3;
    vector<int> a;
    int x = 2;
    while(x> 0){
        int s_cur = summ;
        while(s_cur > 0){
            int maxx = upper_bound(1, s_cur) -1;
            a.push_back(maxx+1)
            s_cur -= maxx+1;
            
        }


        x--;
    }
}


int main(){
    int n;
    cin >> n;
   
    return 0;
}