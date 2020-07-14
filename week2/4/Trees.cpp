#include <iostream>
#include <queue>

using namespace std;

int main(){
    queue<int> q;
    int n;
    cin >> n;
    
    int count = 0;
    for(int i = 0; i<n; i++){
        int a, b ;
        cin >> a;
        if(a == 1 ){
            cin >> b;
            q.push(b);
        }
        else if(a==2){
            cin >> b;
            count += b;
        }
        else{
            
            while(q.size() > 0 && q.front() <= count){
                q.pop();      
            }
            if(q.size()>0){
                cout << q.front();
            }
            else{
                cout << -1;
            }
            
        }
    }
    return 0;
}