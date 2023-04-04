#include<iostream>
#include<math.h>
#include<vector>

using namespace std;

struct Node{
    Node* a[2];
    Node(){
        for(int i = 0; i<2; i++){
            this->a[i] = NULL;
        }
    }
};
class Trie{
public:
    Node* root;
    Trie(){
        root = new Node();
    }

    void insert(int num){
        Node* temp = root;
        for(int i = 31; i >= 0; i--){
            int x = (num >> i) & 1;
            if(temp->a[x] == NULL){
                temp->a[x] = new Node();
            }
            temp = temp->a[x];
        }
    }
    int getMax(int n){
        Node* temp = root;
        int mx = 0;
        for(int i = 31; i>=0; i--){
            int x = (n>>i)& 1;
            if(temp->a[1-x] != NULL){
                mx = mx | (1 << i);
                temp = temp->a[1-x];
            }else{
                temp = temp->a[x];
            }
        }
        return mx;
    }

};


int main(){
    int n;
    cin >> n;
    vector<int> nums;
    for(int i = 0; i< n; i++){
        int x;
        cin >> x;
        nums.push_back(x);
    }
    vector<int> answer;
    Trie trie;
        for(int i= 0; i< nums.size(); i++){
            trie.insert(nums[i]);
            int mx = 0;
            for(int j = 0; j < pow(2, 3); j++){
                mx = max(trie.getMax(j), mx);
                cout << "   " << j << "  " << mx;
            }
            
            answer.push_back();
        }
    for(int i = 0; i< n; i++){
        cout << answer[i];
    }

    return 0;
}