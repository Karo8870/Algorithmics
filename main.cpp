#include<fstream>

using namespace std;

ifstream cin("bile1.in");
ofstream cout("bile1.out");

typedef int big[300];

void bigDouble(big x) {
    int i, t = 0;
    for (i = 1; i <= x[0]; i++, t /= 10) {
        t += x[i] << 1;
        x[i] = t % 10;
    }
    for (; t; t /= 10) {
        x[++x[0]] = t % 10;
    }
}

void write(big x) {
    for (int i = x[0]; i; --i) {
        cout << x[i];
    }
}

int main() {
    int n;
    cin >> n;

    big res;

    res[0] = 1;
    res[1] = 3;

    for (int i = 1; i < n; ++i) {
        bigDouble(res);
    }


    write(res);
    return 0;
}