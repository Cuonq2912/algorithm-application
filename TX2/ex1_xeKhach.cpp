#include<bits/stdc++.h>
using namespace std;

struct XeKhach{
	string ten;
	int slkhach;
	long giaVe;
};

//Tham lam
//lượng ít nhất các xe cần chọn để 
//tổng tiền thu được (p) lớn hơn một giá trị cho trước (m).
//Số lượng ít nhất các xe được chọn và tổng tiền thu được.

int tl1(XeKhach x[], int n, long m, long &p){
	for(int i = 0; i < n; i++){
		for(int j = 0; j < n - i - 1; j++){
			if(x[j].giaVe < x[j + 1].giaVe){
				XeKhach tmp = x[j];
				x[j] = x[j + 1];
				x[j + 1] = tmp;
			}
		}
	}
	int i = 0;
	while(i < n && m > 0){
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

int tl2(XeKhach x[], int n, int m, long &p){
	for(int i = 0; i < n; i++){
		for(int j = 0; j < n - i - 1; j++){
			if(x[j].giaVe < x[j + 1].giaVe){
				XeKhach tmp = x[j];
				x[j] = x[j + 1];
				x[j + 1] = tmp;
			}
		}
	}
	int i = 0;
	while(i < n && m > 0){
		m -=x[i].giaVe;
		i++;
	}
	if(m == 0){
		return i;
	}
	else return -1;
}


//Tham lam
//Tìm số lượng nhiều nhất các xe có thể chọn 
//sao cho tổng tiền thu được (p) nhỏ hơn giá trị cho trước (m).
//Số lượng nhiều nhất các xe được chọn hoặc kết luận không thể đạt được mục tiêu.

int tl3(XeKhach x[], int n, int m, long &p){
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (x[j].giaVe > x[j + 1].giaVe) {
                XeKhach tmp = x[j];
                x[j] = x[j + 1];
                x[j + 1] = tmp;
            }
        }
    }
    int i = 0; p = 0;
    while (i < n && p + x[i].giaVe < m) {
        p += x[i].giaVe;
        i++;
    }
    return i;
}


// QHD
//Tìm số lượng các xe được chọn 
//sao cho tổng số chỗ ngồi không vượt quá giá trị (v) và tổng tiền thu được là lớn nhất.
//Số lượng xe được chọn và tổng tiền thu được lớn nhất.

struct ketqua{
	int cnt = 0; // soluong
	vector<XeKhach> p;
};

void qhd(XeKhach x[], int n, int v, ketqua& result){
	XeKhach x_new[n + 1];
	x_new[0] = {"", 0, 0};
	for(int i = 0; i < n; i++){
		x_new[i + 1] = x[i];
	}
	int F[n + 1][v + 1];
	for(int i = 0; i <= n; i++){
		for(int j = 0; j <= v; j++){
			if(i == 0) F[i][j] = 0;
			else F[i][j] = INT_MIN;
		}
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
	while(i != 0){
		if(F[i][j] != F[i - 1][j]){
			result.cnt++;
			result.p.push_back(x_new[i]);
			j -= x_new[i].slkhach;
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
		int tmp = i;
		while(t[i] == s[k] && k >= 0){
			k--;
			i--;
		}
		if(k < 0){
			return true;
		} 
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
		if(BMH("An", x[i].ten)){
			index.push_back(i);
			cnt++;
		}
	}
	return cnt;
}


//z_algo
//Tìm số lượng xe có tên chứa cụm từ "An"
// trả về danh sách thông tin của các xe đó.

bool z_algo(string s, string t){
	string p = s + "%" + t;
	vector<int> z(p.length());
	int n = p.length(), l = 0, r = 0;
	z[0] = -1;
	for(int i = 1; i < n; i++){
		if(i > r){
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



int cnt_zAlgo(XeKhach x[], int n, vector<int> &index){
	int cnt = 0;
	for(int i = 0; i < n; i++){
		if(z_algo("An", x[i].ten)){
			index.push_back(i);
			cnt++;
		}
	}
	return cnt;
}


int main(){
	int n = 6;
	XeKhach danhSach[n] = {
		{"Hai Nam", 120, 150000},
		{"Bui Minh", 40, 160000},
		{"Le An", 25, 220000},
		{"Nguyen An", 30, 250000},
		{"Van Chung", 20, 300000},
		{"Ly Dao", 100, 200000}			
	};	
	
	long m = 1000000;
	int v = 50;
	long money = 0;
	
	int min_cnt_xe = tl1(danhSach, n, m, money);
	cout << "So luong it nhat cac xe la: " << min_cnt_xe << " --- Tong tien thu duoc la: " << money << endl;
	
	int min_cnt_xe2 = tl2(danhSach, n, m, money);
	if(min_cnt_xe2 < 0){	
		cout << "Khong dat duoc muc tieu\n";
	}
	else{
		cout << "So luong it nhat cac xe de tong so tien thu duoc bang m la: ";
		cout << min_cnt_xe2;
	}
		
	int min_cnt_xe3 = tl3(danhSach, n, m, money);
	cout << "So luong nhieu nhat cac xe de so tien thu duoc nho hon m: " << min_cnt_xe3;
	cout << endl;
	
	vector<int> index;
	cout << "So luong xe co tu An la: " << dem_BMH(danhSach, n, index) << endl;
	cout << "Vi tri cua chung trong danh sach la: ";
	for(auto it : index){
		cout << it << ' ';
	}
	cout << endl;
	
	vector<int> index2;
	cout << "So luong xe co tu An la: " << cnt_zAlgo(danhSach, n, index2) << endl;
	cout << "Vi tri cua chung trong danh sach la: ";
	for(auto it : index2){
		cout << it << ' ';
	}
	cout << endl;
	
	ketqua result;
	qhd(danhSach, n, v, result);
	cout << "So luong xe duoc chon la: " << result.cnt << endl;
	cout << "danh sach cac xe duoc chon la: \n"; 
	for(XeKhach xe : result.p){
		cout << xe.ten << " " << xe.slkhach << " " << xe.giaVe << endl;
	}
}

