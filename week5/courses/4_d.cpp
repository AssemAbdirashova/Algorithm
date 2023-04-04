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
        if(root->data == key){
            root->cnt = root->cnt + 1;
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

 
    long long int find(Node* root,long long int i, long long int j){
        if(root==NULL)
            return 0;
        if(root->data < i) return find(root->right, i, j);
        else if(root->data > j) return find(root->left, i, j);
        else return root->data + find(root->right, i, j) + find(root->left, i, j);
    }


};

int main(){
    vector<long long int> v;
    TreeNode* tree = new TreeNode();
    long long int n;
    cin >> n;

    char x;
    cin >> x;
    bool isRoot = false;
    if(x == '+' ){
        long long int  i;
        cin>>i;
        tree->root = new Node(i);
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
                tree->root = new Node(i);
                isRoot = false;
            }else{
                if(isAfter){
                    i  = (i+ prev) % 1000000000;
                    tree->insert(tree->root, i);
                    isAfter = false;
                }else{
                    tree->insert(tree->root, i);
                }
            }
        }else if(x == '?'){
            long long int i, j;
            cin>>i>>j;
            long long int sum = 0;
            sum = tree->find(tree->root, i, j);
            
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