#include<bits/stdc++.h>
using namespace std;

string name[] = {"Trang", "Cong", "Trung", "Binh", "Hoan", "Mai"};

int cnt = 0;
void show_config(int *x, int n){
	for(int i = 1; i <= n; i++){
		cout << i << "-" << name[x[i] - 1] << ' ';
	}
}

void Try(int k, int *x, int n, bool *used){
	for(int i = 1; i <= n; i++){
		if(!used[i]){
			x[k] = i;
			if(k == n){
				show_config(x, n);
				cout << endl;
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
	int n = 6;
	int *x;
	bool *used;
	x = new int[n + 1];
	used = new bool[n + 1];
	for(int i = 1; i <= n; i++){
		used[i] = false;
	}
	Try(1, x, n, used);
	// tất cả các cách xếp 6 sinh viên gồm: Trang, Cong, Trung, Binh, Hoan, Mai vào 6 chiếc ghế
	//được đánh số thứ tự 1, 2, …, 6.
	
	
	delete[] x;
	delete[] used;
	return 0;
}