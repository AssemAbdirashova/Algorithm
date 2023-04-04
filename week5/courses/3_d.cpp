#include <iostream>
#include <stack>
#include <deque>
 
using namespace std;
class MyDeque{
public:
    deque<int> dq;
    MyDeque(){}
    void push_back(int val){
        dq.push_back(val);
    }
    void insert_middle(int val){
        int mid = dq.size() /2;
        if(dq.size() % 2 != 0){
            mid = mid+1;
        }
        auto it = dq.begin() + mid;
        dq.insert(it, val);
    }
    int pop_front(){
        int val = dq.front();
        dq.pop_front();
        return val;
    }
};

int main() {
    int n;
    cin >> n;

    MyDeque dq;
    // dq.push_back(5);
    // dq.push_back(2);
    // dq.push_back(3);
    // dq.push_back(1);
    // dq.push_back(9);
    // dq.insert_middle(17);
    // cout << dq.pop_front();
    // cout << dq.pop_front();
    // cout << dq.pop_front();
    // cout << dq.pop_front();
    // cout << dq.pop_front();

    for(int i = 0 ; i< n; i++){
        char x;
        cin >> x;
        if(x == '+'){
            int val;
            cin >> val;
            dq.push_back(val);
        }else if(x == '*'){
            int val;
            cin >> val;
            dq.insert_middle(val);
        }else{
            cout << dq.pop_front() << endl;
        }
    }

    return 0;
}