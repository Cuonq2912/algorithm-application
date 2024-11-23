/*
Cho một danh sách d chứa dữ liệu về n học sinh (5 < n < 20), mỗi học sinh gồm các 
thông tin: Mã học sinh, họ đệm, tên, năm sinh.
− Thiết kế thuật toán A1 bằng phương pháp quay lui cho phép liệt kê ra tất cả các 
phương án khác nhau để xếp n học sinh trong danh sách d vào n chỗ ngồi được ghi 
số thứ tự từ 1 đến n. Biểu diễn thuật toán bằng mã giả.
− Thiết kế thuật toán A2 bằng phương pháp quay lui cho phép liệt kê ra tất cả các 
phương án khác nhau để lấy m (m < n) học sinh từ danh sách d. Biểu diễn thuật 
toán bằng mã giả.
Cài đặt chương trình thực hiện các yêu cầu sau:
− Khởi tạo n và danh sách d gồm n học sinh.
− Cài đặt các hàm biểu diễn các thuật toán A1 và A2. Ứng dụng các thuật toán và biểu 
diễn các kết quả
*/
// quay lui sinh hoan vi

#include<bits/stdc++.h>
using namespace std;

struct HocSinh{
	string maHS;
	string hoDem;
	string ten;
	int namSinh;
};
// in danh sach
void show(HocSinh *d, int i){
	cout << d[i - 1].maHS << " " << d[i - 1].hoDem << " " << d[i - 1].ten << " " << d[i - 1].namSinh << endl;

}
//in cau hinh 
void show_config(int *x, int n, HocSinh *d){
	for(int i = 1; i <= n; i++){
		show(d, x[i]);
	}
}
// quay lui sinh cau hinh, với tham so có phan tu thu k cua ch x
void Try(int k, int *x, int n, bool *used, HocSinh *d){
	for(int i = 1; i <= n; i++){
		if(!used[i]){
			x[k] = i;
			if(k == n){
				show_config(x, n, d);
				cout << endl;
			}
			else{
				used[i] = true;
				Try(k + 1, x, n, used, d);
				used[i] = false;		
			}
		}
	}
}
/*
− Thiết kế thuật toán A2 bằng phương pháp quay lui cho phép liệt kê ra tất cả các 
phương án khác nhau để lấy m (m < n) học sinh từ danh sách d. Biểu diễn thuật 
toán bằng mã giả.
*/

// cau hinh ke tiep
void next_config(int *x, int m, int i){
	x[i] += 1;
	i++;
	while(i <= m){
		x[i] = x[i - 1] + 1;
		i++;
	}
}
// in cau hinh
void show_config2(int *x, int m, HocSinh *d){
	for(int i = 1; i <= m; i++){
		show(d, x[i]);
	}
	cout << endl;
}
// danh sach cau hinh
void list_configs(int m, int n, HocSinh *d){
	int i;
	int x[m + 1] = {0};
	for(int j = 1; j <= m; j++){
		x[j] = j;
	}
	do{
		show_config2(x, m, d);
		i = m;
		while(i > 0 && x[i] == n - m + i) --i;
		if(i > 0) next_config(x, m, i); 
	}while(i > 0);
}


int main(){
	
	HocSinh *d = new HocSinh[6]{
        {"HS001", "Nguyen Van", "An", 2005},
        {"HS002", "Le Thi", "Binh", 2004},
        {"HS003", "Tran Minh", "Cuong", 2006},
        {"HS004", "Pham Van", "Duc", 2005},
        {"HS005", "Vu Thi", "Ha", 2004},
        {"HS006", "Doan Quoc", "Hung", 2006}
    };
    
    int n = 6;
    // khai bao 
    int *x;
    bool *used;
    x = new int[n + 1];
    used = new bool[n + 1];
    for(int i = 1; i <= n; i++){
    	used[i] = false;
	}
	
	cout << "các phương án khác nhau để xếp n học sinh trong danh sách d vào n chỗ ngồi là: \n";
	Try(1, x, n, used, d);
	cout << endl;
	
	int m; cout << "\n\n\nNhap m: ";
	cin >> m;
	cout << " các phương án khác nhau để lấy m (m < n) học sinh từ danh sách d là: \n";
	list_configs(m, n, d);
	
	return 0;
}