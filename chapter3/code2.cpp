#include <bits/stdc++.h>
using namespace std;

int e_gcd(int a, int b, int& x, int& y)
{
    if (b == 0) {
        x = 1, y = 0;
        return a;
    }
    int x1;
    int d = e_gcd(b, a % b, x1, x);
    y = x1 - a / b * x;
    return d;
}

void func(vector<int>& b, vector<int>& m)
{
    long long sum = 1;
    for (auto temp : m) {
        sum *= temp;
    }
    vector<int> M(m.size());
    for (int i = 0; i < m.size(); i++) {
        M[i] = sum / m[i];
    }
    vector<int> c(m.size());
    for (int i = 0; i < m.size(); i++) {
        int temp;
        e_gcd(M[i], m[i], c[i], temp);
    }
    long long ans = 0;
    for (int i = 0; i < m.size(); i++) {
        ans += b[i] * M[i] * c[i];
        ans %= sum;
    }
    cout << "answer is x = " << ans << " + " << sum << "k" << endl;
}
int main()
{
    vector<int> b { 2, 3, 2 };
    vector<int> m { 3, 5, 7 };
    // to do 验证 m 中元素互素
    func(b, m);
    return 0;
}