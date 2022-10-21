#include <bits/stdc++.h>
using namespace std;

const int N = 100;
const int INF = 1e9;
int cap[N][N];
int flow[N][N];
int parent[N];
vector<int> graph[N];

int bfs(int s, int t){
    memset(parent, -1, sizeof(parent));
    parent[s] = -2;
    queue<pair<int, int>> q;
    q.push({s, INF});
    while(!q.empty()){
        int u = q.front().first, f = q.front().second;
        q.pop();

        for (int v : graph[u]){
            if (parent[v] == -1 && cap[u][v] > flow[u][v]){
                parent[v] = u;
                int newFlow = min(f, cap[u][v] - flow[u][v]);
                if (v == t) return newFlow;
                q.push({v, newFlow});
            }
        }
    }
    return 0;
}

int edmonsKarp(int s, int t){
    int new_flow, sum_flow = 0;
    int cnt = 0;
    while(new_flow = bfs(s, t) != 0){
        sum_flow += new_flow;
        int pre, cur = t;
        while(cur != s){
            pre = parent[cur];
            flow[pre][cur] += new_flow;
            flow[cur][pre] -= new_flow;
            cur = pre;
        }
    }
    return sum_flow;
}

int main(){
    int e; cin >> e;

    for (int i = 0; i < e; i++){
        char a, b;
        int w;
        cin >> a >> b >> w;
        graph[a - 'A'].push_back(b - 'A');
        graph[b - 'A'].push_back(a - 'A');
        cap[a - 'A'][b - 'A'] = w;
    }
    int start = 'S' - 'A';
    int end = 'T' - 'A';
    cout << edmonsKarp(start, end);
    return 0;
}