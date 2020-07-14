#include <iostream>

using namespace std;

struct node{
    int data;
    node * next;
    node(){

    };
};

struct  list
{
    node * head;
    node * tail;
    list(){
        head = NULL;
        tail = NULL;
    }
    /*
    void insertLast(int x){
        ListNode * t = new ListNode(x);
        if(tail == NULL){
            head = tail = t;
        }else{
            tail->next = t;
            tail = t;
        }
    }

    void insertFirst(int x){
        ListNode * t = new ListNode(x);
        if(tail == NULL){
            head = tail = t;
        }else {
            t -> next = head;
            head = t;
        }
    }*/
    void add(int x){
        node * temp = new node();
        temp -> data = x;
        temp -> next = NULL;
        if(tail == NULL){
            tail = temp;
            head = temp;
        }
        else{
            tail -> next = temp;
            tail = temp;
        }
    }
    void add1(int x){
        node * temp = new node();
        temp -> data = x;
        temp -> next = NULL;
        if(head == NULL){
            tail = temp;
            head = temp;
        }
        else{
            temp -> next = head;
            head = temp;
        }
    }
    void print(node * temp){
        while(temp != NULL ){
            cout << temp -> data << "->";
            temp = temp -> next;
        }
    }

    

};

int main(){
    int n,k;
    cin >> n;
    int a[n];
    int b[k];
    list l;
    for(int i=0;i<n;i++){
        cin >> a[i]; 
    } 
    for(int i = 0; i<n;i++){
        l.add(a[i]);
    }
    l.print(l.head);
    cin >> k;
    for(int i=0; i<k; i++){
        cin >> b[i]; 
    } 
    for(int i = 0;i< k;i++){
        l.add1(b[i]);
    }
    l.print(l.head);
    return 0;


    /*
    int a[] = {1,2,3,4,5,6,76,-1,-2,0};
    int len = sizeof(a) / sizeof(int);

    double_linked_list l;
    for(int i = 0; i < len; ++i){
        l.push_back(a[i]);
    }

    l.print();
    l.print_r();
    */


}