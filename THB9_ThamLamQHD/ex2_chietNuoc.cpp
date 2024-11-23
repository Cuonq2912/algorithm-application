#include<bits/stdc++.h>
using namespace std;

void Swap(int &a, int &b){
	int tmp = a;
	a = b;
	b = tmp;
}

int partition(int a[], int l, int r){
	int pivot = a[r];
	int i = l - 1;
	for(int j = l; j < r; j++){
		if(a[j] <= pivot){
			i++;
			Swap(a[i], a[j]);
		}
	}
	i++;
	Swap(a[i], a[r]);
	return i;
}

void quickSort(int a[], int l, int r){
	if(l < r){
		int p = partition(a, l, r);
		quickSort(a, l, p - 1);
		quickSort(a, p + 1, r);
	}
}

int A2(int a[], int n, int d, bool *dd){
	int i = 0, cnt = 0;
	while(i < n && d > 0){
		if(d >= a[i]){
			cnt++;
			dd[i] = 1;
			d -= a[i];
			i++;
		}
		else break;
	}
	return cnt;
}



int main(){
	int n = 7, d = 35;
	int a[n] = {3, 12, 5, 23, 6, 5, 9};
	quickSort(a, 0, n - 1);
	bool *dd = new bool[n];
	
	int soBinh = A2(a, n, d, dd);
	cout << "Do day duoc " << soBinh << endl;
	for(int i = 0; i < n; i++){
		if(dd[i]){
			cout << a[i] << ": 1" << endl; 
		}
		else{
			cout << a[i] << ": 0" << endl;
		}
	}
	
	delete[] dd;
	return 0;
}