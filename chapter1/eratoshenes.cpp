#include <bits/stdc++.h>
using namespace std;

int Eratoshenes(int n)
{
    vector<int> primes(n, 1);
    for (int i = 2; i <= sqrt(n); i++) {
        if (primes[i] == 1) {
            for (int j = 2; i * j <= n; j++) {
                primes[i * j] = 0;
            }
        }
    }
    int count = 0;
    for (int i = 1; i <= n; i++) {
        if (primes[i] == 1) {
            // cout << i << " ";
            count++;
            if (count % 10 == 0) {
                // cout << endl;
            }
        }
    }
    return count;
}
int normal(int n)
{
    vector<int> primes(n, 1);
    for (int i = 2; i <= n; i++) {
        for (int j = 2; j <= sqrt(i); j++) {
            if (i % j == 0) {
                primes[i] = 0;
                break;
            }
        }
    }
    int count = 0;
    for (int i = 1; i <= n; i++) {
        if (primes[i] == 1) {
            // cout << i << " ";
            count++;
            if (count % 10 == 0) {
                // cout << endl;
            }
        }
    }
    return count;
}
int main()
{
    int start = clock();
    int a = Eratoshenes(1000000);
    int end = clock();
    cout << ((double)(end - start) / CLOCKS_PER_SEC) << endl; // 0.019914
    start = clock();
    int b = normal(1000000);
    end = clock();
    cout << ((double)(end - start) / CLOCKS_PER_SEC) << endl; // 0.370031
    cout << (a == b) << endl; // 1
    return 0;
}