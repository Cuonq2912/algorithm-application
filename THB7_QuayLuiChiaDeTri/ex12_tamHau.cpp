//Tám hậu
//- Thiết kế thuật toán A4 giải quyết bài toán xếp tám quân hậu trên bàn cờ vua 8 x 
//8 ô theo chiến lược quay lui sao cho các quân hậu không ăn được nhau.
//- Cài đặt chương trình thực hiện:
//o Khởi tạo số nguyên dương n.
//o Áp dụng thuật toán A4 tìm tất cả các phương án đặt, cho biết số phương 
//án tìm được, hiển thị phương án tìm được (nếu có).

#include<bits/stdc++.h>
using namespace std;

int n, x[100], cot[100], xuoi[100], nguoc[100];


void show(int x[]){
	for(int i = 1; i <= n; i++){
		cout << x[i];
	}
	cout << endl;
}

void Try(int i){
	for(int j = 1; j <= n; j++){
		if(!cot[j] && !xuoi[i - j + n] && !nguoc[i + j - 1]){
			x[i] = j;
			if(i == n){
				show(x);
			}
			else{
				cot[j] = xuoi[i - j + n] = nguoc[i + j - 1] = 1;
				Try(i + 1);
				cot[j] = xuoi[i -j + n] = nguoc[i + j - 1] = 0;		
			}
		}
	}
}

int main(){
	cin >> n;
	Try(1);
}