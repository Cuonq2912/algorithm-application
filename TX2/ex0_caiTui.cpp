#include <bits/stdc++.h>

using namespace std;

// Struct to represent each package
struct goihang {
    int w; // Weight
    int v; // Value
};

// Struct to store the result
struct ketqua {
    int u = 0; // Number of items in the knapsack
    vector<goihang> d; // List of items in the knapsack
};

// Function to solve the 0/1 Knapsack problem
void al(goihang x[], int n, int m, ketqua &result) {
	
    goihang x_new[n + 1];
    x_new[0] = {0, 0};
    for (int i = 0; i < n; i++) {
        x_new[i + 1] = x[i];
    }

    // Initialize the DP table
    int F[n + 1][m + 1];
    for (int j = 0; j <= m; j++) {
        F[0][j] = 0;
    }

    // Fill the DP table
    for (int i = 1; i <= n; i++) {
        for (int j = 0; j <= m; j++) {
            F[i][j] = F[i - 1][j];
            if (x_new[i].w <= j) {
                int temp = x_new[i].v + F[i - 1][j - x_new[i].w];
                if (F[i][j] < temp) {
                    F[i][j] = temp;			
                }
            }
        }
    }

    // Traceback to find the selected items
    int i = n, j = m;
    while (i != 0) {
        if (F[i][j] != F[i - 1][j]) {
            result.d.push_back(x_new[i]);
            result.u++;
            j -= x_new[i].w;
        }
        i--;
    }
}

int main() {
    int n = 5; // Number of packages
    int m = 7; // Capacity of the knapsack

    goihang x[n] = {
        {7, 100},
        {3, 50},
        {1, 40},
        {3, 90},
        {10, 50}
    };

    ketqua result;
    al(x, n, m, result);

    cout << "Các gói hàng được chọn:\n";
    for (auto item : result.d) {
        cout << "Trọng lượng = " << item.w << ", Giá trị = " << item.v << '\n';
    }			
    cout << "Tổng số gói hàng được chọn: " << result.u << '\n';

    return 0;
}
