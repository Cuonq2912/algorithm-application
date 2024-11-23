#include <bits/stdc++.h>
using namespace std;

void loang(int **O, bool **used, int i, int j, int m, int n) {
    used[i][j] = true;
    if (i > 0 && !used[i - 1][j] && O[i - 1][j] == O[i][j]) {
        loang(O, used, i - 1, j, m, n);
    }
    if (j > 0 && !used[i][j - 1] && O[i][j - 1] == O[i][j]) {
        loang(O, used, i, j - 1, m, n);
    }
    if (i < m - 1 && !used[i + 1][j] && O[i + 1][j] == O[i][j]) {
        loang(O, used, i + 1, j, m, n);
    }
    if (j < n - 1 && !used[i][j + 1] && O[i][j + 1] == O[i][j]) {
        loang(O, used, i, j + 1, m, n);
    }
}

int dem_so_mien_lt(int **O, int m, int n) {
    bool **used = new bool*[m];
    for (int i = 0; i < m; i++) {
        used[i] = new bool[n];
        fill(used[i], used[i] + n, false);
    }
    
    int so_mien = 0;
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            if (!used[i][j] && O[i][j] == 5) {
                so_mien++;
                loang(O, used, i, j, m, n);
            }
        }
    }

    // Deallocate the memory for used array
    for (int i = 0; i < m; i++) {
        delete[] used[i];
    }
    delete[] used;

    return so_mien;
}

int main() {
    int m = 12, n = 12;
    int **O = new int*[m];
    
    fstream fs;
    fs.open("INPUT.TXT", ios::in);
    if (!fs) {
        cerr << "Failed to open INPUT.TXT" << endl;
        return 1;
    }

    for (int i = 0; i < m; i++) {
        O[i] = new int[n];
        for (int j = 0; j < n; j++) {
            fs >> O[i][j];
        }
    }
    fs.close();

    int so_mien = dem_so_mien_lt(O, m, n);
    cout << "So mien lien thong cua luoi la: " << so_mien << endl;

    // Deallocate memory for O array
    for (int i = 0; i < m; i++) {
        delete[] O[i];
    }
    delete[] O;

    return 0;
}
