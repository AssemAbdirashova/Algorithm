#include<iostream>
#include<math.h>
#include<unordered_set>
#include<vector>
#include<set>

using namespace std;

void print_vector(vector<int> v){ 
    for(int i=0; i<(int)v.size(); i++)
        cout << '\t' << v[i]; 
    cout << "\n"; 
}
void helper(int cost[], int a[], set<vector<int> >& result){
    vector<int> data{a[0],a[1],a[2]};
    
    if(result.find(data) != result.end()){
        return;
    }
    result.insert(data);

    // set<vector<int> >::iterator itr; 
    // for(itr = result.begin(); itr!=result.end(); itr++) 
    //     print_vector(*itr);

    if (a[0] >= cost[0]) {
        int new_сoins[] = {a[0] - cost[0], a[1] + cost[1], a[2]};
        helper(cost, new_сoins, result);
        int new_coins1[] = {a[0] - cost[0], a[1], a[2] + cost[2]};
        helper(cost, new_coins1, result);
    }
    if (a[1] >= cost[1]) {
        int new_сoins[] = {a[0] + cost[0], a[1] - cost[1], a[2]};
        helper(cost, new_сoins, result);
        int new_coins1[] = {a[0], a[1] - cost[1], a[2] + cost[2]};
        helper(cost, new_coins1, result);
    }
    if (a[2] >= cost[2]) {
        int new_сoins[] = {a[0] + cost[0], a[1], a[2] - cost[2]};
        helper(cost, new_сoins, result);
        int new_coins1[] = {a[0], a[1] + cost[1], a[2] - cost[2]};
        helper(cost, new_coins1, result);
    }
}

int backtrace(int cost[], int a[], set<vector<int> >& result){
    helper(cost, a, result);
    return result.size();
}

int main(){
    int cost[3];
    int a[3];
    for(int i = 0; i < 3; i++){
        cin >> cost[i]; 
    }
    for(int i = 0; i < 3; i++){
        cin >> a[i]; 
    }
    set<vector<int> > result;
    cout << backtrace(cost, a , result);

    return 0;
}