//Khử đệ quy.
//- Viết lại thuật toán sắp xếp phân đoạn theo phương pháp quay lui.
//- Khử đệ quy thuật toán sắp xếp phân đoạn vừa viết.
//- Cài đặt chương trình thực hiện:
//o Khởi tạo mảng a gồm tối thiểu 3000 số nguyên, các số được khởi tạo ngẫu 
//nhiên.
//o Áp dụng thuật toán sắp xếp phân đoạn vừa được khử đệ quy để sắp xếp, 
//theo dõi thời gian chạy thuật toán.

#include<bits/stdc++.h>
//#include <ctime>
using namespace std;
// thuật toán sắp xếp phân đoạn theo phương pháp quay lui.
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

void mergeSort(int *a, int l, int r){
	if(l < r){
		int m = (l + r)/2;
		mergeSort(a, l, m);
		mergeSort(a, m + 1, r);
		merge(a, l, m, r);
	}
}


// quickSort khử đệ quy.
void Swap(int &a, int &b) {
    int tmp = a;
    a = b;
    b = tmp;
}

int partition(int *a, int l, int r) {
    int pivot = a[r];
    int i = l - 1;
    for (int j = l; j < r; j++) {
        if (a[j] < pivot) {
            i++;
            Swap(a[i], a[j]);
        }
    }
    i++;
    Swap(a[i], a[r]);
    return i;
}

void quickSort(int *a, int n) {
    stack<pair<int, int>> Stack;
    Stack.push({0, n - 1});
    while (!Stack.empty()) {
        int low = Stack.top().first;
        int high = Stack.top().second;
        Stack.pop();
        if (low < high) {
            int p = partition(a, low, high);
            if (p - 1 > low) Stack.push({low, p - 1});
            if (p + 1 < high) Stack.push({p + 1, high});
        }
    }
}
//void quickSort(int *a, int l, int r){
//	if(l < r){
//		int p = partition(a, l, r);
//		quickSort(a, l, p - 1);
//		quickSort(a, p + 1, r);
//	}
//}

int main() {
    int n;
    cout << "Nhap so luong phan tu cua day: ";
    do {
        cin >> n;
    } while (n < 100);

    int *a = new int[n + 1];
    srand(0);
    for(int i = 0; i < n; i++){
    	a[i] = rand() % 100;
	}
	quickSort(a, n);
	for(int i = 0; i <n; i++){
		cout << a[i] << ' ';
	}
	delete[] a;
    return 0;
}
