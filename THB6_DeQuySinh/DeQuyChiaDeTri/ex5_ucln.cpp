#include<bits/stdc++.h>
using namespace std;

using ll = long long;

int ucln_1(int a, int b){
	if(a * b == 0) return a > b ? a : b;
	return ucln_1(b, a % b);
}

int ucln_2(int a, int b){
	while(b != 0){
		int du = a % b;
		a = b;
		b = du;
	}
	return a;
}



int main(){
	int a, b; cin >> a >> b;
	cout << ucln_1(a, b) << "\n";
	cout << ucln_2(a, b);
	return 0;
}