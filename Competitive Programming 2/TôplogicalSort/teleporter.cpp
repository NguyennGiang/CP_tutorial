#include <bits/stdc++.h>
using namespace std;

int main() {
    int N; 
    long long K;
    cin >> N >> K;
    vector<int> A(N);
    for (int i = 0; i < N; ++i) cin >> A[i], --A[i];

    queue <int> a; 
    vector<bool> visited(N, false); 
    int cur = 0;
    while (true) {
        
        if (visited[cur]) {
            while (a.front() != cur) {
                --K;
                a.pop();

                if (K == 0) {
                    cout << a.front()+1 << endl;
                    return 0;
                }
            }
            break;
        }
        a.push(cur);
        visited[cur] = true;
        cur = A[cur];
    }

    int x = K % a.size();
    int id = 0;
    while(id != x){
    	id++;
    	a.pop();
    }
    cout << a.front() + 1 << endl;
}
