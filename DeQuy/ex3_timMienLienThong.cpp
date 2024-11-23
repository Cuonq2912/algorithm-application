#include<bits/stdc++.h>
using namespace std;

using ll = long long;
#define el "\n"

void loang(int **O, bool **used, int i, int j, int m, int n){
	used[i][j] = true;
	if(i > 0){
		if(!used[i - 1][j] && O[i - 1][j] == O[i][j]){
			loang(O, used, i - 1, j, m, n);
		}
	}
	if(j > 0){
		if(!used[i][j - 1] && O[i][j - 1] == O[i][j]){
			loang(O, used, i, j - 1, m, n);
		}
	}
	if(i < m - 1){
		if(!used[i + 1][j] && O[i + 1][j] == O[i][j]){
			loang(O, used, i + 1, j, m, n);
		}
	}
	if(j < n - 1){
		if(!used[i][j + 1] && O[i][j + 1] == O[i][j]){
			loang(O, used, i, j + 1, m, n);
		}
	}
}

int dem_mien_lt(int **O, int m, int n){
	bool **used = new bool*[m];
	for(int i = 0; i < m; i++){
		used[i] = new bool[n];
		for(int j = 0; j < n; j++){
			used[i][j] = false;
		}
	}
	int cnt = 0;
	for(int i = 0; i < m; i++){
		for(int j = 0; j < n; j++){
			if(!used[i][j]){
				cnt++;
				loang(O, used, i, j, m, n);
			}
		}
	}
	return cnt;
}

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int **O, m, n;
	cin >> m >> n;
	int so_mien = 0;
	O = new int*[m];
	for(int i = 0; i < m; i++){
		O[i] = new int[n];
		for(int j = 0; j < n; j++){
			cin >> O[i][j];
		}
	}
	so_mien = dem_mien_lt(O, m, n);
	cout << "So mien lien thong la: " << so_mien << el;
	
	for(int i = 0; i < m; i++){
		delete[] O[i];
	}
	delete[] O;
}