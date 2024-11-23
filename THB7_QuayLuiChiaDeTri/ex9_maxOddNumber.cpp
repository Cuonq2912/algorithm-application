//Thiết kế thuật toán D để tìm và trả về số lẻ lớn nhất một dãy số nguyên kích 
//thước n theo chiến lược chia để trị.
//- Cài đặt chương trình thực hiện:
//o Cài đặt hàm biểu diễn thuật toán D.
//o Khởi tạo danh sách a gồm tối thiểu 20 số nguyên.
//o Áp dụng thuật toán D để tìm số lẻ lớn nhất trong danh sách a.
//o Hiển thị kết quả.

#include<bits/stdc++.h>
using namespace std;

int solve(int *d, int l, int r){
	if(l == r){
		if(d[l] % 2 != 0) return d[l];
		else return INT_MIN;
	}
	int m = (l + r)/2;
	int sL = solve(d, l, m);
	int sR = solve(d, m + 1, r);
	return sL > sR ? sL : sR;
}


int main(){
	int n;
	cin >> n;
	
	int *d = new int[n + 1];
	for(int i = 0; i < n; i++){
		cin >> d[i];
	}
	cout << solve(d, 0, n - 1);
	
	delete[] d;
	return 0;
}