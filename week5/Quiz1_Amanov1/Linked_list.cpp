#include <iostream>

using namespace std;

struct node {
    int data;
    node * next;

    node(){};
};

struct list {
    node * head;
    node * tail;
    
    list(){
        head = NULL;
        tail = NULL;
    }
    void add(int x){
        node * temp = new node();
        temp -> data = x;
        temp -> next = NULL;
        if (tail == NULL){
            head = temp;
            tail = temp;
            
        }
        else {
            tail -> next = temp;
            tail = temp;
        }
    }
    void print(node * temp){
        while (temp != NULL){
            cout << temp -> data << "->";
            temp = temp -> next;
        }
    }

    void deleteNode(node * head, int pos){
        if (pos == 0){
            head = NULL;
            return;
        }
        node * prev = new node();
        node * next = new node();
        prev = head;
        for (int i = 0; i < pos - 1; i++){
            prev = prev -> next;
        }
        next = prev -> next -> next;
        prev -> next = next;
    }
};

int main(){
    list l;
    
    l.add(1);
    l.add(2);
    l.add(3);
    l.deleteNode(l.head, 1);
    l.print(l.head);
    return 0;
}