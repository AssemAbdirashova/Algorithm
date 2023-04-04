#include <iostream>
#include <stack>
#include <vector>
 
using namespace std;

struct Node{
    Node* left;
    Node* right;
    long long int data;
    long long int cnt;
    Node(){};
    Node(long long int data){
        left = right = NULL;
        this->data = data;
        cnt = 0;
    }
};
class TreeNode{
    public:
    Node* root;
    TreeNode(){
        root = NULL;
    }
    Node* insert(Node* root, long long int key){
        long long int cnt;
        if(root == NULL){
            root = new Node(key);
            return root;
        }
        root->cnt = root->cnt + 1;
        if(root->data > key){
            root->left =  insert(root->left, key);
        }else{
            root->right = insert(root->right, key);
        }
        return root;
    }
   
    Node* kth(Node* root,long long int& k){
        if(root==NULL)
            return NULL;

        Node* right=kth(root->right,k);
        if(right!=NULL)
            return right;
        k--;
        if(k==0)
            return root;
        
        return kth(root->left,k);
    }
    // Node* kth(Node* root,long long int& k){
    //     long long int sz  = 0;
    //     if(root->right!= NULL){
    //         sz = root->right->cnt;
    //     }
    //     if(k == sz){
    //         return root;
    //     }else if(sz < k){
    //         return kth(root->right, k);
    //     }else{
    //         k = sz- k;
    //         return kth(root->left, k);
    //     }
    // }
    Node* kth1(Node* root,long long int& k){
        long long int sz  = 0;
        if(root->cnt < k){
            return NULL;
        }
        while(true){
            if (root->left == root->right) return root->left; // leaf node
            if (root->left->cnt < k) {
                k -=  root->left->cnt;
                root = root->right;
            }else 
                root = root->left;
        }
        // if(k == sz){
        //     return root;
        // }else if(sz < k){
        //     return kth(root->right, k);
        // }else{
        //     k = sz- k;
        //     return kth(root->left, k);
        // }
    }


    
    int successor(Node * root) {
        root = root->right;
        while (root->left != NULL) 
            root = root->left;
        return root->data;
    }
    int predecessor(Node * root) {
        root = root->left;
        while (root->right != NULL) 
            root = root->right;
        return root->data;
    }
    
    Node * deleteNode(Node * root, long long int key) {
        if (root == NULL) return NULL;
        if (key > root->data)   
            root->right = deleteNode(root->right, key);
        else if 
            (key < root->data) root->left = deleteNode(root->left, key);
        else {
            if (root->left == NULL && root->right == NULL) root = NULL;
            else if (root->right != NULL) {
                root->data = successor(root);
                root->right = deleteNode(root->right, root->data);
            } else {
                root->data = predecessor(root);
                root->left = deleteNode(root->left, root->data);
            }
        }
        return root;
    }

};

int main(){
    vector<int> v;
    TreeNode* tree = new TreeNode();
    long long int n;
    cin >> n;
    char x;
    cin >> x;
    if(x == '+' ){
        long long int y, i;
        cin>>y>>i;
        tree->root = new Node(i);
    }else if(x == '1'){
        long long int i;
        cin>>i;
        tree->root = new Node(i);
    }
    bool isRoot = false;
    while(n-1 > 0){
        char x;
        cin >> x;
        if(isRoot){
            if(x == '+' ){
            long long int y, i;
            cin>>y>>i;
            tree->root = new Node(i);
            }else if(x == '1'){
                long long int i;
                cin>>i;
                tree->root = new Node(i);
            }
            isRoot = false;
        }else{
            if(x == '+'){
                long long int y, i;
                cin>>y>>i;
                tree->insert(tree->root,i);
            }else if(x == '-'){
                long long int y, i;
                cin>>y>>i;
                if(tree->deleteNode(tree->root,i) == NULL){
                    isRoot = true;
                };
            }else if(x == '0'){
                long long int i;
                cin>>i;
                long long int y = tree->kth(tree->root,i)->data;
                v.push_back(y);
            }else if(x == '1'){
                long long int i;
                cin>>i;
                tree->insert(tree->root,i);
            }
        }
        n--;
    }
    for(long long int i = 0; i< v.size(); i++){
        cout << v[i] << '\n';
    }

    return 0;
}