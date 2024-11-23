//Liệt kê tập con k phần tử
//- Thiết kế thuật toán A5 để giải bài toán liệt kê tất cả các tập con k (0 < k ≤ n) phần 
//tử của tập S = {1, 2, …, n}, (n > 0) theo thứ tự từ điển bằng chiến lược đệ qui.
//- Cài đặt chương trình thực hiện.
//o Khởi tạo số nguyên dương n (1 ≤ n ≤ 10) và số nguyên dương k (0 < k ≤ 
//n).
//o Áp dụng thuật toán A5 để hiển thị ra màn hình tất cả các tập con k phần 
//tử của tập S = {1, 2, …, n} theo thứ tự từ điển.
//o Áp dụng thuật toán A5 để hiển thị ra màn hình tất cả các cách lấy ra 4 sinh 
//viên từ 6 sinh viên gồm: Trang, Cong, Trung, Binh, Hoan, Mai.

#include<bits/stdc++.h>
using namespace std;

string arr[] = {"Trang","Cong", "Trung", "Binh", "Hoan", "Mai"};

void next_config(int *x, int k, int i){
	x[i] += 1;
	i++;
	while(i <= k){
		x[i] = x[i - 1] + 1;
		i++;
	}
}
void show_config(int *x, int k){
	for(int i = 1; i <= k; i++){
//		cout << x[i] << " ";
		cout << arr[x[i] - 1] << " ";
	}
	cout << endl;
}

void list_configs(int k, int n){
	int i;
	int *x;
	x = new int[n + 1];
	for(int j = 1; j <= k; j++){
		x[j] = j;
	}
	do{
		show_config(x, k);
		i = k;
		while(i > 0 && x[i] == n - k + i) --i;
		if(i > 0) next_config(x, k, i);
	}while(i > 0);
}

int main(){
	int n, k; cin >> k >> n;
	list_configs(k, n);
}