#include<bits/stdc++.h>
using namespace std;

string p = "child is the son or the daughter of parent child child child";

int A3(string p){
	int cnt = 0;
	stringstream ss(p);
	string word;
	while(ss >> word){
		if(word == "child"){
			cnt++;
		}
	}
	return cnt;
}

string A4(string p){
	stringstream ss(p);
	string word, result;
	while(ss >> word){
		if(word == "child"){
			word = "children";
		}
		result += word + " ";
	}
	if(!result.empty()) result.pop_back();
	return result;
}

int main(){
	cout << A3(p) << endl;
	cout << A4(p);
}