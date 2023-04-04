#include <iostream>
#include <stack>
#include <vector>
#include <utility> 
#include <cmath>
 
using namespace std;

struct Node{
    long long int key, prior, sum;
    Node *left, *right;
    //Node () { key = _key, prior = 0, sum = 0; }
    Node (int _key) { key = _key, prior = rand(), sum = _key, left = NULL, right = NULL; }
};

long long int getSum(Node* root){
    return ((root == NULL) ? 0 : root->sum);
}
void upd (Node* v) { v->sum = getSum(v->left) + getSum(v->right) + v->key; }

void split(Node *root, long long int key, Node *&left, Node *&right){
    if(root == NULL){
        left = NULL;
        right = NULL;
        return;
    }else if(key >= root->key){
        split(root->right, key, root->right, right);
        left = root;
    }else{
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

long long int sumf(Node *root, long long int left, long long int right) {
    Node* r1, * r2, * r3, * r4;
    split(root, right, r1, r2);
    split(r1, left - 1, r3, r4);
    long long int res = getSum(r4);
    merge(merge(r3, r4), r2);
    return res;
}


int main(){
    vector<long long int> v;
    long long int n;
    cin >> n;
    Node* root = NULL;
    bool isAfter = false;
    long long int prev = -1;

    while(n > 0){
        char x;
        cin >> x;
        if(x == '+'){
            long long int i;
            cin>>i;
            if(isAfter){
                i  = (i+ prev) % 1000000000;
                insert(root, i);
                isAfter = false;
            }else{
                insert(root, i);
            }
        }else{
            long long int i, j;
            cin>>i>>j;
            long long int sum = 0;
            sum = sumf(root, i, j);
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