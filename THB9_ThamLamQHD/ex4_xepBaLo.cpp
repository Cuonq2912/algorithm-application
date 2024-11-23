#include<bits/stdc++.h>
using namespace std;

//Xếp ba lô
//Input:
//- Cho một kho chứa n gói hàng được ghi số thứ tự từ 1 đến n.
//- Các gói hàng có khối lượng lần lượt là m1, m2, ..., mn và kích thước lần lượt  là k1, k2, ..., kn.
//- Cho một chiếc ba lô có kích thước k. 
//
//Output:
//- Tính p và d lần lượt là tổng khối lượng và danh sách các gói hàng được chọn
//để đưa và ba lô sao cho tổng khối lượng là nhỏ nhất và tổng kích thước của 
//các gói hàng được chọn không vượt quá kích thước của ba lô.
//
//Thực hiện các yêu cầu sau:
//- Thiết kế thuật toán A6 để tính và trả về p và d lần lượt là tổng khối lượng và 
//danh sách các gói hàng được chọn để đưa và ba lô sao cho tổng khối lượng là
//nhỏ nhất và tổng kích thước của các gói hàng được chọn không vượt quá kích thước của ba lô.
//
//- Cài đặt chương trình:
//o Cài đặt hàm F6 biểu diễn thuật toán A6.
//o Khởi tạo k, n, {m1, m2, ..., mn} và {k1, k2, ..., kn}.
//o Sử dụng thuật toán A6 để tính và đưa ra p và d

int n = 6, k = 20;
int klg[] = {12, 3, 6, 8, 2, 5};
int kthuoc[] = {4, 6, 3, 7, 3, 6};
bool dsach[] = {0, 0, 0, 0, 0, 0};

void inDS(bool dsach[], int n){
	for(int i = 0; i < n; i++){
		if(dsach[i] == true){
			cout << klg[i] << " " << kthuoc[i] << endl;
		}
	}
}

void Swap(int &a, int &b){
	int tmp = a;
	a = b; b = tmp;
}

void Sort(int klq[], int n){
	for(int i = 0; i < n; i++){
		for(int j = n - 1; j >= i; j--){
			if(klq[j] < klq[j - 1]){
				Swap(klq[j], klg[j - 1]);
			}
		}
	}
}

int A6(int klg[], int kthuoc[], int n, int k){
	int cur_klg = 0, cnt = 0;
	for(int i = 0; i < n; i++){
		if(cur_klg + klg[i] <= k){
			dsach[i] = true;
			cur_klg += klg[i];
			cnt++;
		}
		else break;
	}
	return cnt;
}


int main(){
	Sort(klg, n);
	int p = A6(klg, kthuoc, n, k);
	cout << "Tong khoi luong min la: " << p << endl;
	cout << "Danh sach cac goi hang lay la: \n";
	inDS(dsach, n);
	
}