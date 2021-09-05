#include <bits/stdc++.h>
using namespace std;

int main() {
    // candy
    string a[16];
    a[0] = "Unknown candy bar!";
    a[1] = "Planters";
    a[2] = "Reeses_Pieces";
    a[3] = a[0];
    a[4] = "Sugar_Babies";
    a[5] = "Pay_Day";
    a[6] = a[0];
    a[7] = a[0];
    a[8] = "Hersheys";
    a[9] = "Goobers";
    a[10] = "Reeses_Cups";
    a[11] = "Nutrageous";
    a[12] = "Caramello";
    a[13] = "Baby_Ruth";
    a[14] = "Milky_Way";
    a[15] = "Snickers";
    int n;
    cin >> n;
    
    getchar();
    while(n--){
        string s;
        getline(cin, s);
        int Not = 0;
        int And = 1;
        int Or = 0;
        vector <int> container;
        // (Caramello & Pay_Day) | a & b
        int aValue = 0xF;
        string t = "";
        s += " ";
        for (int i = 0; i < s.size(); i++){
            if (s[i] == '~') {
                Not = 1 - Not;
                t = "";
            }
            else if (s[i] ==  ' ' ) {
            if (t == "") continue;
            int index = -1;
            for (int i = 0; i < 16; i++){
                if (a[i] == t) {
                    index = i;
                    if(Not == 1) index = (~index) & 0xF;
                    break;
                }
            }
            if (And) {
                aValue &= index;
            }
            if (Or) {
                container.push_back(aValue);
                aValue = index;
            }

            // check index here if t != "";
            And = 0;
            Or = 0;
            Not = 0;
            t = "";
            }
            else if (s[i] == '|') {
                Or = 1;
            }
            else if (s[i] == '&') {
                And = 1;
            }
            else {
                t += s[i];
            }
        }
        container.push_back(aValue);
        int ans = 0; 
        for (auto i: container) {
            ans = ans | i;
        }
        cout << a[ans] << endl;
    }
    return 0;
}
