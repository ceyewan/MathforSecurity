#include <bits/stdc++.h>
using namespace std;

int func(int m)
{
    int count = 1;
    for (int i = 2; i < m; i++) {
        if (__gcd(i, m) == 1) {
            count++;
        }
    }
    return count;
}

// 筛法求素数
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
int eular(vector<int>& primes, int m)
{
    int ans = m;
    for (auto p : primes) {
        if (m % p == 0) {
            ans = ans / p * (p - 1);
            while (m % p == 0) {
                m /= p;
            }
        }
    }
    return ans;
}
int main()
{
    int m = 12345678;
    int start = clock();
    int a = func(m); // 定义法
    cout << a << endl;
    int end = clock();
    cout << (double)(end - start) / CLOCKS_PER_SEC << "s" << endl;
    start = clock();
    vector<int> primes;
    Eratoshenes(primes, m);
    int b = eular(primes, m);
    cout << b << endl;
    end = clock();
    cout << (double)(end - start) / CLOCKS_PER_SEC << "s" << endl;
    return 0;
}
// 不算求素数表的时间
// 4027392
// 1.84151s
// 4027392
// 0.008743s
// 算上求素数表的时间
// 4027392
// 1.77208s
// 4027392
// 0.243246s