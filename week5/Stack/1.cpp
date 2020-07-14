#include <iostream>
#include <stack>

using namespace std;
int main(){
  stack <int> st,mx;
  int n;
  cin >> n;
  mx.push(-111);
  int j = 0;
  for(int i =0; i < n;i++){
    string s;
    cin >> s;
    if(s=="add"){
      int x;
      cin >> x;
      st.push(x);
      if(mx.top() <= x){
        mx.push(x);
      }
      
    }
    else if(s=="delete"){
      if(st.empty()){
        cout <<"error"<<endl;
        continue;
      }
      if(st.top() == mx.top()) mx.pop();
       st.pop();

    }
    else if(s == "getmax"){
      if(st.empty()) cout <<"error"<<endl;
      else cout << mx.top()<<endl;
    }
    else if(s == "getcur"){
      if(st.empty()) cout <<"error"<<endl;
      else cout << st.top()<<endl;
    }
  }

}