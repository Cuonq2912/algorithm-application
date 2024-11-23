#include<bits/stdc++.h>
using namespace std;

#define el "\n"

void next_config(int x[], int n, int i){
	x[i] = 1;
	i++;
	while(i <= n){
		x[i] = 0;
		i++;
	}	
}
void show_config(int x[], int n){
	for(int i = 1; i <= n; i++){
		if(x[i] == 0) cout << 'A';
		else cout << 'B';
	}
	cout << el;
}

void list_configs(int n){
	int i, x[n + 1] = {0};
	do{
		show_config(x, n);
		i = n;
		while(i > 0 && x[i] == 1) --i;
		if(i > 0) next_config(x, n, i);
	}while(i > 0);
}

int main(){
	list_configs(3);
	return 0;
}