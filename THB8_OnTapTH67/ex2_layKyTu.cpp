#include<bits/stdc++.h>
using namespace std;

void show(int *x, int m, char *S){
	for(int i = 1; i <= m; i++){
		cout << S[x[i] - 1] << " ";
	}
	cout << endl;
}

void Try(int k, int *x, char *S, int m, int n){
	int fi_ele = (k > 1) ? x[k - 1] + 1 : 1;
	for(int i = fi_ele; i <= n; i++){
		x[k] = i;
		if(k == m){
			show(x, m, S);
		}
		else{
			Try(k + 1, x, S, m, n);
		}
	}
}

int main(){
	int n = 7, m = 6;
	int *x = new int[m + 1];
	char S[n] = {'A', 'B', 'C', 'D', 'E', 'F', 'G'};
	
	Try(1, x, S, m, n);
	delete[] x;
}