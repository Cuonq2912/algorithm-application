#include<bits/stdc++.h>
using namespace std;

struct XeKhach{
	string ten;
	int soKhach;
	int tienVe;
};

void show(XeKhach x){
	cout << x.ten << " " << x.soKhach << " " << x.tienVe << endl;
}

int tl(XeKhach x[], int n, int m, int& p){
	int i = 0;
	while(i < n && m >= 0){
		m -= x[i].tienVe;
		p += x[i].tienVe;
		i++;
	}
	return i;
}

int QHD(XeKhach x[], int n, int v, int& t){
	XeKhach x_new[n + 1];
	x_new[0] = {"", 0, 0};
	for(int i = 0; i < n; i++){
		x_new[i + 1] = x[i];
	}
	int F[n + 1][v + 1];
	for(int j = 0; j <= v; j++){
		F[0][j] = 0;
	}
	for(int i = 1; i <= n; i++){
		for(int j = 0; j <= v; j++){
			F[i][j] = F[i - 1][j];
			if(x_new[i].soKhach <= j){
				int tmp = x_new[i].tienVe + F[i - 1][j - x_new[i].soKhach];
				if(F[i][j] < tmp){
					F[i][j] = tmp;
				}
			}
		}
	}
	t = F[n][v];
	int i = n, j = v, cnt = 0;
	while(i != 0){
		if(F[i][j] != F[i - 1][j]){
			cnt++;
			j -= x_new[i].soKhach;
		} 
		i--;
	}
	return cnt;
}


int main(){
	int n = 8;
	XeKhach ds[n] = {
		{"Khiem Oanh", 30, 5000000},
		{"Thuy Linh", 50, 3500000},
		{"Xuan Thang", 10, 2800000},
		{"Duc Anh", 25, 2400000},
		{"Van Loc", 20, 2000000},
		{"Nam Anh", 35, 1500000},
		{"Gia Bao", 40, 1200000},
		{"Thanh Van", 45, 1000000},
	};
	int m = 10000000;
	int v = 100;
	
	int p = 0;
	int soChuyentl = tl(ds, n, m, p);
	cout << "So chuyen xe its nhat can su dung de tong tien ve thu duoc lon hon m la: " << soChuyentl << endl;
	cout << "Tong tien la: " << p << endl;

	int t = 0; // tien ve
	int soChuyen = QHD(ds, n, v, t);
	cout << "So chuyen xe can dua vao nha cho sao cho tong tien ve thu duoc lon nhat ma khong vuot qua suc chua la: " << soChuyen << endl;
	cout << "Tong tien la: " << t << endl;
}