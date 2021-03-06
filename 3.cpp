#include <iostream>

using namespace std;

struct myqueue{
    private:
        int a[100];
        int last;
        int first;
    public:
        myqueue(){
            last = 0;
            first = 0;
        }
        void enqueue(int x){
            a[last] = x;
            last++;
        }
        int dequeue(){
            int res = a[first];
            first++;
            return res;
        }
};


int main(){

    myqueue q;
    q.enqueue(6);
    q.enqueue(1);
    q.enqueue(2);
    q.enqueue(5);
    q.enqueue(4);

    cout << q.dequeue() << endl;

    return 0;
}