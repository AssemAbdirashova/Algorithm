#include <iostream>
#include <vector>

using namespace std;

struct Node{
    Node *zero;
    Node *one;
    Node() : zero(nullptr), one(nullptr) {}
};

class Trie{
    public:
    Node *root;
    Trie(){
    root = new Node();
    }

void insert(int n){
    Node *cur = root;
    for(int i = 31; i > -1; i = i-1){
        int bit = (n >> i) & 1;
        if(bit == 0){
            if(cur->zero == NULL){
                cur->zero = new Node();
            }
            cur = cur->zero;
        }else{
            if(cur->one == NULL){
               cur->one = new Node(); 
            }
            cur = cur->one;
        }
    }
}

int helper(int data){
    Node *cur = root;
    int result = 0;
    for(int i = 31; i > -1; i = i-1){
        int bit = (data >> i) & 1;
        if(bit == 0){
            if(cur->one != NULL){
                cur = cur->one;
                result = result | (1 << i);
            }else{
                cur = cur->zero;
            }
        }
        else{
            if(cur->zero != NULL){
                cur = cur->zero;
                result = result | (1 << i);
            }else{
                cur = cur->one;
            }
        }
    }
    return result;
}

int getMax(int x, int a){
    insert(x);
    a = max(helper(x), a);
    return a;
}
};


int main(){
    Trie *trie = new Trie();
    vector<int> v;
    int n;
    cin >> n;
    int answer = 0;
    for(int i = 0; i < n; i++){
        int k;
        cin >> k;
        answer = trie->getMax(k, answer);
        v.push_back(answer);
    }
    for(int i = 0; i< v.size(); i++){
        cout << v[i]<< endl;
    }
    return 0;
}