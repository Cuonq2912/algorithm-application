#include<bits/stdc++.h>
using namespace std;

using ll = long long;

int sumOfOdd(int *a, int n){
	int ans = 0;
	for(int i = 0; i < n; i++){
		if(a[i] % 2 == 1){
			ans += a[i];
		}
	}
	return ans;
}

int main(){
	ll n; cin >> n;
	int *a;
	for(int i = 0; i < n; i++){
		cin >> a[i];
	}
	cout << sumOfOdd(a, n);
}