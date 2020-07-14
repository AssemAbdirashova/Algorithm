#include <iostream>

using namespace std;

struct Node {
    public:
    int data;
    Node *next;

    Node(int data) {
        this->data = data;
        next = NULL;
    }
};

struct Queue {
    public:
    Node *tail, *head;
    int sz;

    Queue() {
        tail = head = NULL;
        sz = 0;
    }

    void push(int data) {
        Node *node = new Node(data);
        tail->next = node;
        tail = node;
        sz++;
    }
    void pop() {
        if (head != NULL) {
            sz--;
            head = head->next;
        }
    }

    int front() {
        return head->data;
    }

    bool empty() {
        return sz == 0;
    }
    void print(){
        Node *v = head;
        while (v != NULL) {
        cout << v->data << ' ';
        v = v->next;
    }
    cout << "\n";
    }
};

int main() {
    Queue q;
    cout << " as";

    q.push(5);
    q.print();
    cout << "think";
    return 0;
    
}