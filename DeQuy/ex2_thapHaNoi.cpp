#include<bits/stdc++.h>
using namespace std;

#define el "\n"

void chuyen(int n, int c1, int c3){
	cout << "chuyen dia thu n tu cot " << c1 << " sang cot " << c3 << el;
}

void Try(int n, int c1, int c2, int c3){
	if(n == 1){
		chuyen(n, c1, c3);
		return;
	}
	else{
		Try(n - 1, c1, c3, c2);
		chuyen(1, c1, c3);
		Try(n - 1, c2, c1, c3);
	}
}

int main(){
	int n; cin >> n;
	int c1 = 1, c2 = 2, c3 = 3;
	Try(n, c1, c2, c3);
}