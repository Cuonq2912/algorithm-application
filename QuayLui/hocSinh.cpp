#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define el "\n"


struct hocSinh{
    string ten;
    string ho_dem;
    int namsinh;
    string diachi;
}

int partition(vector<hocSinh> hocsinhs, int l, int r){
    hocSinh pivot = hocsinhs[r];
    int i = l - 1;
    for(int i = l; i < r; i++){
        if(hocSinh[j].ten > pivot.ten){
            ++i;
            swap(hocSinhs[i], hocSinhs[j]);
        }
    }
    ++i;
    swap(hocsinhs[i], hocsinhs[r]); 
    return i;
}

void quickSort(vector<hocSinh> hocsinhs, int l, int r){
    if(l < r){
        hocSinh p = partition(hocSinh, l, r);
        quickSort(hocSinh, l, p - 1);
        quickSort(hocSinh, q + 1, r);
    }
}


int pos_hocSinh(vector<hocSinh> hocsinhs, int l, int r, string name){
    while(l <= r){
        int m = (l + r)/2;
        if(hocsinhs[m].ten == name) return m;
        else if(hocsinhs[m].ten < name) l = m + 1;
        else r = m - 1;
    }
    return -1;
}

int main(){
    int n;

    do{
        cin >> n;
    }while(n <= 5);

    vector<hocSinh> hocsinhs(n);

    for(int i = 0; i < n; i++){
        cin >> hocSinh[i].ten >> hocSinh[i].ho_dem >> hocSinh[i].namsinh;
        cin.ignore();
        getline(cin, hocSinh[i].diachi);
    }
    quickSort(hocSinhs, 0, n);
    for(int i = 0; i < n; i++){
        cout << hocSinh[i].ten << ' ' << hocSinh[i].ho_dem << ' ' << hocSinh[i].namsinh << ' ' << hocSinh[i].diachi << el;
    }

    cin.ignore();
    string name; getline(cin, name);
    int pos_hs = pos_hocSinh(hocsinhs, 0, n, name);
    if(pos_hs == -1){
        cout << "Khong tim thay hoc sinh";
    }
    else{
        int i = pos_hs;
        cout << hocSinh[i].ten << ' ' << hocSinh[i].ho_dem << ' ' << hocSinh[i].namsinh << ' ' << hocSinh[i].diachi << el;
        return 0;
    }
    
    return 0;
}