#include<bits/stdc++.h>
using namespace std;

int Min(int a, int b){
	return a <= b ? a : b;
}

int A1(int a[], int l, int r){
	if(l == r) return a[l];
	int mid = l + (r - l)/2;
	int min_left = A1(a, l, mid);
	int min_right = A1(a, mid + 1, r);
	return Min(min_left, min_right);	
}

int A2(int a[], int l, int r){
	if(l == r){
		if(a[l] % 2 == 0) return 1;
		else return 0;
	}
	int m = l + (r - l)/2;
	int cnt_left = A2(a, l, m);
	int cnt_right = A2(a, m + 1, r);
	return cnt_left + cnt_right;
}

using ll = long long;
ll A3(int a[], int l, int r){
	if(l == r){
		if(a[l] % 2 != 0) return a[l];
		else return 0;
	}
	int m = l + (r - l)/2;
	ll sum_left = A3(a, l, m);
	ll sum_right = A3(a, m + 1, r);
	return sum_left + sum_right;
}

int main(){
	int n; cin >> n;
	int a[n];
	for(int i = 0; i < n; i++){
		cin >> a[i];
	}
	cout << "giá trị nhỏ nhất trong dãy số là: " << A1(a, 0, n - 1);
	cout << "\nsố lượng các số chẵn trong một dãy số là: " << A2(a, 0, n - 1);
	cout << "\ntổng các số lẻ trong dãy số là: " << A3(a, 0, n - 1);
}