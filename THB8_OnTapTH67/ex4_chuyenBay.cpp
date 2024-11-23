#include<bits/stdc++.h>
using namespace std;

struct ChuyenBay{
	string soHieu;
	int giaVe;
	int soGhe;
};

void A1(ChuyenBay *cb, int n, int i){
	if(i >= n) return;
	if(cb[i].giaVe > 700000){
		cout << "chuyen bay: " << cb[i].soHieu;
		cout << " gia ve: " << cb[i].giaVe;
		cout << " so ghe: " << cb[i].soGhe;
		cout << endl;
	}
	A1(cb, n, i + 1);
}

ChuyenBay A2(ChuyenBay *cb, int l, int r){
	if(l == r){
		return cb[r];
	}
	int m = (l + r)/2;
	ChuyenBay Lmin = A2(cb, l, m);
	ChuyenBay Rmin = A2(cb, m + 1, r);
	return Lmin.giaVe < Rmin.giaVe ? Lmin : Rmin;
}


void next_config(int *x, int k, int i){
	x[i] += 1;
	i++;
	while(i <= k){
		x[i] = x[i - 1] + 1;
		i++;
	}
}
void show(ChuyenBay *cb, int i){
	cout << "So hieu: " << cb[i - 1].soHieu << " So ghe: " << cb[i - 1].soGhe << endl;
}
void show_config(int *x, int m, ChuyenBay *cb){
	for(int i = 1; i <= m; i++){
		show(cb, x[i]);
	}
}
void A3(int k, int n, ChuyenBay *cb){
	int i;
	int x[k + 1] = {0};
	for(int j = 1; j <= k; j++){
		x[j] = j;
	}
	do{
		show_config(x, k, cb);
		cout << endl;
		i = k;
		while(i > 0 && x[i] == n - k + i) i--;
		if(i > 0) next_config(x, k, i);
	}while(i > 0);
}


int main(){
	int n = 10;
	ChuyenBay chuyenbays[10] = {
		{"VN001", 100000, 450},
		{"VN002", 250000, 400},
		{"VN003", 870000, 120},
		{"VN004", 360000, 270},
		{"VN005", 410000, 300},
		{"VN006", 900000, 100},
		{"VN007", 290000, 250},
		{"VN008", 120000, 420},
		{"VN009", 750000, 100},
		{"VN010", 950000, 100}
	};
	cout << "các chuyến bay có giá vé trên 700000 là: \n";
	A1(chuyenbays, n, 0);
	cout << endl;
	
	cout << "chuyến bay có giá vé thấp nhất trong danh sách la: ";
	cout << A2(chuyenbays, 0, n - 1).soHieu <<"\n\n\n";
	
	cout << "tất cả các phương án chọn ra 4 chuyến bay từ danh sách la: \n"
;	A3(4, n, chuyenbays);
	return 0;
}

