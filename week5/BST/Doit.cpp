#include <iostream>

using namespace std;

struct node{
    int val;
    node * right;
    node * left;
    node(int v){
        val = v;
        right = NULL;
        left = NULL;
    }
};



node * add_node(node * root, int x){
    if(root == NULL) return new node(x);
    if(root->val < x){
        if(root->right == NULL){
            root->right = new node(x);
            return root;
        }else{
            add_node(root->right, x);
        }
    }else if(root->val > x){
        if(root->left == NULL){
            root->left = new node(x);
            return root;
        }else{
            add_node(root->left, x);
        }
    }
    return root;
}
void print(node * root){
    if(root != NULL){
         cout << root->val << " ";
        print(root->left);
       
        print(root->right);
    }
}


int main(){
    int x,a;
    cin>>x;
    node * root = NULL;
    for(int i=0; i<x; i++){
        cin >> a;
        root = add_node(root, a);
    }
    int k;
    cin >> k;
    search(root, k);
    return 0;
}