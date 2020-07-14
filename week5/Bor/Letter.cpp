#include <bits/stdc++.h>
using namespace std;

class Node {
  public:
  char value;
  Node *ch[26];
  bool isfirst;
  bool issecond;
  bool isend;
  Node(char value) {
    this->value = value;
    this->isfirst = false;
    this->issecond = false;
    isend = false;
    for (int i = 0; i < 26; i++)
      this->ch[i]=NULL;
  }
};

int cnt = 0;

class Trie {
  public:
  Node *root;
  Trie() {
    root = new Node(' ');
  }

  void insert(string s, int order) {
    Node *cur = root;
    for (int i = 0; i < s.size(); i++) {
      if (cur->ch[s[i]-'a'] != NULL)
        cur = cur->ch[s[i]-'a'];
      else {
        Node *node = new Node(s[i]);
        cur->ch[s[i]-'a'] = node;
        cur = node;
      }
      if (order == 1)
        cur->isfirst = true;
      else if (order == 2)
        cur->issecond = true;
      if (i == s.size()-1)
        cur->isend = true;
    }
  }

  void search(Node *node) {
    if (node == NULL)
      return;
    if (node->isfirst && node->issecond)
        cnt++;

    for (int i = 0; i < 26; i++) {
      search(node->ch[i]);
    }
  }

};

int main() {
  Trie *trie = new Trie();
  string s1, s2;
  cin >> s1 >> s2;
  for (int i = 0; i < s1.size(); i++) {
    string t = s1.substr(i);
    trie->insert(t, 1);
  }
  for (int i = 0; i < s2.size(); i++) {
    string t = s2.substr(i);
    trie->insert(t, 2);
  }
  trie->search(trie->root);
  cout << cnt;
  return 0;
}