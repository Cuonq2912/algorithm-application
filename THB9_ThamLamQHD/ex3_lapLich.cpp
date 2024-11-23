#include<bits/stdc++.h>
using namespace std;


int n = 6;
double s[] = {7, 8, 9.5, 11, 11.5, 13}; //start
double f[] = {9, 9, 12, 13, 14.5, 16}; // end
int kq[] = {0, 0, 0, 0, 0, 0, 0};

void inDS(int kq[]){
	for(int i = 0; i < n; i++){
		if(kq[i]){
			cout << s[i] << ' ' << f[i] << endl;
		}
	}
}

void Swap(double &a, double &b){
	double tmp = a;
	a = b; b = tmp;
}


int Schedule(int n, double s[], double f[]){
	for(int i = 0; i < n - 1; i++){
		for(int j = 0; j < n - i - 1; j++){
			if(f[j] > f[j + 1]){
				Swap(f[j], f[j + 1]);
				Swap(s[j], s[j + 1]);
			}
		}
	}	
	int cnt = 1;
	double curr_endtime = f[0];
	kq[0] = 1;
	for(int i = 1; i < n; i++){
		if(curr_endtime <= s[i]){
			cnt++;
			kq[i] = 1;
			curr_endtime = f[i];
		}
	}
	return cnt;
}

int main(){
	cout << "Co " << Schedule(n, s, f) << " cong viec la: \n";
	inDS(kq);	
}



