
#include <iostream>
#include <vector>
using namespace std;

int hh=0;
int hh2 = 0;
class Node {
public:
	int data;
	Node* left;
	Node* right;

	Node(int data) {
		this->data = data;
		left = NULL;
		right = NULL;
	} 
};

class Tree {
public:
	Node* root;

	Tree() {
		root = NULL;
	}

	Node* add(Node* root, int data) {
		if (root == NULL) {
			return new Node(data);
		} else if (root->data > data) {
			root->left = add(root->left, data);
		} else if (root->data < data) {
			root->right = add(root->right, data);
		}
		return root;
	}
	
	void find(Node* root, int x) {
		if (root == NULL) {
			return;
			
		} else if (root->data != x) {
			leaf(root);
		} else if (root->data < x) {
			return find(root->right, x);
		} else {
			return find(root->left, x);
		}
	}

	int Depth(Node * root){
    if(!root -> left && !root -> right) return 1;
	else if(!root -> left) 
	return Depth(root -> right);
	else if(!root -> right) 
	return Depth(root -> left);
	else return Depth(root -> left) + Depth(root -> right) ;
	}
	
	void leaf(Node *root){ 
		if(root != NULL){
			cout << root-> data << " ";
			leaf(root->left);
          
        leaf(root->right);
        
		}
    	
    }
    
	
	
};
	// int getSubtreeHeight(Node* root) {
	// 	root  = find(root, )
	// }

int main(){
	int n;
	cin >> n;

	int a[n];
    Tree *tree = new Tree();
	for(int i=0;i<n;i++){
		cin >> a[i];
	}
	int k;
	cin >> k ;
	
	tree->root = tree->add(NULL,a[0]);
	for(int i=1;i<n;i++){
		tree->add(tree->root, a[i]);
	}
	tree->find(tree->root, k);
    //tree->root = 
	
	//cout << tree->root->datd	va;
	// cout << tree->Depth(tree->root);
    //cout << (tree->find(tree->root,k))->data;
return 0;

}
