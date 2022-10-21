#include <iostream>
#include <vector>

using namespace std;
using ll = long long;

const ll mod = 1000000007LL;

int main() {

    ll n;
    cin >> n;

    vector<ll> a(n + 1);

    for (ll i = 1; i <= n; ++i)
        cin >> a[i];
        
    if (a[1] != 0 && a[1] != -1) {
        cout << 0 << endl;
        return 0;
    }

    vector<ll> num_of_prime_factor(n + 1, 0);
    vector<ll> prime_factor(n + 1, 0);

    ll res = 1;

    for (ll i = 2; i <= n; ++i) {
        for (ll j = 2 * i; j <= n; j += i) {
            if (num_of_prime_factor[i] == 0) {
                num_of_prime_factor[j]++;
                prime_factor[j] = i;
            }
            if (a[j] != -1) {
                if(a[i] == -1)
                    a[i] = a[j] % i;
                else if (a[i] != a[j] % i) {
                    cout << 0 << endl;
                    return 0;
                }
            }
        }
        if (num_of_prime_factor[i] == 0 && a[i] == -1) { // i là số nguyên tố, có thể chọn từ 0 --> i - 1;
            res = (res * i) % mod;
        }

        if (num_of_prime_factor[i] == 1 && a[i] == -1) {  // i có duy nhất 1 ước là nguyên tố
            res = (res * prime_factor[i]) % mod;
        }
    }
    cout << res << endl;

    return 0;
}