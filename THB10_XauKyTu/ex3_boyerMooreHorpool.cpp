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
		while(s[k] == t[i] && k >= 0){
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


int main(){
	string t = "mothaibabonnamsau";
	string s = "bonnam";
	if(BMH(s, t)) cout << "YES";
	else cout << "NO";
}