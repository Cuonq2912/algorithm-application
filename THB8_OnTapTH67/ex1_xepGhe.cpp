#include<bits/stdc++.h>
using namespace std;

char G[4] = {'A', 'B', 'C', 'D'};
string N[4] = {"Tung", "Cuc", "Truc", "Mai"};

void show_config(int *x, int n){
	for(int i = 1; i <= n; i++){
		cout << G[x[i] - 1] << "-" << N[x[i] - 1];
		if(i != n) cout << ' ';
	}
	cout << endl;
}

int cnt = 0;
void Try(int k, int *x, int n, bool *used){
	for(int i = 1; i <= n; i++){
		if(!used[i]){
			x[k] = i;
			if(k == n){
				cnt++;
				show_config(x, n);
			}
			else{
				used[i] = true;
				Try(k + 1, x, n, used);
				used[i] = false;
			}
		}
	}
}

int main(){
	int n = 4;
	int *x = new int[n + 1]; // luu cau hinh;
	bool *used = new bool[n + 1]; // danh dau
	fill(used, used + n + 1, 0);
	
	Try(1, x, n, used);
	cout << "---" << cnt;
	delete[] x;
	delete[] used;
	return 0;
}