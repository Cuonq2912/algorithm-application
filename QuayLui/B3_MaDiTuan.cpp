#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define el "\n"

int dx[8] = {-2, -2, -1, -1, 1, 1, 2, 2};
int dy[8] = {-1, 1, -2, 2, -2, 2, -1, 1};

int n, a[1005][1005];

// bool showTable(int a, int n){
//     for(int i = 0; i < n; i++){
//         for(int j = 0; j < n; j++){
//             if(a[i][j] == 0) return true;
//         }
//     }
//     return false;
// }

void Try(int i, int j){
    a[i][j] = 0;
    for(int k = 0; k < 8; k++){
        int inew = i + dx[i], jnew = j + dy[k];
        if(inew > 0 && jnew > 0 && inew <= n && jnew <= n){
            Try(inew, jnew);
        }    
    }
}
int main(){
    cin >> n;
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= n; j++){
            a[i][j] = 1;
        }
    }
    Try(0, 0);
    if(a[n][n] == 0) cout << "YES";
    else cout << "NO";
    return 0;
}