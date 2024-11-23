#include <bits/stdc++.h>
using namespace std;

int dx[8] = {-2, -2, -1, -1, 1, 1, 2, 2};
int dy[8] = {-1, 1, -2, 2, -2, 2, -1, 1};

int **H;
int n;

void Try(int k, int x, int y, bool &success) {
    int u, v;
    success = false;
    for (int i = 0; i < 8; i++) {  // Iterate over all moves
        u = x + dx[i];
        v = y + dy[i];
        if (1 <= u && u <= n && 1 <= v && v <= n && !H[u][v]) {
            H[u][v] = k;  // Place the knight move
            if (k < n * n) {
                Try(k + 1, u, v, success);
                if (!success) H[u][v] = 0;  // Backtrack if unsuccessful
            } else {
                success = true;  // If k == n*n, solution found
            }
            if (success) break;
        }
    }
}

int main() {
    cin >> n;
    bool success = false;

    // Initialize the chessboard
    H = new int*[n + 1];
    for (int i = 1; i <= n; i++) {
        H[i] = new int[n + 1];
        fill(H[i], H[i] + n + 1, 0);
    }

    // Choose the starting position
    int x = 1, y = 1;
    H[x][y] = 1;

    // Start the knight's tour from the first move
    Try(2, x, y, success);

    if (success) {
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= n; j++) {
                cout << setw(3) << H[i][j];
            }
            cout << endl;
        }
    } else {
        cout << "Khong tim thay nuoc di!" << endl;
    }

    // Clean up memory
    for (int i = 1; i <= n; i++) {
        delete[] H[i];
    }
    delete[] H;

    return 0;
}
