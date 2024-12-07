//9:10 9:55
#include<bits/stdc++.h>
using namespace std;

struct XeKhach{
	string ten;
	int slkhach;
	int giaVe;
};

void show(XeKhach x){
	cout << x.ten << " " << x.slkhach << " " << x.giaVe << endl;
}

//Tham lam
//lượng ít nhất các xe cần chọn để 
//tổng tiền thu được (p) lớn hơn một giá trị cho trước (m).
//Số lượng ít nhất các xe được chọn và tổng tiền thu được.
int tl1(XeKhach x[], int n, int m, long& p){
	int i = 0;
	while(i < n && m >= 0){
		m -= x[i].giaVe;
		p += x[i].giaVe;
		i++;
	}
	return i;
}

//Tham lam
//Tìm số lượng ít nhất các xe cần chọn để 
//tổng tiền thu được (p) bằng chính xác giá trị m.
//Số lượng ít nhất các xe được chọn hoặc kết luận không thể đạt được mục tiêu.
int tl2(XeKhach x[], int n, int m, long& p){
	int i = 0;
	while(i < n && m > 0){
		m -= x[i].giaVe;
		p += x[i].giaVe;
		i++;
	}
	if(m == 0) return i;
	return -1;
}

//Tham lam
//Tìm số lượng nhiều nhất các xe có thể chọn 
//sao cho tổng tiền thu được (p) nhỏ hơn giá trị cho trước (m).
//Số lượng nhiều nhất các xe được chọn hoặc kết luận không thể đạt được mục tiêu.
int tl3(XeKhach x[], int n, int m, long& p){
	int i = 0;
	while(i < n && p + x[i].giaVe < m){
		p += x[i].giaVe;
		i++;
	}
	if(i != 0) return i;
	return -1;
}

// QHD
//Tìm số lượng các xe được chọn 
//sao cho tổng số chỗ ngồi không vượt quá giá trị (v) và tổng tiền thu được là lớn nhất.
//Số lượng xe được chọn và tổng tiền thu được lớn nhất.
struct ketqua{
	int cnt = 0;
	vector<XeKhach> p;
};
void QHD(XeKhach x[], int n, int v, long& tien, ketqua& result){
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
			if(x_new[i].slkhach <= j){
				int tmp = x_new[i].giaVe + F[i - 1][j - x_new[i].slkhach];
				if(F[i][j] < tmp){
					F[i][j] = tmp;
				}
			}
		}
	}
	int i = n, j = v;
	tien = F[n][v];
	while(i != 0){
		if(F[i][j] != F[i - 1][j]){
			result.cnt++;
			result.p.push_back(x_new[i]);
		}
		i--;
	}
}

//BMH
//Tìm số lượng xe có tên chứa cụm từ "An"
//trả về danh sách các vị trí của các xe đó trong mảng ban đầu.
//Số lượng xe có tên chứa cụm từ "An" và các vị trí của chúng.
int char_in_string(char x, string s){
	for(int i = s.length() - 1; i >= 0; i--){
		if(s[i] == x) return i;
	}
	return -1;
}

bool BMH(string s, string t){
	int v = s.length(), i = v - 1;
	while(i < t.length()){
		int k = v - 1;
		while(t[i] == s[k] && k >= 0){
			k--; i--;
		}
		if(k < 0) return true;
		else{
			int x = char_in_string(t[i], s);
			if(x < 0) i += v;
			else i += v - x - 1;
		}
	}
	return false;
}

int dem_BMH(XeKhach x[], int n, vector<int> &index){
	int cnt = 0;
	for(int i = 0; i < n; i++){
		if(BMH("An",x[i].ten)){
			cnt++;
			index.push_back(i);
		}
	}
	return cnt;
}

//z_algo
//Tìm số lượng xe có tên chứa cụm từ "An"
// trả về danh sách thông tin của các xe đó.
bool z_algo(string s, string t){
	string p = s + "#" + t;
	vector<int> z(p.length());
	z[0] = -1;
	int n = p.length(), l = 0, r = 0;
	for(int i = 1; i < n; i++){
		if(r < i){
			l = r = i;
			while(r < n && p[r] == p[r - l]){
				r++;
			}
			z[i] = r - l;
			r--;
		}
		else if(z[i - l] < r - i + 1){
			z[i] = z[i - l];
		}
		else{
			l = i;
			while(r < n && p[r] == p[r - l]){
				r++;
			}
			z[i] = r - l;
			r--;
		}
	}
	for(int i = s.length() + 1; i < n; i++){
		if(z[i] == s.length()) return true;
	}
	return false;
}

void dem_z(XeKhach x[], int n, ketqua &result){
	for(int i = 0; i < n; i++){
		if(z_algo("An", x[i].ten)){
			result.cnt++;
			result.p.push_back(x[i]);
		}
	}
}

int main(){
	int n = 6;
	XeKhach ds[n] = {
		{"An Minh", 30, 450000},
		{"Hung Cuong", 32, 370000},
		{"Tran An", 36, 330000},
		{"Ngo Tung", 40, 260000},
		{"Le Khai", 25, 200000},
		{"Nam An", 10, 150000},
	};
//	int m = 1500000;
//	long p = 0;
//	int anstl1 = tl1(ds, n, m, p);
//	if(anstl1 > 0){
//		//	cout << "So luong it nhat cac xe duoc chon de tong tien thu duoc p lon hon gia tri cho truoc m la: ";
//		//	cout << tl1(ds, n, m, p) << endl;
//		//	cout << "Tong tien thu duoc: " << p << endl;
//	}
//	else cout << "Khong dat duoc muc tieu!!;

	
//	int m = 1150000;
//	long p = 0;
//	int anstl2 = tl2(ds, n, m, p);
//	if(anstl2 < 0) cout << "Khong dat duoc muc tieu!";
//	else{
//		cout << "So luong it nhat cac xe duoc chon de tong tien thu duoc p bang chinh xac gia tri cho truoc m la: ";
//		cout << anstl2;	
//	} 
	
//	int m = 1500000;
//	long p = 0;
//	int anstl3 = tl3(ds, n, m, p);
//	if(anstl3 < 0) cout << "Khong dat duoc muc tieu!!";
//	else {
//		cout << "So luong it nhat cac xe duoc chon de tong tien thu duoc p nho hon gia tri cho truoc m la: ";
//		cout << anstl3 << endl;
//	}

//	int v = 80;
//	long tien = 0;
//	ketqua result1;
//	QHD(ds, n, v, tien, result1);
//	cout << "So luong xe: " << result1.cnt << endl;
//	cout << "Tong tien thu: " << tien << endl; 

//	vector<int> index;
//	int ans_BMH = dem_BMH(ds, n, index);
//	cout << "So luong xe chua tu An la: " << ans_BMH << endl;
//	if(ans_BMH > 0){
//		cout << "Vi tri cac xe la: ";
//		for(int x : index){
//			cout << x << " "; 
//		}
//	} else cout << "Khong ton tai xe nao" << endl;

//	ketqua result2;
//	dem_z(ds, n, result2);
//	cout << "So luong xe chua cum tu An la: " << result2.cnt << endl;
//	if(result2.cnt > 0){
//		cout << "Danh sach cac xe la: " << endl;
//		for(XeKhach x : result2.p){
//			show(x);
//		}
//	}
//	else cout << "Khong ton tai xe nao!!";

	return 0;
}


