#include<bits/stdc++.h>
using namespace std;

string s = "rqwertxtrewql";

bool A1(string s){
	int l = 0, r = s.length() - 1;
	while(l < r){
		if(s[l] != s[r]) return false;
		else{
			l++;
			r--;	
		}
	}
	return true;
}

string A2(string s, int k){
	string ans = "";
	int l = k, r = k;
	while(l >= 0 && r < s.length()){
		if(s[l] == s[r]){
			ans.push_back(s[l]);
			l--;
			r++;
		}
		else{
			break;
		}
	}
	string rev = ans;
	reverse(rev.begin(), rev.end());
	rev.pop_back();
	return rev + ans;	
}

int main(){
	if(A1(s)) cout << "dx";
	else cout << "kdx";
	cout << endl << A2(s, 6);
}