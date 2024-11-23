//			Cho một danh sách d chứa thông tin về các máy tính xách tay khác nhau được bày 
//			bán trong một cửa hàng, thông tin về mỗi máy tính xách tay gồm hãng sản xuất, 
//			thông tin mô tả (ví dụ: “CPU I7 12650H – RAM 16GB – 15.7 inchs – new”), giá 
//			bán (USD). Cho một số tiền m (USD) và một xâu t là thông tin về kích thước màn 
//			hình của một máy tính (ví dụ “14 inchs”).
//			Hãy viết chương trình thực hiện các yêu cầu:
//			- Cài đặt các thuật toán:
//			o Thuật toán Z xử lý xâu ký tự để cho biết một xâu s có phải là một xâu 
//			con của một xâu p hay không?
//			o Khởi tạo một danh sách gồm ít nhất 6 máy tính xách tay sao cho danh 
//			sách được sắp xếp theo thứ tự giảm dần của giá bán máy tính, khởi tạo 
//			số tiền m và khởi tạo xâu t. Áp dụng các thuật toán đã thiết kế ở trên để
//			tính sau đó hiển thị ra màn hình thong tin về các máy và giá trị y là số máy 
//			tính xách tay có kích thước màn hình t, hoặc đưa ra thông báo nếu 
//			không có phương án

#include<bits/stdc++.h>
using namespace std;

struct mayTinh{
	string hangSX;
	string thongTinMT;
	int giaBan;
};

void showData(mayTinh mt){
	cout << "{" << mt.hangSX << ", " << mt.thongTinMT << ", " << mt.giaBan << "}" << "\n";
}

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
		while(s[k] == t[i] && k >=0){
			k--;
			i--;
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
			z[i] = r- l;
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
			z[i] = r- l;
			r--;
		}
	}
	for(int i = s.length() + 1; i <n; i++){
		if(z[i] == s.length()) return true;
	}
	return  false;
}


int main(){
//	string t = "mothaibabonnamsau";
//	string s = "bonnam";
//	cout << BMH(s, t);
//	cout << z_algo(s, t);

	mayTinh danhSachs[10] = {
					{"MSI", "CPU I9 12900H – RAM 32GB – 17 inches – new", 35000000},
					{"MacBook", "CPU M1 – RAM 8GB – 13.3 inches – new", 25000000},
					{"Acer", "CPU I7 12700H – RAM 16GB – 15.7 inches – new", 21000000},
					{"Dell", "CPU I7 12650H – RAM 16GB – 15.6 inches – new", 20000000},
					{"Lenovo", "CPU Ryzen 7 5800H – RAM 16GB – 15.6 inches – old", 18000000},
					{"Asus", "CPU I5 1235U – RAM 8GB – 15.6 inches – new", 16000000},
					{"Asus", "CPU I5 1135G7 – RAM 8GB – 14 inches – new", 15000000},
					{"HP", "CPU I5 75000H – RAM 8GB – 14.6 inches – old", 14000000},
					{"HP", "CPU Ryzen 5 4600H – RAM 8GB – 15.6 inches – old", 13000000},
					{"Dell", "CPU I3 1115G4 – RAM 4GB – 14 inches – old", 9000000}
	};
	
	int m, cnt = 0;
	string t = "15.6 inches";
	
	cout << "Danh sach cac may tinh: \n";
	for(int i = 0; i < 10; i++){
		if(z_algo(t,danhSachs[i].thongTinMT)){
			cnt++;
			showData(danhSachs[i]);
		}
	}
	cout << "So may: " << cnt;
	
	
}