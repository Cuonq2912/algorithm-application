#include<bits/stdc++.h>
using namespace std;

bool z_algo(string s, string t){
	string p = s + " " + t;
	vector<int> z(p.length());
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
	for(int i = s.length() + 1; i < p.length(); i++){
		if(z[i] == s.length()){
			return true;
		}
	}
	return false;
}

int main(){
	string t = "mothaibabonnam";
	string s = "babon";
	if(z_algo(s, t)) cout << "YES";
	else cout << "NO";
}