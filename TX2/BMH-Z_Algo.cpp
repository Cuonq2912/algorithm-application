#include<bits/stdc++.h>
using namespace std;

int char_in_string(char x, string s){
	for(int i = s.length() - 1; i >= 0; i--){
		if(s[i] == x) return i;
	}
	return -1;
}

bool BMH(string s, string t){
	int v= s.length(), i = v - 1;
	while(i < t.length()){
		int k = v - 1;
		while(s[k] == t[i] && k >= 0){
			i--;
			k--;
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

bool z_algo(string s, string t){
	string p = s + "%" + t;
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
			while(r < n && p[r] == p[r - l]){
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

int main(){
	string s = "bonccnam";
	string t = "mothaibabonnamsau";
	
	if(BMH(s, t)) cout << "YES";
	else cout << "NO";
//	if(z_algo(s, t)) cout << "YES";
//	else cout << "No";
}