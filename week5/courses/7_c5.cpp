#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>  
using namespace std;

vector<unsigned long long int> fib1(){
    vector<unsigned long long int> v;
    int i;
    v.push_back(1);
    v.push_back(1);
    for(i = 2; i <= 70 ; i++){
        v.push_back(v[i - 1] + v[i - 2]);
    }
    reverse(v.begin(), v.end());
    return  v;
};


void backtraking(unsigned long long int n, unsigned long long int s, vector<unsigned long long int>& c, vector<vector<unsigned long long int>>& ans, vector<unsigned long long int>& fib) {
    for (unsigned long long int i = s; i <= sqrt(n); i++) {
        if (n % i == 0) {
          //cout << i << " " << "\n";
            //if(find(fib.begin(), fib.end(), i) != fib.end()){ //&& find(fib.begin(), fib.end(), n/i) != fib.end()){
              c.push_back(i);
              c.push_back(n / i);
              ans.push_back(c);
              c.pop_back();
              backtraking(n / i, i, c, ans, fib);
              c.pop_back();
            //}
        }
    }
}
vector<vector<unsigned long long int>> getFactors(unsigned long long int n, vector<unsigned long long int>& fib) {
        vector<vector<unsigned long long int>> ans;
        vector<unsigned long long int> c;
        backtraking(n, 2, c, ans, fib);
        return ans;
}
int main(){
  unsigned long long int x; 
  cin>> x;
  vector<unsigned long long int> fib = fib1();
  vector<vector<unsigned long long int>> ans;
  vector<unsigned long long int> result;

  for(unsigned long long int i = 0 ; i < x; i++){
    unsigned long long int n;
    cin>>n;
    ans = getFactors(n, fib);
    unsigned long long int cnt = 0;
    unsigned long long int answer = 0;
    if(ans.empty()){
      if(find(fib.begin(), fib.end(), n) != fib.end()){
        result.push_back(1);
      }else{
        result.push_back(0);
      }
    }else{
      for(unsigned long long int i = 0; i < ans.size(); i++){
        for(unsigned long long int j = 0; j < ans[i].size(); j++){
            if(find(fib.begin(), fib.end(), ans[i][j]) != fib.end()){
              cnt++;
            }
        }
        if(cnt == ans[i].size()){
          answer += 1;
        }
        cnt = 0;
      }
      if(find(fib.begin(), fib.end(), n) != fib.end()){
        result.push_back(answer + 1);
      }else{
        result.push_back(answer);
      }
    }
  }
  for(unsigned long long int i = 0; i < x; i++){
    cout << result[i] << "\n";
  }
  return 0;
}