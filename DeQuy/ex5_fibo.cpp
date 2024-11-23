#include<bits/stdc++.h>
using namespace std;

using ll = long long;
#define el "\n"

// fibonacci bằng đệ quy, đệ quy có nhớ, khử đệ quy

//So fibo thu n

ll fibo0(int n){
	if(n <= 1) return n;
	return fibo0(n - 1) + fibo0(n - 2);
}

// mang fibonacci
ll *f;
ll fibo(int n){
	if(n <= 1) f[n] = 1;
	else f[n] = fibo(n - 1) + fibo(n - 2);
	return f[n];
}

void show(int n){
	for(int i = 1; i <= n; i++){
		cout << fibo(i - 1) << ' ';
	}
}

//fibo khu de quy
ll *f2;
ll fibo2(int n){
	f2[0] = f2[1] = 1;
	for(int i = 2; i <= n; i++){
		f2[i] = f2[i - 1] + f2[i - 2];
	}
	return f2[n - 1]; // vi mang f2 bat dau tu chi so 0
}

int main(){
	int n; cin >> n;
//	cout << fibo(n);	
	f2 = new ll[n];
//	show(n);
	cout << fibo2(5);
	delete[] f2;
	
	return 0;
}