//Bài tập 3: Số chẵn nhỏ nhất.
//- Thiết kế thuật toán C để tìm và trả về số chẵn nhỏ nhất một dãy số nguyên kích 
//thước n theo chiến lược chia để trị.
//- Cài đặt chương trình thực hiện:
//o Cài đặt hàm biểu diễn thuật toán C.
//o Khởi tạo danh sách a gồm tối thiểu 20 số nguyên.
//o Áp dụng thuật toán C để tìm số chẵn nhỏ nhất trong danh sách a.
//- Hiển thị kết quả

#include<bits/stdc++.h>
using namespace std;


int solve(int *d, int l, int r){
	if(l == r){
		if(d[l] % 2 == 0) return d[l];
		else return INT_MAX;
	}
	int m = l + (r - l) /2;
	int L = solve(d, l, m);
	int R = solve(d, m + 1, r);
	return L < R ? L : R;
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
}