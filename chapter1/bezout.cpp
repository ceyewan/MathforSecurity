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
    int a = 2507988, b = 57275298;
    int s, t;
    int c = e_gcd(a, b, s, t);

    cout << s << " * " << a << " + " << t << " * " << b << " = " << c << endl;
    cout << s * a + t * b << endl;
    return 0;
}