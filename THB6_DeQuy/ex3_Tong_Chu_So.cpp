#include<bits/stdc++.h>
using namespace std;

using ll = long long;

int sumOfNumber(ll n){
	if(n == 0) return 0;
	return n % 10 + sumOfNumber(n/10);
}

int main(){
	ll n; cin >> n;
	cout << sumOfNumber(n);
}