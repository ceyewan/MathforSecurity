#include <bits/stdc++.h>
using namespace std;

// 模重复平方
int func1(long long b, long long n, long long m)
{
    vector<int> v;
    while (n > 0) {
        v.push_back(n % 2);
        n /= 2;
    }
    long long a = 1;
    for (int i = 0; i < v.size(); i++) {
        if (v[i] == 1) {
            a = a * b % m;
        } else {
            a = a % m;
        }
        b = b * b % m;
    }
    return a;
}
// 二分
int func2(long long b, long long n, long long m)
{
    if (n == 1) {
        return b % m;
    }
    if (n % 2 == 0) {
        long long ans = func2(b, n / 2, m);
        ans = ans * ans % m;
        return ans;
    } else {
        long long ans = func2(b, n / 2, m);
        ans = ans * ans % m;
        ans = ans * b % m;
        return ans;
    }
}
int main()
{
    // 129965232^22733898 (mod 37909896)
    long long b = 129965232, n = 22733898, m = 37909896;
    int start = clock();
    int a = func1(b, n, m);
    cout << a << endl;
    int end = clock();
    cout << (double)(end - start) / CLOCKS_PER_SEC << "s" << endl;
    start = clock();
    a = func2(b, n, m);
    cout << a << endl;
    end = clock();
    cout << (double)(end - start) / CLOCKS_PER_SEC << "s" << endl;
    return 0;
}