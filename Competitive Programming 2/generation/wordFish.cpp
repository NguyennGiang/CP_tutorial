#include <bits/stdc++.h>

using namespace std;

int computeDist(string &s){
    int dist = 99999;
    for(int i = 1; i < s.length(); i++){
        dist = min(dist, abs(s[i] - s[i-1]));
    }
    return dist;
}

int main() {
    string s;

    while(cin >> s){
        string bestString = s;
        int bestDist = computeDist(s);
        string pre = s;
        string next = s;
        bool hasPre = true;
        bool hasNext = true;
        
        for (int i = 0; i < 10; i++){
            hasPre = hasPre ? prev_permutation(pre.begin(), pre.end()) : false;
            hasNext = hasNext ? next_permutation(next.begin(), next.end()) : false;

            int dist = computeDist(pre);
            if (hasPre && dist >= bestDist){
                bestDist = dist;
                bestString = pre;
            }

            dist = computeDist(next);
            if (hasNext && dist > bestDist){
                bestDist = dist;
                bestString = next;
            }
        }
        cout << bestString << bestDist << endl;    
    }   
    return 0;
}