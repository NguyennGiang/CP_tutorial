#include<bits/stdc++.h>
using namespace std;
#define KAMEHAMEHA ios_base::sync_with_stdio(0); cin.tie(0);
#define f first
#define s second
const int N = 5e5 + 5;

struct Trie {
    Trie* next[26];
    int leaf, count;
    string store;
    Trie(){
        leaf = 0, count = 0;
        for (int i = 0; i < 26; i++){
            next[i] = NULL;
        }
    }
};

string s;
int val;

void build(int pos, int n, Trie* root){
    if(pos == n){
        root->leaf++;
        val = root->leaf;
        if (root->count < root->leaf){
            root->count = root->leaf;
            root->store = s;
        }
        else if (root->count == root->leaf){
            root->store = min(root->store, s);
        }
        return;
    }
    int c = s[pos] - 'a';
    if (root->next[c] == NULL){
        root->next[c] = new Trie();
    }
    build(pos + 1, n, root->next[c]);
    if (root->count < val){
        root->store = s;
        root->count = val;
    }
    else if(root->count == val){
        root->store = min(s, root->store);
    }
}

pair <int, string> query(Trie* root){
    for (int i = 0; i < s.length(); i++){
        int c = s[i] - 'a';
        if (root->next[c] == NULL) return {0, ""};
        root = root->next[c];
    }
    return {root->count, root->store};
}

int main(){
    KAMEHAMEHA

    Trie* root = new Trie();
    int n; cin >> n;
    for (int i = 0; i < n; i++){
        cin >> s;
        build(0, int(s.length()), root);
    }
    cin >> n;
    while(n--){
        cin >> s;
        pair<int, string> res = query(root);
        if (res.f == 0) cout << -1 << endl;
        else cout << res.s << " " << res.f << endl;
    }
    return 0;
}

