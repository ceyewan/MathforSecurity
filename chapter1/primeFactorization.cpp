#include <bits/stdc++.h>
using namespace std;

// 筛法筛选出素数，然后不断整除素数
int Eratoshenes(vector<int>& primes, int n)
{
    vector<int> temp(n, 1);
    for (int i = 2; i <= sqrt(n); i++) {
        if (temp[i] == 1) {
            for (int j = 2; i * j <= n; j++) {
                temp[i * j] = 0;
            }
        }
    }
    for (int i = 2; i < n; i++) {
        if (temp[i] == 1) {
            primes.push_back(i);
        }
    }
    return 0;
}
int main()
{
    vector<int> primes;
    Eratoshenes(primes, 100000000);
    // cout << primes.size() << endl;
    vector<int> v;
    long long a = 6987238;
    while (a > 1) {
        for (int i = 0; i < primes.size(); i++) {
            while (a > 1 && a % primes[i] == 0) {
                v.push_back(primes[i]);
                a /= primes[i];
                cout << a << " " << primes[i] << endl;
            }
        }
    }
    for (int i = 0; i < v.size(); i++) {
        cout << v[i] << " ";
    }
    cout << endl;
    return 0;
}