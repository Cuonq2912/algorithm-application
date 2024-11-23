//Thiết kế thuật toán E để tính giá trị của a^n với a là số thực và n là số nguyên 
//dương theo chiến lược chia để trị
//- Cài đặt chương trình thực hiện:
//o Cài đặt hàm biểu diễn thuật toán E.
//o Khởi tạo số thực a và số nguyên dương n.
//o Áp dụng thuật toán E để tính giá trị a^n
//o Hiển thị kết quả

#include<bits/stdc++.h>
using namespace std;

double powMod(double a, int n){
	if(n == 0) return 1;
	double half = powMod(a, n/2);
	if(n % 2 == 0) return half * half;
	else return half * half * a;
}

int main(){
	double a;int n;
	cin >> a >> n;
	if(n < 0) cout << 1.00/powMod(a, n);
	else cout << powMod(a, n);
}