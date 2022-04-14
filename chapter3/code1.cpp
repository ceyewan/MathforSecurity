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

int main()
{
    // 42x = 12(mod 33)
    int a = 42, b = 12, m = 33;
    int g = __gcd(a, m);
    if (b % g != 0) {
        cout << "no answer" << endl;
        return 0;
    }
    // 求解 14x = 1(mod 11) 的一个特解
    // 也就是 14x - 11y = 1
    int x = 0, y = 0;
    e_gcd(a / g, m / g, x, y);
    cout << x << endl;
    x = b / g * x % (m / g);
    cout << "answer is x = " << x << " + " << m / g << " * t(mod " << m << ")" << endl;
    return 0;
}