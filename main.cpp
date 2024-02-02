#include<iostream>

using namespace std;

void read(int &n, int prices[]) {
    cin >> n;

    for (int i = 1; i <= n; i++) {
        cin >> prices[i];
    }
}

int solve(int p[], int &n) {
    int r[100];
    r[0] = 0;

    for (int l = 1; l <= n; l++) {
        int optimal_value = INT_MIN;

        for (int i = 1; i <= l; i++) {
            optimal_value = max(optimal_value, p[i] + r[l - i]);
            // Tai o bucata de lungime i din bara (p[i]) si iau impartirea optima pentru bucata de lungime l - i (r[l - i])
        }

        r[l] = optimal_value; // Profitul maxim pentru lungimea l este optimal_value
    }

    return r[n];
}

int main() {
    int n, prices[100];

    read(n, prices);

    cout << solve(prices, n);

    return 0;
}