//				Cho một danh sách d gồm n xâu ký tự, mỗi xâu ký tự là một câu tiếng anh có chiều dài 
//				không quá 100 ký tự, các xâu ký tự đôi một khác nhau. Cài đặt chương trình thực hiện:
//				- Khởi tạo số n và danh sách d (5 ≤ n ≤ 10).
//				- Sử dụng chiến lược tham lam thiết kế thuật toán tạo một xâu ký tự mới có chiều dài 
//				đúng bằng k từ các xâu ký tự trong danh sách d sao cho số xâu ký tự cần lấy trong danh 
//				sách d là ít nhất, hiển thị các xâu ký tự đã lấy trong danh sách d.
//				- Ứng dụng thuật toán Boyer Moore Horspool cho biết từ “child” xuất hiện trong bao 
//				nhiêu xâu của danh sách d, gồm những xâu nào (in các xâu xuất hiện từ “child”)?
//				- Ứng dụng thuật toán Z cho biết xâu d[0] là xâu con của những xâu nào trong danh sách d 
//				(không tính d[0]), in các xâu chứa xâu d[0] và số lần xuất hiện d[0] trong mỗi xâu đó

	
#include<bits/stdc++.h>
using namespace std;

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
			k--;
			i--;
		}
		if(k < 0){
			return true;
		}
		else{
			int x = char_in_string(t[i], s);
			if(x < 0) i += v;
			else i += v - x- 1;

		}
	}
	return false;
}

bool z_algo(string s, string t){
	string p = s + " " + t;
	vector<int> z(p.length());
	z[0] = -1;
	int n = p.length(), l = 0, r = 0;
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
			while(i < r && p[r] == p[r - l]){
				r++;
			}
			z[i] = r - l;
			r--;
		}
	}
	for(int i = s.length(); i < n; i++){
		if(z[i] == s.length()){
			return true;
		}
	}
	return false;
}

int cnt_the(string danhSach[], int n, string sub, bool dd[]){
	int cnt = 0;
	for(int i = 0; i < n; i++){
		if(BMH(sub, danhSach[i]) == true){
			cnt++;
			dd[i] = true;
		}
	}
	return cnt;
}

int main(){
	int n = 8;
	string danhSach[n] ={
		{"The sky is clear, and the stars are shining bright."},
		{"She loves reading books in her free time."},
	    {"The traveled to Europe last summer for a vacation."},
	    {"Learning new languages can be a rewarding experience."},
	    {"The coffee shop on the corner serves delicious pastries."},
	    {"My favorite season is autumn because of the beautiful colors."},
	    {"He practices the guitar every evening to improve his skills."},
	    {"She adopted a cute puppy from the animal shelter."}
	};
	
//	string s = "bonnam";
//	string t = "mothaibabonnamsau";
//	if(z_algo(s, t)) cout << "Ys";
	bool dd[n];
	string sub = "the";
	cout << "the xuat hien: " << cnt_the(danhSach, n, sub, dd) << endl;
}