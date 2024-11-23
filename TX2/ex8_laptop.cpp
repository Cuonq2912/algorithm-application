//				Cho danh sách d gồm n chiếc laptop thuộc các hãng sản xuất khác nhau, thông tin về
//				mỗi chiếc laptop gồm tên hãng sản xuất, cấu hình, giá bán (ví dụ: HP, CPU 2.5GHz upto 
//				3.5GHz-RAM 16GB-SSD 512GB; ACER, CPU 2.5GHz upto 3.5GHz-RAM 8GB-HDD 2TB).
//				- Viết thuật toán Boyer Moore Horspool xác định trí xuất hiện của xâu P trong xâu T.
//				- Viết thuật toán Z cho biết xâu P có xuất hiện trong xâu T không.
//				- Khởi tạo n và danh sách d. Sử dụng thuật toán BMP trên cho biết trong danh sách d có 
//				bao nhiêu laptop có RAM 16GB. Sử dụng thuật toán Z cho biết những máy tính nào 
//				trong danh sách d sử dụng ổ cứng loại SSD, hiển thị đầy đủ thông tin của các máy tính 
//				(nếu có

#include<bits/stdc++.h>
using namespace std;

struct LapTop{
	string hangSX;
	string cauHinh;
	int giaBan;
};

void showInfo(LapTop &lt){
	cout << "{" << lt.hangSX << ", " << lt.cauHinh << ", " << lt.giaBan << "}" << endl;
}

int char_in_string(char x, string s){
	for(int i = s.length() - 1; i >= 0; i--){
		if(s[i] == x) return i;
	}
	return -1;
}
// trả về vị trí đầu tiên của xâu s trong xâu t, nếu xâu s không xuat hiện trả về -1
int BMH(string s, string t){
	int v = s.length(), i = v - 1;
	while(i < t.length()){
		int k = v - 1;
		int tmp = i;
		while(t[i] == s[k] && k >= 0){
			k--;
			i--;
		}
		if(k < 0){
			return tmp - k;
		} 
		else{
			int x = char_in_string(t[i], s);
			if(x < 0) i += v;
			else i += v - x - 1;
		}
	}
	return -1;
}

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
	for(int i = s.length(); i < n; i++){
		if(z[i] == s.length()) return true;
	}
	return false;
}

int cnt_RAM(LapTop danhSach[], int n, string s){
	int cnt = 0;
	for(int i = 0; i < n; i++){
		if(BMH(s, danhSach[i].cauHinh) != -1){
			cnt++;
		}
	}
	return cnt;
}

void o_SSD(LapTop danhSach[], int n, string s){
	int cnt = 0;
	for(int i = 0; i < n; i++){
		if(z_algo(s, danhSach[i].cauHinh)){
			showInfo(danhSach[i]);
			cnt++;
		}
	}
	cout << "Số máy tính trong danh sách d sử dụng ổ cứng loại SSD: " << cnt;
}



int main(){
	int n = 7;
	LapTop danhSach[n] = {
		{"HP", "CPU 2.5GHz upto 3.5GHz-RAM 16GB-SSD 512GB", 15000000},
		{"Dell", "CPU 3.0GHz upto 4.2GHz-RAM 8GB-SSD 256GB", 12000000},
		{"Acer", "CPU 2.4GHz upto 3.8GHz-RAM 12GB-HDD 1TB", 14000000},
		{"Asus", "CPU 2.6GHz upto 3.6GHz-RAM 16GB-SSD 512GB", 15500000},
		{"Lenovo", "CPU 3.1GHz upto 4.0GHz-RAM 8GB-SSD 512GB", 13000000},
		{"Apple", "CPU 2.8GHz upto 3.8GHz-RAM 8GB-SSD 256GB", 20000000},
		{"MSI", "CPU 3.2GHz upto 4.5GHz-RAM 16GB-SSD 1TB", 22000000}
	};
	
	string s = "RAM 16GB";
	cout << "laptop có RAM 16GB: " << cnt_RAM(danhSach, n, s) << endl;
	
	string f = "SSD";
	o_SSD(danhSach, n, f);
}