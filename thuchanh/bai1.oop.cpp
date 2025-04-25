#include <bits/stdc++.h>
#include <iostream>
using namespace std;

class SinhVien {
private:
    string maSv;
    string hoTen;
    string lop;
    string ngaySinh;
    float gpa;

public:
    SinhVien();
    friend void nhap(SinhVien &);
    friend void in(SinhVien);
    void chuanHoaNgaySinh(); 
};

// Hàm dựng mặc định
SinhVien::SinhVien() {
    this->gpa = 0;
    this->maSv = "";
    this->hoTen = "";
    this->lop = "";
    this->ngaySinh = "";
}

// Hàm nhập (định nghĩa đúng kiểu friend function)
void nhap(SinhVien &sv) {
    cout << "Nhap ma sinh vien: ";
    getline(cin, sv.maSv);
    cout << "Nhap ho ten: ";
    getline(cin, sv.hoTen);
    cout << "Nhap ten lop: ";
    getline(cin, sv.lop);
    cout << "Nhap ngay thang nam sinh: ";
    getline(cin, sv.ngaySinh);
    cout << "Nhap gpa: ";
    cin >> sv.gpa;
    cin.ignore(); // Tránh lỗi khi dùng getline sau cin
}

// Hàm in (định nghĩa đúng kiểu friend function)
void in(SinhVien sv) {
    cout << sv.maSv << " " << sv.hoTen << " " << sv.lop << " "
         << sv.ngaySinh << " " << fixed << setprecision(2) << sv.gpa << endl;
}

// Hàm chuẩn hóa ngày sinh về định dạng dd/mm/yyyy
void SinhVien::chuanHoaNgaySinh() {
    if (ngaySinh[2] != '/') ngaySinh = '0' + ngaySinh; // Nếu ngày chỉ có 1 chữ số, thêm '0'
    if (ngaySinh[5] != '/') ngaySinh.insert(3, "0");  // Nếu tháng chỉ có 1 chữ số, thêm '0'
}

5/3/2005
05/03/2005
25/03
int main() {
    SinhVien a;  // Sửa lỗi khai báo đối tượng
    nhap(a);     // Gọi hàm nhập
    a.chuanHoaNgaySinh();
    in(a);       // Gọi hàm in
    
    return 0;
}
