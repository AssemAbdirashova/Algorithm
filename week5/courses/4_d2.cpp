#include <iostream>
#include <stack>
#include <vector>
#include <utility> 
 
using namespace std;

struct Node {
    int key, prior,sum;
    Node *l = 0, *r = 0;
    Node (int _key) { key = _key, prior = rand(); }
};
int sum (Node* v) { return v ? v->sum : 0; }
void upd (Node* v) { v->sum = sum(v->l) + sum(v->r) + v->key; }

pair<Node*, Node*> split (Node *p, int x) {
    if (!p) return {0, 0};
    if (p->key <= x) {
        pair<Node*, Node*> q = split(p->r, x);
        p->r = q.first;
        upd(p);
        return {p, q.second};
    }
    else {
        pair<Node*, Node*> q = split(p->l, x);
        p->l = q.second;
        return {q.first, p};
    }
}
Node* merge (Node *l, Node *r) {
    if (!l) return r;
    if (!r) return l;
    if (l->prior > r->prior) {
        l->r = merge(l->r, r);
        upd(l);
        return l;
    }
    else {
        r->l = merge(l, r->l);
        upd(r);
        return r;
    }
}
int sumf (int l, int r, Node* root) {
    pair<Node*, Node*> rq = split(root, r);
    pair<Node*, Node*> lq = split(rq.first, l);
    int res = sum(lq.second);
    root = merge(lq.first, merge(lq.second, rq.second));
    return res;
}
void insert (Node* root, int x) {
    pair<Node*, Node*> q = split(root, x);
    Node *t = new Node(x);
    root = merge(q.first, merge(t, q.second));
}




int main(){
    vector<long long int> v;
    long long int n;
    cin >> n;
    Node* root ;
    char x;
    cin >> x;
    bool isRoot = false;
    if(x == '+' ){
        long long int  i;
        cin>>i;
        root = new Node(i);
    }else{
        long long int i, j;
        cin>>i>>j;
        v.push_back(0);
       isRoot = true;
    }

    long long int prev = -1;
    bool isAfter = false;
    while(n-1 > 0){
        char x;
        cin >> x;
        if(x == '+'){
            long long int i;
            cin>>i;
            if(isRoot){
                root = new Node(i);
                isRoot = false;
            }else{
                if(isAfter){
                    i  = (i+ prev) % 1000000000;
                    insert(root, i);
                    isAfter = false;
                }else{
                    insert(root, i);
                }
            }
        }else if(x == '?'){
            long long int i, j;
            cin>>i>>j;
            long long int sum = 0;
            sum = sumf( i, j, root);
            
            v.push_back(sum);
            prev = sum;

            isAfter = true;
        }
        n--;
    }
    for(long long int i = 0; i< v.size(); i++){
        cout << v[i] << '\n';
    }

    return 0;
}