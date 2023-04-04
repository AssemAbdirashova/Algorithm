#include <iostream>
#include <stack>
#include <vector>
#include <utility> 
#include <cmath>
#define MAXV 1000000009
 
using namespace std;

struct Node{
    long long int key, prior, cnt, sum;
    Node *left, *right;
    Node (int _key) { key = _key, prior = rand(), sum = _key, left = NULL, right = NULL, cnt = 1 ; }
};

long long int getSize(Node* root){
    return ((root == NULL) ? 0 : root->cnt);
}
void upd (Node* v) { v->cnt = getSize(v->left) + getSize(v->right) + 1; }

void split(Node *root, long long int key, Node *&left, Node *&right){
    if(root == NULL){
        left = NULL;
        right = NULL;
        return;
    }
    else if (key >= root->key){
        split(root->right, key, root->right, right);
        left = root;
    }
    else{
        split(root->left, key, left, root->left);
        right = root;
    }
    upd(root);
}

Node* merge (Node *left, Node *right) {
    if (!left) 
    	return right;
    if (!right)
    	return left;
    if (left->prior > right->prior) {
        left->right = merge(left->right, right);
        upd(left);
        return left;
    } else { 
        right->left = merge(left, right->left);
        upd(right);
        return right;
    }
}

bool search(Node *root, long long int val){
    if(root == NULL)
        return false;
    else if (root->key == val)
        return true;
    if(val < root->key)
        return search(root->left, val);
    else //if (root->key < val)
        return search(root->right, val);
}

void insert(Node *&root, long long int key){
    if(!search(root, key)){
        Node *temp = new Node(key);
        Node *left, *right;
        split(root, key, left, right);
        root = merge(merge(left, temp), right);
    }
}
int kth(Node* root, int k){
    if ((k < 1) || (k > root->cnt)) return MAXV;

    Node *l, *r, *cur = root;
    for(; ;){
        l = cur->left, r = cur->right;
        if (r){
            if (k <= r->cnt) cur = r;
            else if ((r->cnt + 1) == k) return cur->key;
            else cur = r, k -= (r->cnt + 1);
        }
        else{
            if (k == 1) return (cur->key);
            else cur = l, k--;
        }
    }
    return k;
}
int getKth(Node* temp, int k, int par = 0){
        if(temp == NULL) return 0;
        int currSize = par + getSize(temp->right)  + 1;
        if(currSize == k) return temp->key;

        else if(currSize <= k) return getKth(temp->right, par, k);
        else return getKth(temp->left, currSize, k);
}
int find_kth(Node *t, int k, int add = 0){
    assert(t);
    int cur_pos = add + getSize(t->left) + 1;
    if(cur_pos == k) return t-> key;
    if(cur_pos < k) return find_kth(t->right, k, cur_pos);
    return find_kth(t->left, k, add);
}

void erase(Node *&root, int key) {
	if(!root) return;
    if (root->key == key)
        merge(root->left, root->right);
    else
        erase(key < root->key ? root->left : root->right, key);
    upd(root);
}

int main(){
    vector<int> v;
    long long int n;
    cin >> n;
    char x;
    cin >> x;
    Node* root = NULL;
    if(x == '+' ){
        long long int y, i;
        cin>>y>>i;
        insert(root, i);
    }else if(x == '1'){
        long long int i;
        cin>>i;
        insert(root, i);
    }
    bool isRoot = false;
    while(n-1 > 0){
        char x;
        cin >> x;
        if(isRoot){
            if(x == '+' ){
            long long int y, i;
            cin>>y>>i;
            insert(root, i);
            }else if(x == '1'){
                long long int i;
                cin>>i;
                insert(root, i);
            }
            isRoot = false;
        }else{
            if(x == '+'){
                long long int y, i;
                cin>>y>>i;
                insert(root, i);
            }else if(x == '-'){
                long long int y, i;
                cin>>y>>i;
                erase(root, i);
            }else if(x == '0'){
                long long int i;
                cin>>i;
                long long int y = getKth(root,i);
                v.push_back(y);
            }else if(x == '1'){
                long long int i;
                cin>>i;
                insert(root, i);
            }
        }
        n--;
    }
    for(long long int i = 0; i< v.size(); i++){
        cout << v[i] << '\n';
    }
    return 0;
}