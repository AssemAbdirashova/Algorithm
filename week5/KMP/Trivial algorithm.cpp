#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

class Node {
	public:
	char value;
	Node *ch[10];
	int cnt;
	bool isEnd;

	Node(char value) {
		this->value = value;
		this->cnt = 0;
		this->isEnd = false;
		for (int i = 0; i < 10; i++)
		this->ch[i]=NULL;
	}
	};

	bool ok  = true;

	class Trie {
	public:
	Node *root;
	Trie() {
		root = new Node(' ');
	}

	void insert(string s) {
		Node *cur = root;
		for (int i = 0; i < s.size(); i++) {
			if (cur->ch[s[i]-'0'] != NULL)
			cur = cur->ch[s[i]-'0'];
			else {
			Node *node = new Node(s[i]);
			cur->ch[s[i]-'0'] = node;
			cur = node;
			}
			if (i == s.size() - 1) {
			cur->isEnd = true;
			}
		}
	}

	void search(Node *node) {
		if (node == NULL)
			return;
		if (node->isEnd) {
			int has = false;
			for (int i = 0; i < 10; i++)
			if (node->ch[i]!=NULL) {
				has = true;
			}
			if (has)
			ok = false;
		}

		for (int i = 0; i < 10; i++) {
			search(node->ch[i]);
		}
	}

	};
	vector<string> v;
	void solve() {
	Trie *trie = new Trie();
	int n;
	cin >> n;
	
	ok = true;
	for (int i = 0; i < n; i++) {
		string t;
		cin >> t;
		reverse(t.begin(), t.end());
		trie->insert(t);
	}
		trie->search(trie->root);
		if (ok){
			v.push_back("YES") ;
		}
		else {
			v.push_back("NO");

		}	
	
}

int main() {
	int test;
	cin >> test;
	for (int t = 0; t < test; t++){
		solve();
	}

	for(int i = 0 ; i< v.size(); i++){
			cout << v[i] << endl;
		}
}