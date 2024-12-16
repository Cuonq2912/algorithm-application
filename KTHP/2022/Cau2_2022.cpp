#include <bits/stdc++.h>
using namespace std;

struct lopHoc
{
	string maLop;
	int soHS;
	int soHSNu;
};

void showTitle()
{
	cout << "Ma lop" << setw(15) << "So hoc sinh" << setw(10) << "So hs nu" << endl;
}

void show(lopHoc x)
{
	cout << x.maLop << setw(15) << x.soHS << setw(10) << x.soHSNu << endl;
}
// tham lam: Cho biết cần lấy từ ít nhất bao nhiêu lớp
// trong danh sách d để được số học sinh lớn hơn n.
int tl(lopHoc x[], int n, int m)
{
	int i = 0;
	while (i < n && m >= 0)
	{
		m -= x[i].soHS;
		i++;
	}
	if (m < 0)
		return i;
	return -1;
}

struct ketqua
{
	int cnt = 0;
	vector<lopHoc> p;
};
// Cần ghép những lớp nào vào phòng học p để được tổng số
//  học viên không vượt quá k
//  mà tổng số học sinh nữ đạt được nhiều nhất
int QHD(lopHoc x[], int n, int k, ketqua &result)
{
	lopHoc x_new[n + 1];
	x_new[0] = {"", 0, 0};
	for (int i = 0; i < n; i++)
	{
		x_new[i + 1] = x[i];
	}
	int F[n + 1][k + 1];
	for (int j = 0; j <= k; j++)
	{
		F[0][j] = 0;
	}
	for (int i = 1; i <= n; i++)
	{
		for (int j = 0; j <= k; j++)
		{
			F[i][j] = F[i - 1][j];
			if (x_new[i].soHS <= j)
			{
				int tmp = x_new[i].soHSNu + F[i - 1][j - x_new[i].soHS];
				if (F[i][j] < tmp)
				{
					F[i][j] = tmp;
				}
			}
		}
	}
	int soHSnumax = F[n][k];
	int i = n, j = k;
	while (i != 0)
	{
		if (F[i][j] != F[i - 1][j])
		{
			result.cnt++;
			result.p.push_back(x_new[i]);
			j -= x_new[i].soHS;
		}
		i--;
	}
}

int char_in_string(char x, string s)
{
	for (int i = s.length() - 1; i >= 0; i--)
	{
		if (s[i] == x)
			return i;
	}
	return -1;
}

bool BMH(string s, string t)
{
	int v = s.length(), i = v - 1;
	while (i < t.length())
	{
		int k = v - 1;
		while (t[i] == s[k] && k >= 0)
		{
			k--;
			i--;
		}
		if (k < 0)
			return true;
		else
		{
			int x = char_in_string(t[i], s);
			if (x < 0)
				i += v;
			else
				i += v - x - 1;
		}
	}
	return false;
}

int dem_BMH(lopHoc x[], int n)
{
	int cnt = 0;
	for (int i = 0; i < n; i++)
	{
		if (BMH("it", x[i].maLop))
		{
			cnt++;
		}
	}
	return cnt;
}

bool z_algo(string s, string t)
{
	string p = s + "%" + t;
	vector<int> z(p.length());
	int n = p.length(), l = 0, r = 0;
	z[0] = -1;
	for (int i = 1; i < n; i++)
	{
		if (r < i)
		{
			l = r = i;
			while (r < n && p[r] == p[r - l])
			{
				r++;
			}
			z[i] = r - l;
			r--;
		}
		else if (z[i - l] < r - i + 1)
		{
			z[i] = z[i - l];
		}
		else
		{
			l = i;
			while (r < n && p[r] == p[r - l])
			{
				r++;
			}
			z[i] = r - l;
			r--;
		}
	}
	for (int i = s.length() + 1; i < n; i++)
	{
		if (z[i] == s.length())
			return true;
	}
	return false;
}

void hienthi(lopHoc x[], int n)
{
	for (int i = 0; i < n; i++)
	{
		if (z_algo("it", x[i].maLH))
		{
			show(x[i]);
		}
	}
}

int main()
{
	int n = 7;
	lopHoc ds[n] = {
		{"tdh01", 70, 16},
		{"it01", 65, 24},
		{"ktpm02", 62, 22},
		{"it01", 60, 26},
		{"it02", 58, 25},
		{"dtvt01", 55, 22},
		{"it03", 50, 18}};

	int m = 300;
	int anstl = tl(ds, n, m);
	if (anstl > 0)
	{
		cout << "So lop it nhat can lay de so hoc sinh > " << m << " la: " << anstl << endl;
	}
	else
		cout << "khong dat duoc yeu cau";

	int k = 200; // khong qua k
	ketqua result;
	QHD(ds, n, k, result);
	if (result.cnt > 0)
	{
		cout << "So lop hoc duoc chon la de so hoc sinh ko qua " << k << " va nhieu nu nhat la: \n";
		showTitle();
		for (lopHoc x : result.p)
		{
			show(x);
		}
	}
	else
		cout << "Khong lop nao duoc chon";

	cout << "So lop chua tu it la: " << dem_BMH(ds, n) << endl;
}