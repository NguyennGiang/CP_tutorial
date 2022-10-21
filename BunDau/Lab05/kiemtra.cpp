#include <bits/stdc++.h>
using namespace std;

struct SP
{
    string MaSP;
    string TenSP;
    int soluong;
    float dongia;

    float getTien(){
        return 1.0 * soluong * dongia;
    }

    float getGiam(){
        if (soluong < 10) return 0.0;
        if (soluong < 50) return 0.01;
        if (soluong < 100) return 0.02;
        if (soluong < 200) return 0.025;
        return 0.03;
    }
    
    float get(){
        return getTien() - getTien() * getGiam();
    }

};

struct PhieuNhap {
    string ten;
    int ngay;
    int thang;
    int nam;
    int soluong;
    float thanhtoan;
    vector<SP> sanpham;

    float getSum(){
        float sum = 0;  
        for (int i = 0; i < sanpham.size(); i++){
            sum += sanpham[i].getTien();
        }
        return sum;
    }

    float getGiam(){
        float giam = 0;
        for (int i = 0; i < sanpham.size(); i++){
            giam += sanpham[i].getGiam() * sanpham[i].getTien();
        }
        return giam;
    }
    float getThua(){
        return thanhtoan - getSum() + getGiam();
    }
};


void showInfor(PhieuNhap p){
    cout << '\n';
    cout << '\t' << "Ten nha cung cap: " << p.ten << endl;
    cout << '\t' << "Ngay thu: Ngay " << p.ngay << " thang " << p.thang << " nam " << p.nam << endl;
    cout << '\t' << "So san pham: " << p.soluong << endl;
    cout << '\t' << "Tong da thanh toan: " << p.thanhtoan << endl;
    cout << '\t' << "Tong phai thanh toan: " << p.getSum() << endl;
    cout << '\t' << "Tong tien giam: " << p.getGiam() << endl;
    cout << '\t' << "Thanh toan thua: " << p.getThua() << endl;
    cout << endl << '\t' << "Chi tiet cac san pham: \n";
    cout << "\tTMaSp \tTenSanPham \tDongia \tSoluong \tThanhtien \tgiam\n";
    for (int i = 0; i < p.sanpham.size(); i++){
        cout << '\t' << p.sanpham[i].MaSP << '\t' << p.sanpham[i].TenSP << '\t' << p.sanpham[i].dongia << '\t';
        cout << p.sanpham[i].soluong << '\t' << p.sanpham[i].getTien() << '\t' << p.sanpham[i].getGiam() * p.sanpham[i].getTien() << endl;
    }
}

int main(){
    vector<PhieuNhap> list;

    while(true){
        cout << endl;
        cout << "Ho va ten : Nguyen Duc Giang \nMSSV : 20204826 " << endl;
        cout << "** CHUONG TRINH QUAN LY NHA CC **" << endl;
        cout << "** 1. Nhap nha CC phieu nhap **" << endl;
        cout << "** 2. IN KET QUA PHIEU Phieu nhap - San pham \n";
        cout << "** 0. Thoat **\n";
        cout <<"*******************************\n**   Nhap lua chon cua ban   **\n";

        int n;
        cin >> n;

        switch(n){
            case 0: return 0;
            case 1: {
                cout << "Ban da chon nhap ds Phieu Nhap SP!\n";
                cout << "Nhap so Phieu Nhap: ";
                int soluong; cin >> soluong;

                for (int i = 1; i <= soluong; i++){
                    PhieuNhap tmp;
                    cout << "Nhap thong tin phieu nhap " << i << ":\n";
                    
                    cout << "\tTen nha cung cap: ";
                    fflush(stdin);
                    string s; getline(cin, s); tmp.ten = s;

                    cout << "\tNgay: "; 
                    int ngay; cin >> ngay; tmp.ngay = ngay;

                    cout << "\tThang: ";
                    int thang; cin >> thang; tmp.thang = thang;

                    cout << "\tNam: ";
                    int nam; cin >> nam; tmp.nam = nam;

                    cout << "\tSo san pham: ";
                    int cnt; cin >> cnt; tmp.soluong = cnt;

                    cout << "\tNhap danh sach san pham: \n";

                    SP sp;
                    for (int j = 1; j <= cnt; j++){
                        cout << "\tSan pham: " << j << endl;

                        cout << "\t\tMa so SP: ";
                        fflush(stdin);
                        getline(cin, sp.MaSP);

                        cout << "\t\tTen san pham: ";
                        fflush(stdin);
                        getline(cin, sp.TenSP);

                        cout << "\t\tSo luong san pham: ";
                        cin >> sp.soluong;

                        cout << "\t\tDon gia nhap: ";
                        cin >> sp.dongia;

                        tmp.sanpham.push_back(sp);
                    }

                    cout << "\tSo tien da thanh toan: ";
                    cin >> tmp.thanhtoan;
                
                    list.push_back(tmp);
                }   
                cout << "Ban da nhap thanh cong!\n";
                break;
            }
            case 2: {
                if (list.size() == 0){
                    cout << "Ban chua nhap du lieu Phieu Nhap\n";
                    break;
                }
                cout << "Ban da chon xuat phieu nhap! \n";
                float sum = 0;
                float thanhtoan = 0;
                float giam = 0;
                for (int i = 0; i < list.size(); i++){
                    sum += list[i].getSum();
                    thanhtoan += list[i].thanhtoan;
                    giam += list[i].getGiam();
                    showInfor(list[i]);
                }

                cout << "Tong phai thanh toan cac phieu nhap: " << sum << endl;
                cout << "Tong da thanh toan cac phieu nhap: " << thanhtoan << endl;
                cout << "Tong duoc giam cua cac phieu nhap: " << giam << endl;
                cout << "Tong thanh toan thua: " << thanhtoan - sum + giam << endl;
                break;
            }
            default: {
                cout << "Moi ban nhap lai!\n";
                break;
            }
        }
    }
    return 0;
}
