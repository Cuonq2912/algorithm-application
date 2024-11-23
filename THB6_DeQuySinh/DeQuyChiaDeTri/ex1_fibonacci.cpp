#include<bits/stdc++.h>
using namespace std;

using ll = long long;
#define el "\n"

ll fibo_de_quy(int m){
	if(m == 1 || m == 2) return 1;
	return fibo_de_quy(m - 1) + fibo_de_quy(m - 2);
}

ll fibo_khu_de_quy(int n){
	ll f[n];
	f[1] = f[2] = 1;
	for(int i = 3; i <= n; i++){
		f[i] = f[i - 1] + f[i - 2];
	}
	return f[n];
}


//  de quy co nho
ll *f;

int fibo(int n){
	if(n <= 1) return 1;
	if(f[n] != -1) return f[n];
	f[n] = fibo(n - 1) + fibo(n - 2);
	return f[n];
}

void genFibo(int n){
	f = new ll[n];
	fill(f, f + n + 1, -1);
	cout << fibo(n - 1);
	delete[] f;
}

int main(){
	int m, n; cin >> m >> n;
	cout << fibo_de_quy(m) << el;
	cout << fibo_khu_de_quy(n) << el;
	genFibo(n);
}