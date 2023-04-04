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
        int x = 0;

        while(i<j){
            if(height[i] < height[j]){
                x =  max(x,height[i]*(j-i));
            }else{
                x =  max(x, height[j]*(j-i));
            }
            if(height[i] < height[j]){
                i++;
            }else{
                j--;
            }
        }
        cout << x;

    // int i = 0;
    // int j = n-1;
    // int x = 0;

    // while(i<j){
    //     if(height[i] < height[j]){
    //         int t = height[i]*(j-i);
    //         x =  max(x,t);
    //         cout << t << " " << x<< endl;
    //     }else{
    //         int t= height[j]*(j-i);
    //         x =  max(x, t);
    //         cout << t << " " << x<< endl;
    //     }
    //     cout << "why";
    //     if(height[i] < height[j]){
    //         i++;
    //     }else if(height[i] > height[j]){
    //         j--;
    //     }else{
    //         j--;
    //     }
    // }
    // cout << x;
    
  return 0;
}