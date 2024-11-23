#include<bits/stdc++.h>
using namespace std;



bool A1(int *a, int n, int m, int *cnt){ // mang menh gia, so menh gia, 
	int i;							// so tien can doi, mang dem so xu ung voi menh gia
	for(int j = 0; j < n; j++){			// cnt[i] > 0 tuc dong i lay cnt[i] xu
		cnt[j] = 0;
	}
	i = 0;
	while(i < n && m > 0){
		cnt[i] = m / a[i];
		m %= a[i];
		i++;
	}
	if(m > 0) return false;
	else return true; 
}

void merge(int *a, int l, int m, int r){
	int n1 = m - l + 1;
	int n2 = r - m;
	int L[n1], R[n2];
	for(int i = l; i < m + 1; i++){
		L[i - l] = a[i];
	} 
	for(int i = m + 1; i <= r; i++){
		R[i - m - 1] = a[i];
	}
	int i = 0, j = 0, cnt = l;
	while(i < n1 && j < n2){
		if(L[i] >= R[j]){
			a[cnt++] = L[i++];
		}
		else{
			a[cnt++] = R[j++];
		}
	}
	while(i < n1) a[cnt++] = L[i++];
	while(j < n2) a[cnt++] = R[j++];
	
}

void mergeSort(int *a, int l, int r){
	if(l < r){
		int m = l + (r - l) / 2;
		mergeSort(a, l, m);
		mergeSort(a, m + 1, r);
		merge(a, l, m, r);
	}
}

int main(){
	long n = 5 , m = 34; // so menh gia xu, so tien
	int a[] = {1, 10, 5, 25, 100}; // menh gia xu
	mergeSort(a, 0, n - 1); // sx
	
	int *cnt = new int[n];
	
	if(!A1(a, n, m, cnt)){
		cout << "Khong the doi";
	}
	else{
		for(int i = 0; i < n; i++){
			if(cnt[i] > 0){
				cout << "Co " << cnt[i] << " to menh gia " << a[i] << " dong." << endl; 
			} 
		}
	}
	delete[] cnt;
	return 0;
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
}