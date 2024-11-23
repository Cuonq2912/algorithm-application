//Thiết kế thuật toán T để tính tổng các số dương của một dãy số thực kích thước 
//n theo chiến lược chia để trị.
//- Cài đặt chương trình thực hiện:
//o Cài đặt hàm biểu diễn thuật toán T.
//o Khởi tạo danh sách a gồm tối thiểu 20 số thực.
//o Áp dụng thuật toán T để tính tổng các số dương trong danh sách a.
//o Hiển thị kết quả

#include<bits/stdc++.h>
using namespace std;

int sumPositiveInt(int *a, int l, int r){
	if(l == r){
		if(a[l] > 0) return a[l];
		else return 0;
	}
	int m = (l + r)/2;
	int sumL = sumPositiveInt(a, l, m);
	int sumR = sumPositiveInt(a, m +1, r);
	return sumL + sumR;
}

int main(){
	int n;
	do{
		cin >> n;
	}while(n < 5);
	
	int *a = new int[n];
	for(int i = 0; i < n; i++){
		cin >> a[i];
	}
	
	cout << sumPositiveInt(a, 0, n - 1);
	
	delete[] a;
	return 0;
}