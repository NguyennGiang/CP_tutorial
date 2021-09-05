    #include <bits/stdc++.h>
    using namespace std;

    string solve(string s){
        if (s.length() & 1){
            return s;
        }
        string x = solve(s.substr(0, s.length() / 2));
        string y = solve(s.substr(s.length() / 2));
        return min(x + y, y + x);

    }

    bool isEquivalent(string a, string b){
        if (solve(a) == solve(b)){
            return true;
        }
        return false;
    }

    int main(){
        string a, b;
        cin >> a >> b;
        if (isEquivalent(a, b)){
            cout << "YES\n";
        }
        else {
            cout << "NO\n"; 
        }
        return 0;
    }