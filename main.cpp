#include<fstream>
using namespace std;

ifstream cin("necuatie.in");
ofstream cout("necuatie.out");

using namespace std;

#define MOD 555557

long long modPow(long long x, long long e) {
    long long r = 1;
    for (; e; e >>= 1) {
        if (e & 1)
            r = (r * x) % MOD;
        x = (x * x) % MOD;
    }
    return r % MOD;
}

int fact(const long long &n) {
    int P = 1;

    for (int i = 2; i <= n; ++i) {
        P = P * i % MOD;
    }

    return P;
}

long long square(const long long n) {
    return n * n % MOD;
}

long long perms(const int n, const int zeros, const int ones) {
    const long long top = fact(n);
    const long long bottom = (fact(zeros) * square(fact(ones))) % MOD;
    long long invMod = modPow(bottom, MOD - 2);
    return top * invMod % MOD;
}

long long solve(const int &n) {
    long long S = 0;

    const long long halfN = n / 2;

    for (int i = 0; i <= halfN; ++i) {
        S = (S + perms(n, n - 2 * i, i)) % MOD;
    }

    return S;
}

int main() {
    int n;

    cin >> n;
    cout << solve(n);

    return 0;
}