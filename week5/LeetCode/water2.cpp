#include<iostream>
#include<vector>

using namespace std;

int main(){
    int n;
    cin >> n;
    int height[n];
    for(int i= 0; i< n;i++){
        cin >> height[i];
    }
    int i = 0;
    int j = n-1;
    int check = 0;
    vector<int> reach;
    int sum = 0; 
    int lx = height[i];
    int rx = height[j];
    int x = 0;

    while(x < n-1){
        lx = min(lx, height[i]);
        rx = max(rx, height[j]);
        i++;
        j--;

        x++;
    }
    cout << check << " " << i;
    
  return 0;
}