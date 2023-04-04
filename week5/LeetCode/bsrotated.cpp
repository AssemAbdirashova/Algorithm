#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;



int main() {
    int n, k;
	cin >> n >> k;
    int a[n];
    for(int i = 0; i< n; i++){
        cin >> a[i];
    }
    // 3 4 5 6 0 1 2
    // 0 1 2 3 4 5 6

    // l = 0; r = 6
    // med = 3

    int l = 0;
    int r = n-1;
    int answer = 0;
    while(l<=r){
        int mid = (l+r)/2;
        if(a[mid] == k){
            answer = mid;
            break;
        }    
        if(k < a[mid]){
            if(k < a[l]){
                l = mid + 1;
            }
            else{
                r = mid - 1;
            }
        }
        if(k > a[mid]){
            if(k > a[r]){
                r = mid - 1;
            }
            else{ 
                l = mid + 1;
            }
        }
    }
    cout<< answer;
    return 0;
}