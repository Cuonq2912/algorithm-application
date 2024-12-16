#include <bits/stdc++.h>
using namespace std;

// tinh tong tat ca cac so trong mang a theo chia de tri, dequy
double t_cdt(double a[], int l, int r)
{
	if (l == r)
		return a[l];
	else
	{
		int m = (l + r) / 2;
		return t_cdt(a, l, m) + t_cdt(a, m + 1, r);
	}
}

double t_dq(double a[], int n)
{
	if (n == 0)
		return 0;
	else
		return a[n - 1] + t_dq(a, n - 1);
}

// tinh tong tat ca cac so le trong mang a gom n so nguyen cdt, dq
void tl_cdt(int a[], int l, int r, int &sum, int &count)
{
	if (l == r)
	{
		if (a[l] % 2 != 0)
		{
			sum += a[l];
			count++;
		}
	}
	else
	{
		int m = (l + r) / 2;
		tl_cdt(a, l, m, sum, count);
		tl_cdt(a, m + 1, r, sum, count);
	}
}

double tl_dq(int a[], int n, int &sum, int &count)
{
	if (n == 0)
		return 0;
	else
	{
		if (a[n - 1] % 2 != 0)
		{
			sum += a[n - 1];
			count++;
			tl_dq(a, n - 1, sum, count);
		}
		else
			tl_dq(a, n - 1, sum, count);
	}
}

// tim kiem so thuc k theo cdt, dq
double search_cdt(double a[], double &k, int l, int r)
{
	if (l > r)
		return -1;
	if (l == r)
	{
		if (a[l] == k)
			return l;
		else
			return -1;
	}
	int m = (l + r) / 2;
	int x = search_cdt(a, k, l, m);
	int y = search_cdt(a, k, m + 1, r);
	if (x >= 0)
		return x;
	if (y >= 0)
		return y;
}

double search_dq(double a[], int n, double &k)
{
	if (a[n - 1] == k)
		return n - 1;
	if (n < 0)
		return -1;
	return search_dq(a, n - 1, k);
}
// Tim max bang cdt, dq
double max_cdt(double a[], int l, int r)
{
	if (l == r)
		return a[l];
	int m = (l + r) / 2;
	double x = max_cdt(a, l, m);
	double y = max_cdt(a, m + 1, r);
	return x > y ? x : y;
}

double max_dq(double a[], int n)
{
	if (n == 1)
		return a[0];
	int x = max_dq(a, n - 1);
	return x > a[n] ? x : a[n];
}

int main()
{
	int n = 10;
	double a[n] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
	cout << "Tong cac so trong mang la: " << t_cdt(a, 0, n - 1) << endl;
	cout << "Tong cac so trong mang la: " << t_dq(a, n) << endl;

	int b[n] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
	int sum = 0, count = 0;

	tl_cdt(b, 0, n - 1, sum, count);
	cout << "Tong cac so le trong mang la: " << sum << endl;
	cout << "Co " << count << " so!!\n";
	tl_dq(b, n, sum, count);
	cout << "Tong cac so le trong mang la: " << sum << endl;
	cout << "Co " << count << " so!!\n";

	double k = 9;
	int pos_k = search_dq(a, n, k);
	int pos_k2 = search_cdt(a, k, 0, n - 1);
	if (k > 0)
	{
		cout << "Vi tri cua k trong mang la: " << pos_k2 << endl;
	}
	else
		cout << "k khong nam trong mang!!" << endl;
	cout << "Vi tri cua phan tu max trong mang la: " << max_cdt(a, 0, n - 1) << endl;
	cout << "Vi tri cua phan tu max trong mang la: " << max_dq(a, n) << endl;
}
