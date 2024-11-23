#include<bits/stdc++.h>
using namespace std;

#define el "\n"

void next_config(int x[], int k, int i){
	x[i] += 1;
	i++;
	while(i <= k){
		x[i] = x[i - 1] + 1;
		i++;
	}
}

void view_config(int x[], int k){
	for(int i = 1; i <= k; i++){
		cout << x[i];
	}
	cout << el;
}

void list_configs(int k, int n){
	int i;
	int x[k + 1] = {0};
	for(int j = 1; j <= k; j++){
		x[j] = j;
	}
	do{
		view_config(x, k);
		i = k;
		while(i > 0 && x[i] == n - k + i) --i;
		if(i > 0) next_config(x, k, i);
	}while(i > 0);
}

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	list_configs(3, 6);
}