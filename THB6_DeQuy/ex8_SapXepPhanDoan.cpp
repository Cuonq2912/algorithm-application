#include<bits/stdc++.h>
using namespace std;

using ll = long long;
#define el "\n"
#define MAX 10

int ds[] = {11, 12, 13, 14, 15, 16, 17, 18, 19, 20};

void merge(int a[], int l, int m, int r){
	int n1 = m - l + 1;
	int n2 = r - m;
	int L[n1], R[n2];
	for(int i = l; i <= m; i++){
		L[i - l] = a[i];
	}
	for(int i = m + 1; i <= r; i++){
		R[i - m - 1] = a[i];
	}
	
	int i = 0, j = 0, cnt = l;
	while(i < n1 && j < n2){
		if(L[i] <= R[j]){
			a[cnt++] = L[i++];
		}
		else{
			a[cnt++] = R[j++];
		}
	}
	while(i < n1) a[cnt++] = L[i++];
	while(j < n2) a[cnt++] = R[j++];
}

void mergeSort(int a[], int l, int r){
	if(l <= r){
		int m = (l + r)/2;
		mergeSort(a, l, m - 1);
		mergeSort(a, m + 1, r);
		merge(a, l, m, r); 
	}
}

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	mergeSort(ds, 0, MAX - 1);
	for(int i = 0; i < MAX; i++){
		cout << ds[i] << " ";
	}
}