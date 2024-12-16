#include<bits/stdc++.h>
using namespace std;
// Bài 1: Khởi tạo số nguyên dương k và mảng a gồm ít nhất 15 số nguyên. 
// Tìm số nhỏ nhất m trong mảng a sao cho m > k
// bằng chiến lược đệ quy/ chia để trị.
int find_dq(int a[], int n, int k){
	if(n == 0) return -1;
	else{
		if(a[n - 1] > k) return a[n - 1];
		return find_dq(a, n - 1, k);
	}
}

int find_cdt(int a[], int n, int l, int r, int k){
	if(l > r) return -1;
	if(l == r){
		if(a[l] > k) return a[l];
		else return a[n - 1] + 1;
	}
	else{		
		int m = (l + r)/2;
		int x = find_cdt(a, n, l, m, k);
		int y = find_cdt(a, n, m + 1, r, k);
		return x < y ? x : y;
	}
}
int main(){
	int n = 15;
	int k = 16;
	int a[n] = {15,14,13,12,11,10,9,8,7,6,5,4,3,2,1};
	int b[n] = {1,2,3,4,5,6,7,8,9,10,11,12,13,14,15};
	int ans_dq = find_dq(a, n, k);
	if(ans_dq > 0){
		cout << "So nho nhat trong mang > k: " << ans_dq << endl;
	} else cout << "Khong co dap an";
	
	int ans_cdt = find_cdt(b, n, 0, n - 1, k);
	if(ans_cdt > 0){
		cout << "So nho nhat trong mang > k: " << ans_dq << endl;
	} else cout << "Khong co dap an";
}