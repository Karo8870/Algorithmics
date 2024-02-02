#include <iostream>

using namespace std;

// e numeste cautare binara cautarea unui element intr-un sir sortat.
// Aceasta se rezolva folosind un algoritm de tip divide et empera si anume:
// Se imparte sirul in jumatate si se verifica daca elementul din mijloc este egal cu elementul cautat.
// Daca da, atunci algoritmul se incheie.
// Daca nu, atunci algoritmul continua fie in pria jumatate daca elementul cautat este mai mic decat elementul din mijloc, fie in a doua jumatate in caz contrar

// Obs: Algoritmul se poate implementa atat recursiv cat si iterativ, dar se recomanda varianta iterativa

// x = 100
// a = (7, 12, 40, 100, 512):
// x > 40 => (100, 512)
// x = 100 => mij = 3

// x = 6
// a = (7, 12, 40, 100, 512):
// x < 40 => (7, 12)
// x < 7 => NU EXISTA

bool find(int &x, int &n, const int a[]) {
    for (int st = 0, dr = n - 1; st <= dr;) {
        int mij = (st + dr) / 2;

        if (a[mij] == x) {
            return true;
        }

        if (a[mij] < x) {
            st = mij + 1;
        } else {
            dr = mij - 1;
        }
    }

    return false;
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