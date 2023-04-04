#include <iostream>
#include<vector>
using namespace std;

struct ListNode {
    int val;
    ListNode* next;
    ListNode(int x) : val(x), next(NULL) {}
};

struct List{
    ListNode * head;
    ListNode * tail;
    List(){
        head = NULL;
        tail = NULL;
    }
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
    }

    void print(ListNode * t){
        while(t != NULL){
            cout << t->val;
            t = t->next;
            if(t != NULL){
                cout << " ";
            }
        }
    }
    int count (int x){
        ListNode * temp = NULL;
        int cnt = 0;
        temp = head;
        while (temp != NULL){
            if (temp->val == x)
                cnt ++;
            temp = temp -> next;
        }
        return cnt;

    }

    int getNth(int n){
        ListNode * temp = NULL;
        temp = head;
        int i = 0;
        while (i < n){
            temp = temp -> next;
            if (temp == NULL)
                return -1;
            i++;
        }
        return temp -> val;

    }
};



int main(){

    List l;
    int n;
    cin >> n;
    string s;
    int x;
    vector<int> v;
    for (int i=0; i<n; i++){
        cin >> s;
        if (s == "insertFirst"){
            cin >> x;
            l.insertFirst(x);
            continue;
        }
        if (s == "cnt"){
            cin >> x;
           
            v.push_back(l.count(x));
            continue;

        }
        if (s == "getNth"){
            cin >> x;
            v.push_back(l.getNth(x));
            continue;
        }
        if (s == "insertLast")
        {
            cin >> x;
            l.insertLast(x);
            continue;
        }
    }
    for (int i =0; i<v.size();i++){
        cout << v[i] << endl;;
    }
   
    l.print(l.head);


    

    return 0;
}