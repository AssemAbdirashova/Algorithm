#include <iostream> 
#include <string>
using namespace std;
 
struct stack{
    int storage[100000];
    int start;
    
    stack(){
        start = 0;
    
    }
 
    void push(int n){
        storage[start] = n;
        start++;
    }
 
    int pop(){
        int a = storage[start-1];
        start--;
        return a;
    }
 
    int back(){
        int b = storage[start-1];
        return b;
    }
 
    int size(){
        return  (start);
    }
 
    string clear(){
      //  previous = 0;
        start = 0;
        return "ok";
    }
 
    string exit(){
        return "bye";
    }
};
 
int main() {
    string a;
    stack x;
    while(cin >> a){
        if(a == "push"){
            int n;
            cin >> n;
            x.push(n);
            cout << "ok" << endl;
        }
        if(a == "pop"){
            cout << x.pop() << endl;
        }
        if(a == "back"){
            cout << x.back() << endl;
        }
        if(a == "size"){
            cout << x.size() << endl;
        }
        if(a == "clear"){
            cout << x.clear() << endl;
        }
        if(a == "exit"){
            cout << x.exit() << endl;
            return 0;
        }
    }
    return 0;
}