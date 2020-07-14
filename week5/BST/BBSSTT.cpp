/* #define _GLIBCXX_DEBUG
#include <bits/stdc++.h>
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


void leaf(node *root){ 
    if(root){
        leaf(root->r);
        cout << root-> val << "\n";
        leaf(root->l);
    }
}
int size , k ;
int main(){
    heap h;
    cin >> size >> k;
    while(size>0){
        string s;
        cin >> s;
        if(s == "insert"){
            int x;
            cin >> x;
            sum += x;
            h.insert(x);
            if(size > k){
                sum -= get_minimum();
                cut_min()
            }
            --size;
        }else{
            cout << sum<<endl;
        }
    }
}
int main(){
    int q, i = 0;
    cin >> q;
    vi v(q);
    for(int i = 0; i < q; i++){
        cin >> v[i];
    }
    node * tree;
    
        tree = new node(v[i]);
    while(n%i == 0){
        sum += i;
        n /= i;
    }
    if(n>1){
        sum+=n;
    }
    

    for(int i = 1; i < q; i++){
         add_tree(tree, v[i]);
    }
    leaf(tree);    
}



 */


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


using namespace std;
struct TreeNode{
  int val;
  TreeNode * l;
  TreeNode * r;
  TreeNode(int x) {
    val = x;
    l = r = NULL;
  }
};

TreeNode* insert(int val){
    return new TreeNode(val);
}

TreeNode * invertTree(TreeNode *root, int val){
    if(!root){
        root = insert(val);
        return root;
    }
    if(root->val > val){
       if(!root->l){
           root->l = insert(val);
       }else return invertTree(root->l, val);
    }
    if(root->val < val){
       if(!root->r){
           root->r = insert(val);
       }else return invertTree(root->r, val);
    }
    return root;
}

void Order(TreeNode * root) {
  if (root == NULL) return;
  Order(root -> r);
  printf("%d\n", root -> val);
  Order(root -> l);
}

int main() {
  TreeNode* root = NULL;
  int n;
  cin >> n;
  vi v(n);
    int i = 0;
    for(int i = 0; i < n; i++){
        cin >> v[i];
    }
    TreeNode * tree;
    tree = new TreeNode(v[i]);


    for(int i = 1; i < n; i++){
         invertTree(tree, v[i]);
    }    
  
  Order(tree);
}