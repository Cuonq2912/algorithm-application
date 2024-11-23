//Thiết kế thuật toán sắp xếp trộn S để sắp xếp dãy số thực có kích thước n (n > 0)
//theo chiều tăng dần bằng chiến lược chia để trị.
//- Cài đặt chương trình thực hiện:
//o Cài đặt hàm biểu diễn thuật toán S.
//o Khởi tạo mảng a gồm tối thiểu 15 số thực.
//o Sắp xếp mảng a theo chiều tăng dần bằng thuật toán S.
//o Hiển thị mảng a sau khi sắp xếp

#include<bits/stdc++.h>
using namespace std;

void merge(int *a, int l, int m , int r){
	int n1 = m - l + 1;
	int n2 = r - m;
	int L[n1], R[n2];
	for(int i = l; i < m + 1; i++){
		L[i - l] = a[i];
	}
	for(int i = m + 1; i <= r; i++){
		R[i -m - 1] = a[i];
	}
	int i = 0, j = 0, cnt = l;
	while(i < n1 && j < n2){
		if(L[i] <= R[j]){
			a[cnt++] = L[i++];
		}
		else{
			a[cnt++] = R[j++];
		}
	}
	while(i < n1) a[cnt++] = L[i++];
	while(j < n2) a[cnt++] = R[j++];
}

void mergeSort(int *a, int l, int r){
	if(l < r){
		int m = l + (r - l)/2;
		mergeSort(a, l, m);
		mergeSort(a, m + 1, r);
		merge(a, l, m, r);
	}
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
	
	mergeSort(a, 0, n - 1);
	
	for(int i = 0; i < n; i++){
		cout << a[i] << " ";
	}
	delete[] a;
	return 0;
}