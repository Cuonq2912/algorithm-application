//                   Bài tập 4: Cho danh sách L chứa thông tin của n học sinh, thông tin của mỗi học sinh 
//                   gồm tên, họ đệm, năm sinh, địa chỉ. 
//                   - Thiết kế thuật toán S với độ phức tạp O(nlgn) để sắp xếp danh sách L bằng tên 
//                   học sinh theo thứ tự từ điển.
//                   - Thiết kế thuật toán T để tìm và trả về vị trí của một học sinh trong danh sách L 
//                   theo tên học sinh bằng chiến lược chia để trị.
//                   - Cài đặt chương trình thực hiện:
//                   o Khởi tạo n (n > 5) và danh sách L gồm n học sinh.
//                   o Cài đặt các thuật toán S và T.
//                   o Sắp xếp danh sách học sinh bằng thuật toán S, hiển thị danh sách L sau 
//                   khi sắp xếp.
//                   o Khởi tạo chuỗi x là tên của một học sinh, tìm vị trí xuất hiện của học sinh 
//                   có tên x bằng thuật toán T, hiển thị thông tin đầy đủ của học sinh nếu tìm 
//                   được (nếu danh sách có nhiều học sinh trùng tên chỉ cần hiển thị thông tin 
//                   của học sinh tìm thấy đầu tiên).


#include<bits/stdc++.h>
using namespace std;

struct HocSinh{
	string ten;
	string hoDem;
	int namSinh;
	string diaChi;
};


// Thuật toán S
void merge(HocSinh *L, int l, int m, int r){
	int n1 = m - l + 1;
	int n2 = r - m;
	HocSinh Left[n1], Right[n2];
	for(int i = l; i < m + 1; i++){
		Left[i - l] = L[i];
	}
	for(int i = m + 1; i <= r; i++){
		Right[i - m - 1] = L[i];
	}
	
	int i = 0, j = 0, cnt = l;
	while(i < n1 && j < n2){
		if(Left[i].ten <= Right[j].ten){
			L[cnt++] = Left[i++];
		}
		else{
			L[cnt++] = Right[j++];
		}
	}
	while(i < n1) L[cnt++] = Left[i++];
	while(j < n2) L[cnt++] = Right[j++];
}

void mergeSort(HocSinh *L, int l, int r){
	if(l < r){
		int m = l + (r - l)/2;
		mergeSort(L, l, m);
		mergeSort(L, m + 1, r);
		merge(L, l, m, r);
	}
}


void show_lists(HocSinh *L, int n){
	for(int i = 0; i < n; i++){
		cout << L[i].ten << " " << L[i].hoDem << " " << L[i].namSinh << " " << L[i].diaChi << endl;
	}
}

// Thuật toán T
int BinarySearch(HocSinh *L, int l, int r, string name){
	while(l < r){
		int m = l + (l - r)/2;
		if(L[m].ten == name) return m;
		else if(L[m].ten > name){
			l = m + 1;
		}
		else{
			r = m - 1;
		}
	}
	return -1; // khong tim thay.
}

int main(){
	// nhap ds hoc sinh
	HocSinh hocsinhs[6] = {
        {"Alice", "Johnson", 2005, "123 Main St"},
        {"Bob", "Smith", 2004, "456 Maple Ave"},
        {"Charlie", "Brown", 2003, "789 Oak Dr"},
        {"David", "Wilson", 2005, "101 Pine St"},
        {"Eve", "Davis", 2004, "202 Elm St"},
        {"Alice", "Taylor", 2005, "303 Cedar St"} // Học sinh trùng tên
    };
	mergeSort(hocsinhs, 0, 5);
	show_lists(hocsinhs, 6);
}