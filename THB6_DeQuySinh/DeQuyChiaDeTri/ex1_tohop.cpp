#include<bits/stdc++.h>
using namespace std;

using ll = long long;
#define el "\n"

int **d;
int C(int k, int n){
	if(k == 0 || k == n) d[k][n] = 1;
	else{
		if(d[k][n] < 0){
			d[k][n] = C(k, n - 1) + C(k - 1, n - 1);
		}
	}
	return d[k][n];
}

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int k, n; cin >> k >> n;
	d = new int*[k + 1];
	for(int i = 0; i <= k; i++){
		d[i] = new int[n + 1];
		for(int j = 0; j < n + 1; j++){
			d[i][j] = -1;
		}
	}
	cout << "To hop chap " << k << " cua " << n << " phan tu la: " << C(k, n);
	for(int i = 0; i <= k; i++){
		delete[] d[i];
	}
	delete[] d;
	return 0;
}