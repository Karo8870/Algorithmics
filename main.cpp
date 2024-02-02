#include <iostream>

using namespace std;

// Sortarea prin interclasare

int a[100];

void interclasare(int st, int mij, int dr) {
    int i = st, j = mij + 1, b[100], k = st;

    while (i <= mij && j <= dr) {
        if (a[i] < a[j]) {
            b[k++] = a[i++];
        } else {
            b[k++] = a[j++];
        }
    }

    for (; i <= mij; i++) {
        b[k++] = a[i];
    }

    for (; j <= dr; j++) {
        b[k++] = a[j];
    }

    for (i = st; i <= dr; i++) {
        a[i] = b[i];
    }
}

void merge(int st, int dr) {
    if (st == dr) {
        return;
    }

    int mij = (st + dr) / 2;

    merge(st, mij);
    merge(mij + 1, dr);

    interclasare(st, mij, dr);
}

void read(int &n) {
    cin >> n;

    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
}

void write(int &n) {
    for (int i = 0; i < n; i++) {
        cout << a[i] << ' ';
    }
}

int main() {
    int n;

    read(n);
    merge(0, n - 1);
    write(n);

    return 0;
}

// 7 4 2 1 5 9 3 =>

// 7 4 2 1 => (7 4) [4 7], (2, 1) [1 2]       [1 2 4 7] |
//                                                      | => [1, 2, 3, 4, 5, 7, 9]
// 5 9 3 => (5, 9) [5 9], 3 [3]               [3 5 9]   |