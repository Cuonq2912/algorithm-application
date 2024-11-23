//					Vận tải 1
//					Input:
//					- Cho n chiếc xe tải với các xe có tải trọng khác nhau lần lượt là t1, t2, ..., tn.
//					- Kho hàng k chứa m tấn hàng cần vận chuyển đến địa điểm khác.
//					Output:
//					- Tính d là danh sách tối thiểu các xe tải cần sử dụng để vận chuyển hết m tấn 
//					hàng sao cho mỗi xe tải chỉ được sử dụng 1 lần.
//					Thực hiện các yêu cầu sau:
//					- Thiết kế thuật toán A4 để tính và trả về d là danh sách tối thiểu các xe tải được 
//					sử dụng để vận chuyển hết m tấn hàng bằng chiến lược tham lam.
//					- Cài đặt chương trình:
//					o Cài đặt hàm F4 biểu diễn thuật toán A4.
//					o Khởi tạo m, n và {t1, t2, ..., tn}.
//					o Sử dụng thuật toán A4 để tính và đưa ra d. 

#include<bits/stdc++.h>
using namespace std;

void Swap(int &x, int &y){
	int tmp = x;
	x = y; y = tmp;
}

void inDS(int trongLuong[], bool d[], int n){
	for(int i = 0; i < n; i++){
		if(d[i]){
			cout << trongLuong[i] << " ";
		}
	}
}

void Sort(int a[], int n){
	for(int i = 1; i < n; i++){
		for(int j = n - 1; j >= i; j--){
			if(a[j] > a[j - 1]){
				Swap(a[j], a[j - 1]);				
			}
		}
	}
}

bool A4(int trongLuong[], int n, bool d[], int m){
	int i = 0;
	while(i < n && m > 0){
		m -= trongLuong[i];
		d[i] = true;
		i++;
	}
	if(i >= n){
		return false;
	}
	return true;
}

int main(){
	int n = 7, m = 300;
	int trongLuong[] = {23, 54, 43, 76, 12, 59, 68};
	bool d[] = {0, 0, 0, 0, 0, 0, 0};
	Sort(trongLuong, n);
	if(A4(trongLuong, n, d, m)){
		cout << "Danh sach xe can dung la: ";
		inDS(trongLuong, d, n);
	}
	else cout << "Không thể vẫn chuyển hết";
	
	return 0;
}