#include <iostream>
#include <stack>
#include <vector>
#include <string>
 
using namespace std;

struct Node{
    Node* left;
    Node* right;
    int data;
    int cnt;
    Node(){};
    Node(int data){
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
    Node* insert(Node* root, int key){
        int cnt;
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
    Node* kth(Node * root, int index){
        int cnt = 0;
        return order(root, index, cnt);
    }
    Node* order(Node * root, int index, int & cnt) {
        if (root == NULL || cnt > index) return NULL;
        Node* left = order(root -> right, index, cnt);
        // if(left){
        //     return left;
        // }
        cnt++;
        if(index == cnt){
            return root;
        }
        return order(root -> left, index, cnt);
    }
    Node *findMin(Node *node) {
        while (node->left != NULL)
            node = node->left;
        return node;
    }
    Node *delete_node(Node *node, int data) {
        if (node == NULL)
            return NULL;
        if (data < node->data) 
            node->left = delete_node(node->left, data);
        else if (data > node->data)
            node->right = delete_node(node->right, data);
        else {
            if (node->right == NULL && node->left == NULL)
                node = NULL;
            else if (node->left == NULL)
                node = node->right;
            else if (node->right == NULL)
                node = node->left;
            else {
                Node *temp = findMin(node->right);
                node->data = temp->data;
                node->right = delete_node(node->right, temp->data);
            }
        }
        return node;
    }
};

int main(){
    vector<int> v;
    TreeNode* tree = new TreeNode();
    tree->root = new Node();
    int n;
    cin >> n;
    cin.ignore(numeric_limits<streamsize>::max(), '\n'); 
   
    // cout << s.size()-1;
    // int y = tree->kth(tree->root,1)->data;
    // cout << y;
    int ch = n;
    int r =0 ;
    while(n > 0){
        string s;
        getline(cin, s);
       // cout << s;
        if(ch == n){
            tree->root = new Node(stoi(s.substr(3, s.size()-3)));
        }
        if(s[0] == '+' || s[0] == '1'){
            tree->insert(tree->root, stoi(s.substr(3, s.size()-3)));
        }else if(s[0] == '-'){
            tree->delete_node(tree->root,s[s.size()-1]);
        }else if(s[0] == '0'){
            //cout << s[s.size()-1];
            //int y = 6;
             r= stoi(s.substr(2, s.size()-2));
            
            int y = tree->kth(tree->root,r)->data;
            //v.push_back(y);
        }
        n--;
    }
    for(int i = 0; i< v.size(); i++){
        cout << v[i] << endl;
    }
    
    cout << r;
    // tree->insert(tree->root,7);
    // tree->insert(tree->root,3);
    // tree->insert(tree->root,2);
    // tree->insert(tree->root,1);
    
    
    return 0;
}