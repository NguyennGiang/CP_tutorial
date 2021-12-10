#include<bits/stdc++.h>
using namespace std;
#define KAMEHAMEHA ios_base::sync_with_stdio(0); cin.tie(0);
const int N = 26;

struct Node {
  Node *child[N];
  int cnt;
  Node(){
    cnt = 0;
    fill(child, child + N, nullptr);
  };
};

int n, q;

void add(Node* root, string s){
  Node *cur = root;
  for (char c : s){
    if (cur->child[c - 'a'] == nullptr){
      cur->child[c - 'a'] = new Node();
    }
    cur = cur -> child[c - 'a'];
    cur->cnt++;
  }
}

int search(Node *root, string s){
  Node *cur = root;
  for (char c : s){
    if (cur->child[c-'a'] == nullptr){
      return 0;
    }
    cur = cur->child[c - 'a'];
  }
  return cur->cnt;
}

int main(){
  cin >> n >> q;
  Node *root = new Node();
  for (int i = 0; i < n; i++){
    string s;
    cin >> s;
    add(root, s);
  }
  while(q--){
    string s;
    cin >> s;
    cout << search(root, s) << endl;
  }
  return 0;
}

