#include <bits/stdc++.h>
using namespace std;

struct CongViec {
    string maCV;
    string startTime;
    double thoiLuong;
};

vector<CongViec> ds_CongViec() {
    return {
        {"CV001", "08:00", 0.5},
        {"CV002", "09:00", 1.0},
        {"CV003", "10:00", 0.25},
        {"CV004", "10:30", 0.5},
        {"CV005", "11:00", 0.75},
        {"CV006", "13:00", 1.5},
        {"CV007", "14:30", 0.25},
        {"CV008", "15:00", 0.5}
    };
}

vector<string> ds_NhanVien() {
    return {"Alice", "Bob", "Charlie", "David", "Eve", "Frank", "Grace", "Hank"};
}

// A1: Hiển thị danh sách công việc theo thứ tự ngược lại
void A1(vector<CongViec> &congViecs, int i) {
    if (i < 0) return;
    cout << congViecs[i].maCV << " bắt đầu lúc " << congViecs[i].startTime << " trong " << congViecs[i].thoiLuong << " giờ\n";
    A1(congViecs, i - 1);
}

// A2: Đếm số công việc có thời lượng <= 30 phút
int A2(vector<CongViec> &congViecs, int l, int r) {
    if (l > r) return 0;
    if (l == r) return congViecs[l].thoiLuong <= 0.5 ? 1 : 0;
    int mid = (l + r) / 2;
    return A2(congViecs, l, mid) + A2(congViecs, mid + 1, r);
}

// A3: Phân công công việc cho nhân viên
void A3(vector<int> &phanCong, vector<CongViec> &congViecs, vector<string> &nhanViens) {
    for (int i = 0; i < phanCong.size(); ++i) {
        cout << congViecs[i].maCV << " -> " << nhanViens[phanCong[i]] << "\n";
    }
    cout << "\n";
}

void phanCongCongViec(int k, int n, vector<int> &phanCong, vector<bool> &daSuDung, vector<CongViec> &congViecs, vector<string> &nhanViens) {
    if (k == n) {
        A3(phanCong, congViecs, nhanViens);
        return;
    }
    for (int i = 0; i < n; ++i) {
        if (!daSuDung[i]) {
            daSuDung[i] = true;
            phanCong[k] = i;
            phanCongCongViec(k + 1, n, phanCong, daSuDung, congViecs, nhanViens);
            daSuDung[i] = false;
        }
    }
}

int main() {
    vector<CongViec> congViecs = ds_CongViec();
    vector<string> nhanViens = ds_NhanVien();
    int n = congViecs.size();

    // A1: Hiển thị công việc theo thứ tự ngược lại
    cout << "Công việc theo thứ tự ngược lại:\n";
    A1(congViecs, n - 1);
    cout << "\n";

    // A2: Đếm số công việc có thời lượng <= 30 phút
    int soLuongCongViecNgan = A2(congViecs, 0, n - 1);
    cout << "Số công việc có thời lượng <= 30 phút: " << soLuongCongViecNgan << "\n\n";

    // A3: Phân công công việc cho nhân viên
//    vector<int> phanCong(n, -1);
//    vector<bool> daSuDung(n, false);
//    cout << "Tất cả các phương án phân công công việc:\n";
//    phanCongCongViec(0, n, phanCong, daSuDung, congViecs, nhanViens);

    return 0;
}
