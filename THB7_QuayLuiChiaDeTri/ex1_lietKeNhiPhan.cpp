#include<bits/stdc++.h>
using namespace std;

void show_listAB(int *x, int i){
	if(i == 0) cout << "A";
	else cout << "B";
}

void show_config(int *x, int n){
	for(int i = 1; i <= n; i++){
		show_listAB(x, x[i]);
	}
	cout << endl;
}

void Try(int k, int *x, int n){
	for(int i = 0; i <= 1; i++){
		x[k] = i;
		if(k == n){
			show_config(x, n);
		}
		else{
			Try(k + 1, x, n);
		}
	}
	
}

int main(){
	int n; cin >> n;
	int *x;
	x = new int[n];
	for(int i = 1; i <= n; i++){
		x[i] = 0;
	}
	Try(1, x, n);
	delete[] x;
	return 0;
}