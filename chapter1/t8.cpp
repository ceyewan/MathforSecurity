#include <bits/stdc++.h>
using namespace std;
#define MAX 100000000

// 筛法筛选出素数，然后不断整除素数
int Eratoshenes(vector<int>& primes, int n)
{
    int* temp = (int*)malloc(sizeof(int) * n);
    memset(temp, 0, sizeof(int) * n);
    for (int i = 2; i <= sqrt(n); i++) {
        if (temp[i] == 0) {
            cout << i << endl;
            for (int j = 2; i * j < n; j++) {
                temp[i * j] = 1;
            }
        }
    }
    for (int i = 2; i < n; i++) {
        if (temp[i] == 0) {
            primes.push_back(i);
        }
    }
    return 0;
}
int main()
{
    vector<int> primes;
    Eratoshenes(primes, MAX);
    int n = 53169;
    vector<int> v;
    for (int i = 1; i * n < MAX; i++) {
        int temp = i * n;
        v.clear();
        while (temp > 1) {
            for (int i = 0; i < primes.size(); i++) {
                while (temp > 1 && temp % primes[i] == 0) {
                    v.push_back(primes[i]);
                    temp /= primes[i];
                    cout << temp << " " << primes[i] << endl;
                }
            }
        }
        long long sum = 1;
        for (int i = 0; i < v.size(); i++)
            sum *= v[i];
        do {
            long long a = 1, b = 1;
            for (int j = 0; j < v.size(); j++) {
                a *= v[j];
                b = sum / a;
                if ((a + b) % (2 * n) != 0 && abs(a - b) % (2 * n) != 0) {
                    int c = (a + b) / 2, d = abs(a - b) / 2;
                    if (__gcd(n, c) != 1 && __gcd(n, c) != n && __gcd(n, d) != 1 && __gcd(n, d) != n) {
                        cout << i * n << " " << c << " " << d << endl;
                        return 0;
                    }
                }
            }
        } while (next_permutation(v.begin(), v.end()));
    }
    return 0;
}