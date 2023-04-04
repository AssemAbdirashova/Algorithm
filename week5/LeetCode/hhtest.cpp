#include<iostream>
#include<vector>
#include<queue>

using namespace std;

int main(){
    queue<int> q;
    queue<int> q1;
    int n, m,s;
    cin >> n;
    cin >> m;
    cin >> s;
    //  vector<int> res;
    for(int i= 0; i< n;i++){
        int a;
        cin >> a;
        q.push(a);
    }
    for(int i= 0; i< m;i++){
        int b;
        cin >> b;
        q1.push(b);
    }
    int cnt;
    cnt = 0;
    int sum =0;
    while(sum < s && (!q.empty() || !q1.empty())){
        if(q.empty() || (!q.empty() && !q1.empty() && q.front() >= q1.front())    ) {
            sum = sum + q1.front();
            cnt++;
            q1.pop();  
        }else if(q1.empty() || (!q.empty() && !q1.empty() && q.front() < q1.front()) ){
            sum = sum + q.front();
            cnt++;
            q.pop();      
           
        } 
        // else if(q.front() < q1.front()){
        //     if(sum + q.front() < s){
        //         sum = sum + q.front();
        //         cnt++;
        //         q.pop();
        //     } else{
        //         break;
        //     }
        // } else{
        //     if(sum + q1.front() < s){
        //         sum = sum + q1.front();
        //         cnt++;
        //         q1.pop();
        //     } else{
        //         break;
        //     }
        // }
    }
    cout<< cnt-1 << " " << sum; 
  return 0;
}