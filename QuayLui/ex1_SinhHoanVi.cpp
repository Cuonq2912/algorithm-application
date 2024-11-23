#include<bits/stdc++.h>
using namespace std;

using ll = long long;
#define el "\n"

void show(int *x, int n){
	for(int i = 1; i <= n; i++){
		cout << x[i];
	}
	cout << el;
}

void Try(int k, int *x, int n, bool *dd){
	for(int i = 1; i <= n; i++){
		if(!dd[i]){
			x[k] = i;
			if(k == n){
				show(x, n);
			}
			else{
				dd[i] = true;
				Try(k + 1, x, n, dd);
				dd[i] = false;
			}
		}
	}
}

int main(){
	int n = 4;
	int *x;
	bool *dd;
	x = new int[n + 1];
	dd = new bool[n + 1];
	for(int i = 1; i <= n; i++){
		dd[i] = false;
	}
	Try(1, x, n, dd);
	delete[] x;
	delete[] dd; 
	return 0;
}