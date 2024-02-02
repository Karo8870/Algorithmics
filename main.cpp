#include <iostream>

using namespace std;

// Să se afle poziția celui mai mic element care este mai mare decât X

// a = (7, 10, 40, 50, 100, 500, 600)
// X = 30

// st = 0, dr = 6, mij = 3 => a[3] = 50 > x => poz = 3 -> mergem în stânga
// st = 0, dr = 2, mij = 1 => a[1] = 10 < x -> mergem în stânga
// st = 2, dr = 2, mij = 2 => a[2] = 4o > x => poz = 2 -> mergem în stânga
// st = 2, dr = 1 => STOP


// X = 700 =>


int find(int &x, int &n, const int a[]) {
    int poz;

    for (int st = 0, dr = n - 1; st <= dr;) {
        int mij = (st + dr) / 2;

        if (a[mij] > x) {
            dr = mij - 1;
            poz = mij;
        } else {
            st = mij + 1;
        }
    }

    return poz;
}

void read(int &x, int &n, int a[]) {
    cin >> x >> n;

    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
}

int main() {
    int n, x, a[100];

    read(x, n, a);
    cout << find(x, n, a);

    return 0;
}