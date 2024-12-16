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
			i--; k--;
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

void QHD(XeKhach x[], int n, int v, ketqua& result){
	XeKhach x_new[n + 1];
	x_new[0] = {"", 0, 0};
	for(int i = 0; i < n; i++){
		x_new[i + 1] = x[i];
	}
	int F[n + 1][v + 1];
	for(int j = 0; j <= n; j++){
		F[0][j] = 0;
	}
	for(int i = 1; i <= n; i++){
		for(int j = 0; j <= v; j++){
			F[i][j] = 0;
			if(x_new[i].slkhach < j){
				int tmp = x_new[i].giaVe + F[i - 1][j - x_new[i].slkhach];
				if(F[i][j] < tmp){
					F[i][j] = tmp;
				}
			}
		}
	}
	int i = n, j = v;
	int tongtien = F[n][v];
	while(i != 0){
		if(F[i][j] != F[i - 1][j]){
			result.cnt++;
			result.p.push_back(x_new[i]);
			j -= x_new[i].slkhach;
		}
		i--;
	}
	return tongtien;
}

int main(){
	string s = "bonnam";
	string t = "mothaibabonnam";
	cout << z_algo(s, t);	
}