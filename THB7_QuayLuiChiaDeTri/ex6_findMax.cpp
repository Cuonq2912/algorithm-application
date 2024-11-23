//Thiết kế thuật toán M tìm giá trị lớn nhất của một dãy a gồm n số thực theo chiến 
//lược chia để trị.
//- Cài đặt chương trình thực hiện:
//o Cài đặt hàm biểu diễn thuật toán M.
//o Khởi tạo danh sách a gồm tối thiểu 15 số thực.
//o Áp dụng thuật toán M để tìm giá trị lớn nhất của danh sách a.
//o Hiển thị kết quả.

#include<bits/stdc++.h>
using namespace std;

int findMax(int *a, int l, int r){
	if(l == r) return a[l];
	int m = (l + r)/2;
	int max_left = findMax(a, l, m);
	int max_right = findMax(a, m + 1, r);
	return max_left > max_right ? max_left : max_right;
}

int main(){
	int n;
	
	do{
		cin >> n;
	}while(n < 15);
	
	int *a = new int[n + 1];
	for(int i = 0; i < n; i++){
		cin >> a[i];
	}
	int max_val = findMax(a, 0, n - 1);
	cout << "---" << max_val;
	delete[] a;
	return 0;
}