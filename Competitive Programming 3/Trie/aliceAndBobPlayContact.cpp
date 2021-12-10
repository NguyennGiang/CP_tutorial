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
  vector <int> v;
  for (char c : s){
    if (cur->child[c-'a'] == nullptr){
      break;
    }
    cur = cur->child[c - 'a'];
    v.push_back(cur->cnt);
  }
  int ans = 0;
  for(int i = 1, j = v.size() - 1; j >= 0; j--){
    if (v[j] >= i){
      i++;
      ans++;
    }
  }
  return ans;
}

int main(){
  while(cin >> n >> q){
    Node *root = new Node();
    string a[n];
    for (int i = 0; i < n; i++){
      cin >> a[i];
    }
    while(q--){
      string s;
      cin >> s;
      add(root, s);
    }
    int ans = 0;
    for (int i = 0; i < n; i++){
      ans += search(root, a[i]);
    }
    cout << ans << endl;
  }
  return 0;
}
