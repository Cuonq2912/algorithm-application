//Biểu diễn thuật toán loang giải quyết bài toán tìm miền liên thông bằng mã giả.
//Cài đặt chương trình thực hiện:
//− Khởi tạo lưới L (mảng 2 chiều) kích thước 12 x 12 gồm các số ngẫu nhiên trong 
//đoạn [1, 5], hiển thị lưới. 
//− Cài đặt thuật toán đếm số miền liên thông của lưới L. Ứng dụng thuật toán và biểu 
//diễn kết quả.
//− Thiết kế và cài đặt thuật toán để đếm và trả về số miền liên thông của lưới L chứa 
//các ô có giá trị 5. Ứng dụng thuật toán và biểu diễn kết quả.

#include<bits/stdc++.h>
using namespace std;


void loang(int **O, bool **used, int i, int j, int m, int n){
	used[i][j] = true;
	if(i > 0 && !used[i - 1][j] && O[i - 1][j] == O[i][j]){
		loang(O, used, i - 1, j, m, n);
	}
	if(j > 0 && !used[i][j - 1] && O[i][j - 1] == O[i][j]){
		loang(O, used, i, j - 1, m, n);
	}
	if(i < m - 1 && !used[i + 1][j] && O[i + 1][j] == O[i][j]){
		loang(O, used, i + 1, j, m, n);
	}
	if(j < n - 1 && !used[i][j + 1] && O[i][j + 1] == O[i][j]){
		loang(O, used, i, j + 1, m, n);
	}
}

int dem_so_mien_lt(int **O, int m, int n){
	bool **used;
	used = new bool*[m];
	for(int i = 0; i < m; i++){
		used[i] = new bool[n];
		for(int j = 0; j < n; j++){
			used[i][j] = false;
		}
	}
	
	int so_mien = 0;
	for(int i = 0; i < m; i++){
		for(int j = 0; j < n; j++){
			if(!used[i][j]){
				if(O[i][j] == 5){
					so_mien++;
				}
				loang(O, used, i, j, m, n);
			}
		}
	}
	return so_mien;
}

int main(){
	int **O;
	int m = 5, n = 5;
	int so_mien = 0;
	O = new int*[m];
	for(int i = 0; i < m; i++){
		O[i] = new int[n];
		for(int j = 0; j < n; j++){
			cin >> O[i][j];
		}
	}
	for(int i = 0; i < m; i++){
		for(int j = 0; j < n; j++){
			cout << O[i][j] << ' ';
		}
		cout << endl;
	}
	cout << endl;
	so_mien = dem_so_mien_lt(O, m, n);
//	cout << "So mien lien thong cua luoi la: " << so_mien << endl;
	cout << "So mien lien thong cua luoi chua gia tri 5 la la: " << so_mien << endl;

	for(int i = 0; i < m; i++){
		delete[] O[i];
	}
	delete[] O;
	return 0;
}