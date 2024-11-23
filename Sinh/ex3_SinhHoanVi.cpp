#include<bits/stdc++.h>
using namespace std;

#define el "\n"

//12345
//12354
//12435
//12453
//12543
//1

void Swap(int &a, int &b){
	int tmp = a;
	a = b;
	b = tmp;
}
void next_config(int x[], int n, int i){
	int k = n;
	while(x[k] < x[i]){
		k--;
	}
	Swap(x[i], x[k]);
	int j = n;
	i++;
	while(i < j){
		Swap(x[i], x[j]);
		i++;
		j--;
	}
}

void show_config(int x[], int n){
	for(int i = 1; i <= n; i++){
		cout << x[i];
	}
	cout << el;
}
void list_configs(int n){
	int i, x[n + 1] = {0};
	for(int j = 1; j <= n; j++){
		x[j] = j;
	}
	do{
		show_config(x, n);
		i = n - 1;
		while(i > 0 && x[i] > x[i + 1]) i--;
		if(i > 0) next_config(x, n, i);
	}while(i > 0);
}

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	list_configs(3);
	return 0;
}