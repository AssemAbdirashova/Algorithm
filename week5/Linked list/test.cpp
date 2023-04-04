#include <iostream>

using namespace std;

struct node{
    int data;
    node* next;
    node(int x){
        data = x;
        next = NULL;
    }
    node(){};
};

struct list{
    node* head;
    node* tail;
    list(){
        head = NULL;
        tail = NULL;
    }
    void addLast(int x){
        node* temp = new node(x);
        if(tail == NULL){
            head = tail = temp;
        }
        else{
            tail->next = temp;
            tail = temp;
        }
    }
    void addFirst(int x){
        node* temp = new node(x);
        if(tail == NULL){
            head = tail = temp;
        }
        else{
            temp->next =head;
            head = temp;
        }
    }
    void print(node * temp){
        while(temp!=NULL){
            cout<< temp->data << " ";
            temp = temp-> next;
        }
    }
    int count(){
        node* temp = head;
        int cnt = 0;
        while (temp != NULL){
            cnt++;
            temp = temp->next;            
        }
        return cnt;
    }
    int count(int x){
        node* temp =head;
        int cnt = 0;
        while(temp != NULL){
            if(temp -> data == x){
                cnt++;
            }
            temp = temp->next;
        }
        return cnt;
    }
    
    int getNth(int x){
        int ans;
        node* temp = head;
        for(int i=0; i< x; i++ ){
            ans = temp->data;
            temp = temp->next;
        }
        return ans;
    }

    void del(node* head, int pos){
        node* prev = head;
        node* next = new node(); 
        if (pos == 0){
            head = NULL;
            return;
        }
        int i= 0;
        while(i< pos-1){
            prev = prev->next;
            i++;
        }
        next = prev->next->next;
        prev -> next = next;
    }
    void delwithbugprevious(int val){
        node* temp = head;
        node* next = new node();
        while(temp!=NULL){
            if(temp->data == val){
                next = temp->next->next;
                temp->next = next;
            }
            temp = temp->next;
        }
    }
    void del(int val){
        node* v = head;
        node* prev = new node();
        while(v != NULL && v->data != val ){
            prev = v;
            v = v->next;
        }
        if(v==NULL){
            return;
        }else{
            if(v==head){
                head = v->next;
            }
            else{
                prev->next = v->next;
                
            }
            delete v;
        }
    }
};
int main(){

    int n;
    cin>> n;
    int a[n];
    list l;
    for(int i = 0; i< n; i++){
        cin>> a[i];
    }
    for(int i = 0; i< n; i++){
        l.addFirst(a[i]);
    }
    l.print(l.head);
    cout<< endl;
    l.del(3);
    l.print(l.head);
    return 0;
}