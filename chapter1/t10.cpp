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
    // 8x + 15y = 2
    int a = 8, b = 15, c = 2;
    if (c % __gcd(a, b) != 0) {
        cout << "no answer" << endl;
        return 0;
    }
    int s, t;
    int g = e_gcd(a, b, s, t);
    int x0 = c / g * s, y0 = c / g * t;
    cout << "x = " << x0 << "+" << b / g << "n" << endl;
    cout << "y = " << y0 << "-" << a / g << "n" << endl;
    return 0;
}