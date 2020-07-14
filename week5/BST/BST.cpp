#include <iostream>

using namespace std;

class Node{
    public:
    int data;
    Node *left;
    Node *right;
    Node(int data){
        this->data = data;
        left =NULL;
        right = NULL;
    }
};
class Tree{
    public:
    Node *root;
    Tree(){
        root=NULL;
    }
    int height(Node *node){

    }
    Node *insert(Node *node, int data){
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

};


int main(){
    Tree *tree = new Tree();
    tree->root = tree->insert(NULL,10);
    tree->insert(tree->root, 4);

    return 0;
}