#include <iostream>

using namespace std;


struct node{
    int val;
    struct node *l, *r;
    node(int i){
        val= i;
        l = NULL;
        r = NULL;
    }
};

node * add_node(int val){
    return new node(val);
}

node * add_tree(node *root, int val){
    if(!root){
        root = add_node(val);
        return root;
    }
    if(root->val > val){
       if(!root->l){
           root->l = add_node(val);
       }else return add_tree(root->l, val);
    }
    if(root->val < val){
       if(!root->r){
           root->r = add_node(val);
       }else return add_tree(root->r, val);
    }
    return root;
}


int hh = 0; 
bool out(node* v) {
	if (v == NULL) return false;
	out(v->l);
	
    if(!out(v->l) && !out(v->r) || !out(v->r) && !out(v->l)){
        hh++;    
    }
    out(v->r);
    return true;
    
}
//int hh=0;
int leaf(node *root){
    
    if(root == NULL){
        return ;
    }
    
        leaf(root->l);
    if(root->r == NULL && root->l == NULL){
        hh++;
    }
   
        leaf(root->r);
    
    
    return hh;
}

int main(){
    int n, i = 0;
    cin >> n;
    int a[n];
    for(int i = 0; i < n; i++){
        cin >> a[i];
    }
    node * tree;
    
    tree = new node(a[0]);
    for(int i = 1; i < n; i++){
         add_tree(tree, a[i]);
    }
    
    cout << leaf(tree); 
    }
    

