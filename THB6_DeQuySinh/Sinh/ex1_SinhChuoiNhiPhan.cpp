#include<bits/stdc++.h>
using namespace std;

#define el "\n"

void next_config(int x[], int n, int i){
	x[i] = 1;
	i++;
	while(i <= n && x[i] == 1){
		x[i] = 0;
		i++;
	}
}

void view_config(int x[], int n){
	for(int i = 1; i <= n; i++){
		cout << x[i];
	}
	cout << el;
}

void list_configs(int n){
	int i;
	int x[n + 1] = {0};
	do{
		view_config(x, n);
		i = n;
		while(i > 0 && x[i] == 1) i--;
		next_config(x, n, i);
	}while(i > 0);
}

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	list_configs(3);
}