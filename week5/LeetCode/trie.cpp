#include <iostream>
#include <vector>

using namespace std;


class node{
    public:
    bool ok;
    node* a[26];
    node(){
        for(int i = 0 ; i < 26; i++){
            a[i] = NULL;
        }
        ok = false;
    }
};
class Trie{
    public:
    Trie(){
        root = new node();
    }
    void insert(string s){
        node* trieNode = root;
        int temp = 0;
        for(int i = 0; i < s.size(); i++){
            temp = s[i] - 'a';
            if(trieNode->a[temp] == NULL ){
                trieNode->a[temp] = new node();
            }
            trieNode = trieNode->a[temp];
        }
        trieNode->ok = true;
    }

    bool search(string s){
        node* trieNode = root;
        int temp = 0;
        for(int i = 0; i< s.size(); i++){
            temp = s[i] - 'a';
            if(trieNode->a[temp] == NULL){
                return false;
            }
            trieNode = trieNode->a[temp];
        }
        return trieNode->ok;
    }

    bool startsWith(string s){
        node* trieNode = root;
        int temp = 0;
        for(int i = 0 ; i< s.size(); i++){
            temp = s[i] - 'a';
            if(trieNode->a[temp] == NULL){
                return false;
            }
            trieNode = trieNode->a[temp];
        }
        return true;
    }
    private:
    node* root;

};
int main(){
    Trie* obj = new Trie();
    obj->insert("asdf");
    cout << obj->search("asdf") << endl;
    cout << obj->startsWith("b");

    return 0;
}