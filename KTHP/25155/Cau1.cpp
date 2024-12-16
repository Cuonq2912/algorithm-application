//1:49: 2:08
#include<bits/stdc++.h>
using namespace std;

int find(double a[], int l, int r, double &k){
	if(l > r) return -1;
	if(l == r){
		if(a[l] == k) return l;
		else return -1;
	}
	else{
		int m = (l + r)/2;
		int x = find(a, l, m, k);
		int y = find(a, m + 1, r ,k);
		if(x >= 0) return x;
		if(y >= 0) return y;
	}
}

int main(){
	int n = 14;
	double a[n] = {1.3, 2.5, 3.6, 4.7, 7.8, 8.9, 10.11, 13.4, 16.7, 19.6, 20.3, 22.4, 35.1, 36.9};
	double k = 1.3;
	int ans = find(a, 0, n - 1, k);
	if(ans >= 0){
		cout << "Vi tri cua " << k << " trong danh sach la vi tri co chỉ số là: " << ans << endl;
	}
	else cout << k <<" khong xuat hien trong danh sach";
	return 0;
}
