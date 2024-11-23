//				Bài 7: Chủ nhật tuần sau Nhà trường tổ chức n hội thảo về n chủ đề khác nhau, thông tin về
//				mỗi hội thảo gồm: chủ đề (ví dụ: tìm kiếm việc làm, nâng cao kỹ năng mềm,…), thời gian bắt đầu, thời gian kết thúc.
//				Thiết kế thuật toán cho biết một sinh viên có thể tham dự được nhiều nhất bao nhiêu hội thảo, gồm những hội thảo nào.
//				Khởi tạo n, danh sách n hội thảo, sử dụng thuật toán trên để cho biết số lượng hội thảo và 
//				thông tin các hội thảo mà sinh viên có thể tham gia.

#include<bits/stdc++.h>
using namespace std;

struct HoiThao{
	string subject;
	double startTime;
	double endTime;
};

void showData(HoiThao x){
	cout << x.subject << " " << x.startTime << " " << x.endTime << endl; 
}

void Swap(HoiThao &x, HoiThao &y){
	HoiThao tmp = x;
	x = y;
	y = tmp;
}

void SortEndTime(HoiThao danhSach[], int n){
	for(int i = 0; i < n - 1; i++){
		for(int j = 0; j < n - i - 1; j++){
			if(danhSach[j].endTime > danhSach[j + 1].endTime){
				Swap(danhSach[j], danhSach[j + 1]);
			}
		}
	}
}

void solve(HoiThao danhSach[], int n, bool dd[]){
	int cnt = 0, cur_endTime = 0;
	for(int i = 0; i < n; i++){
		if(danhSach[i].startTime >= cur_endTime){
			dd[i] = true;
			cnt++;
			cur_endTime = danhSach[i].endTime;
		}
	}
	cout << "Co the tham gia nhieu nhat " << cnt << " hoi thao\n\n";
	cout << "Danh sach cac hoi thao \n";
	for(int i = 0; i < n; i++){
		if(dd[i] == true){
			showData(danhSach[i]);
		}
	}
}


int main(){
	int n = 7;
	HoiThao danhSach[n] = {
		{"tim kiem viec lam", 7, 9},
		{"nang cao ky nang mem", 8.5, 9.5},
		{"tim kiem sinh vien tiem nang", 9, 10},
		{"tim hieu ve cong nghe moi", 11.5, 12.5},
		{"phat trien ky nang lap trinh", 10, 11},
		{"doi moi trong giao duc", 9.5, 10.5},
		{"quan ly du an hieu qua", 8, 9}
	};
	SortEndTime(danhSach, n);
	bool dd[n];
	solve(danhSach, n, dd);
	
}