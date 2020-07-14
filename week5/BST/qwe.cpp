#include <iostream>
#include <algorithm>

using namespace std;
struct Node{
    int value;
    Node* left;
    Node* right;
    Node(int o){value = o; right = NULL; left = NULL;}
};
void add(Node* tree, int x){
    if(tree == NULL){
        tree = new Node(x);
        return;
    }
    else if(tree -> value > x ){
        add(tree->left, x);
    }
    else if(tree->value < x){
        add(tree->right,x);
    }


}
void search(Node* kor, int x){
if(kor -> value > x){
 if(kor -> left) search(kor -> left, x);
else {
     Node* t = new Node(x);
 kor -> left = t;
        }
    }
    else{
 if(kor -> right) search(kor -> right, x);
     else {
      Node* t = new Node(x);
     kor -> right = t;
        }
    }
}
void out(Node* v) {
	if (v == NULL) return;
	out(v->left);
	
    cout<< v->value;
    out(v->right);

    
}
int counter(Node* kor){
 if(!kor -> left && !kor -> right) return 1;

else if(!kor -> left) 
return counter(kor -> right);
else if(!kor -> right) 
return counter(kor -> left);
else return counter(kor -> left) + counter(kor -> right);
}
int main(){
 int n,m;
 int k;
cin >> n >> m;
Node* root = new Node(m);
for(int i = 1; i < n; i++){
     cin >> m;
    add(root, m);
}
cin >> k;
out(root);
   search(root, k);
 cout << "  " << counter(root);
}