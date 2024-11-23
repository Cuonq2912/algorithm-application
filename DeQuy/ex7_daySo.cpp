//Cài đặt chương trình sử dụng cấu trúc dữ liệu vector (danh sách kế tiếp) với các chức năng: 
//− Khởi tạo số nguyên dương n và một dãy a với n số nguyên (n ≥ 30), hiển thị dãy.
//− Tính tổng các phần tử của dãy a, tìm giá trị lớn nhất, nhỏ nhất của dãy a, hiển thị
//các kết quả.
//− Sắp xếp dãy a bằng một thuật toán sắp xếp có độ phức tạp O(n.lgn). Hiển thị dãy 
//sau khi sắp xếp.

#include<bits/stdc++.h>
using namespace std;

using ll = long long;

void input(vector<int> &v, int n){
	for(auto &it : v){
		cin >> it;
	}
}

ll sum_of_arr(vector<int> &v, int n){
	ll sum = 0;
	for(auto &it : v){
		sum += it;
	}
	return sum;
}

void show(vector<int> &v, int n){
	for(auto &it : v){
		cout << it << ' ';
	}
}

pair<int, int> min_max_val(vector<int> &v, int n){
	int min_val = INT_MAX;
	int max_val = INT_MIN;
	for(auto &it : v){
		if(it < min_val) min_val = it;
		if(it > max_val) max_val = it;
	}
	return {min_val, max_val};
}

void merge(vector<int> &v, int l, int m, int r){
	int n1 = m - l + 1;
	int n2 = r - m;
	vector<int> L(n1), R(n2);
	for(int i = 0; i < n1; i++){
		L[i] = v[l + i];
	}
	for(int i = 0; i < n2; i++){
		R[i] = v[m + i + 1];
	}
	
	int i = 0, j = 0, cnt = l;
	while(i < n1 && j < n2){
		if(L[i] <= R[j]){
			v[cnt++] = L[i++];
		}
		else{
			v[cnt++] = R[j++];
		}
	}
	while(i < n1) v[cnt++] = L[i++];
	while(j < n2) v[cnt++] = R[j++];
}

void mergeSort(vector<int> &v, int l, int r){
	if(l < r){
		int m = (l + r)/2;
		mergeSort(v, l, m);
		mergeSort(v, m + 1, r);
		merge(v, l, m, r);
	}
}

int main(){
	int n; cin >> n;
	vector<int> v(n);
	input(v, n);
	show(v, n);
	cout << "\ntong day: " << sum_of_arr(v, n) << endl;
	pair<int, int> p = min_max_val(v, n);
	cout << "Gia tri lon nhat trong day la: " << p.second << endl;
	cout << "Gia tri nho nhat trong day la: " << p.first << endl;
	mergeSort(v, 0, v.size() - 1);
	show(v, n);
	return 0;
}