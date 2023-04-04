#include <iostream>
#include <stack>
#include <vector>
 
using namespace std;

struct Node{
    Node* left;
    Node* right;
    long long int data;
    Node(int data){
        left = NULL;
        right = NULL;
        this->data = data;
    }
};
class Tree{
    public:
    Node *root;
    Tree(){
        root=NULL;
    }
    int height(Node *node){
        return 0;
    }
    Node *insert(Node *node, long long int data){
        if(node==NULL){
            node = new Node(data);
            return node;
        }
        if(node->data < data){
            node->right = insert(node->right,data);
        }
        else
            node->left = insert(node->left, data);
        return node;
    }
    Node *insert2(Node *node, long long int data, long long int prev){
        data  = (data+ prev) % 1000000000;
        if(node==NULL){
            node = new Node(data);
            return node;
        }
        if(node->data < data){
            node->right = insert(node->right,data);
        }
        else
            node->left = insert(node->left, data);
        return node;
    }
    Node *find(Node *node){
        Node* succParent = node;
 
        Node* succ = node->right;
        while (succ->left != NULL) {
            succParent = succ;
            succ = succ->left;
        }
        return succ;
    }
    Node *search(Node *node, long long int key){
        if (node == NULL || node->data == key)
            return node;
        if (node->data < key)
            return search(node->right, key);
        
        return search(node->left, key);
    }
    int findMaxforN(Node* root,  long long int N){
        if (root == NULL)
            return -1;
        if (root->data == N){
            return N;
        }else if (root->data < N) {
            int k = findMaxforN(root->right, N);
            if (k == -1) return root->data;
            else return k;
        }
        else{
            return findMaxforN(root->left, N);   
        }
    }
    int findFloor(Node* root, long long int key){
        Node *curr = root, *ans = NULL;
    
        while (curr) {
            if (curr->data > key) {
                ans = curr;
                curr = curr->left;
            }      
            else if (curr->data == key) {
                ans = curr;
                break;
            }
                
            else // move to the right of the tree
                curr = curr->right;
        }
        
        if (ans != NULL)
        return ans->data;
        
        return -1;
    }
    void order(Node * root) {
        if (root == NULL) return;
        order(root -> left);
        cout << " " << root-> data;
        //printf("%d\n", root -> data);
        order(root -> right);   
    }
};

int main() {
    int n;
    cin >> n;
    vector<long long int> v;
    Tree *tree = new Tree();
    char x1;
    cin >> x1;
    long long int re;
    cin >> re;
    tree->root = tree->insert(NULL, re);
    long long int prev = -1;
    for(int i = 0; i< n-1; i++){
        char x;
        cin >> x;
        if(x == '+'){
            long long int y;
            cin >> y;
            if(prev!=-1){
                tree->insert2(tree->root, y, prev);
                prev = -1;
            }else{
                tree->insert(tree->root, y);
            }
        }else if(x == '?'){
            long long int y;
            cin >> y;
            //tree->insert(tree->root, y);
            v.push_back(tree->findFloor(tree->root,y));
            prev = tree->findFloor(tree->root,y);
        }
    }
    for(int i = 0; i< v.size(); i++){
        cout << v[i] << endl;
    }
    //tree->order(tree->root);

    // tree->root = tree->insert(NULL, 6);
    // tree->insert(tree->root, 5);
    // tree->insert(tree->root, 1);
    // tree->insert(tree->root, 17);
    // tree->insert(tree->root, 8);
    // tree->insert(tree->root, 9);
    // tree->insert(tree->root, 11);
    // tree->insert(tree->root, 12);
    // tree->insert(tree->root, 13);
    
    // cout << tree->find(tree->search(tree->root, 12))->data;
    return 0;
}