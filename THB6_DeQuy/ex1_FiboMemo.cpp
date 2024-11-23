#include<bits/stdc++.h>
using namespace std;

using ll = long long;
#define el "\n"

ll *f;
ll fibo(int n){
	if(n <= 1) return 1;
	if(f[n] != -1) return f[n];
	f[n] = fibo(n - 1) + fibo(n - 2);
	return f[n];
}

void genFibo(int n){
	f = new ll[n + 1];
	fill(f, f + n + 1, -1);
	cout << fibo(n - 1);
	delete[] f;
}

int main(){
	int n; cin >> n;
	genFibo(n);
	return 0;
}