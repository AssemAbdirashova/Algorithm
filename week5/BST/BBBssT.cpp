#define _GLIBCXX_DEBUG
#include <iostream>
#include <vector>

using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;
typedef vector<bool> vb;
#define pb push_back
#define mp make_pair
#define f first
#define s second
#define in insert
#define FOR(i,a,b) for (int i = a; i < b; i++)
#define all(x) (x).begin(), (x).end()
#define speed ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
const int INF = 1e9 + 5;

struct node{
    int val;
    struct node *l, *r;
    node(int i): val(i), l(nullptr), r(nullptr){};
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


void leaf(node *root){ // asc or desc
    if(root){
        leaf(root->l);
        cout << root-> val << "\n";
        leaf(root->r);
    }
}

/* void alone_leaf(node *root){ // leaf without child
    if(root){
        alone_leaf(root->l);
        if(!root->l and !root->r)
            cout << root-> val << "\n";
        alone_leaf(root->r);
    }
}

void two_childe(node * root){
    if(root){
        two_childe(root->l);
        if(root-> l and root->r or root->r and root->l)
            cout << root->val << "\n";
        two_childe(root->r); 
    }
}


void one_childe(node * root){
    if(root){
        one_childe(root->l);
        if(!root-> l and root->r or !root->r and root->l)
            cout << root->val << "\n";
        one_childe(root->r); 
    }
}

int maxDepth(node * root){
    if(root == 0) return 0;
    else{
        int leftDepth = maxDepth(root->l);
        int rightDepth = maxDepth(root->r);
        if(leftDepth > rightDepth){
            return  leftDepth+1;

        }else{
            return  rightDepth+1;
        }
    }
}

int count_of_el(node * root){
    if(root == 0) return 0;
    int lcnt = count_of_el(root -> l);
    int rcnt = count_of_el(root -> r);
    return lcnt+rcnt+1;
}

bool sbalance(node * root){
    if(root == 0) return 0;
    else{
        int lpart = sbalance(root->l);
        int rpart = sbalance(root->r);
        if(lpart == rpart or abs(lpart - rpart) == 1){
            return true;
        }
        else return false;
    }
    
} */


int main(){
   int n;
   cin >> n;
   node * tree = nullptr;
   if(n != 0){
       tree = new node(n);
   }
   while(n != 0){
       add_tree(tree, n);
       cin >> n;
   }
  /*  if(sbalance(tree)) cout << "YES";
   else cout << "NO"; */

   leaf(tree);  
   //cout <<  maxDepth(tree);  
   //cout << count_of_el(tree);
   //alone_leaf(tree);
   //two_childe(tree);
   //one_childe(tree);


    
}