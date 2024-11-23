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
#include<bits/stdc++.h>
using namespace std;

struct HocSinh{
	string MaHS;
	string hoDem;
	string ten;
	int namSinh;
};

// quay lui sinh hoan vi

void show(int i, HocSinh *d){
	cout << d[i - 1].MaHS << " " << d[i - 1].hoDem << " " << d[i - 1].ten << " " << d[i - 1].namSinh << endl;
}

void view_config(int *x, int n, HocSinh *d){
	for(int i = 1; i <= n; i++){
		show(x[i], d);
	}
}
void Try(int k, int *x, int n, bool *used, HocSinh *d){
	for(int i = 1; i <= n; i++){
		if(!used[i]){
			x[k] = i;
			if(k == n){
				view_config(x, n, d);
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

void next_config(int *x, int m, int i){
	x[i] += 1;
	i++;
	while(i <= m){
		x[i] = x[i - 1] + 1;
		i++;
	}
}
void show_config(int *x, int m, HocSinh *d){
	for(int i = 1; i <= m; i++){
//		cout << x[i] << ' ';
		show(x[i], d);
	}
	cout << endl;
}
void list_configs(int m, int n, HocSinh *d){
	int i;
	int x[m + 1] = {0};
	for(int j = 1; j <= m; j++){
		x[j] = j;
	}
	do{
		show_config(x, m, d);
		i = m;
		while(i > 0 && x[i] == n - m + i) i--;
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
    int *x = new int[n + 1];
    bool *used = new bool[n + 1];
    for(int i = 1; i <= n; i++){
    	used[i] = false;
	}
	cout << "Các phương án khác nhau để xếp n học sinh trong danh sách d vào n chỗ ngồi được ghi số thứ tự từ 1 đến n là: \n\n";
	Try(1, x, n, used, d);
	cout << "\n\n\n";
	
	cout << "Nhap m: ";
	int m; cin >> m;
	cout << "các phương án khác nhau để lấy m (m < n) học sinh từ danh sách d\n";
	list_configs(m, n, d);
	delete[] x;
	delete[] used;
	delete[] d;
}