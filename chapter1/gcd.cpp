#include <bits/stdc++.h>
using namespace std;

int mygcd(int a, int b)
{
    cout << __gcd(a, b) << endl;
    while (b != 0) {
        int temp = a % b;
        a = b;
        b = temp;
    }
    return a;
}
int main()
{
    int a = mygcd(1284132, 88395987);
    cout << a << endl;
    return 0;
}