#include <iostream>

#include <bits/stdc++.h>
using namespace std;

class DATE {
private:
    int day, month, year;
public:
    // Hàm khởi tạo mặc định
    DATE() : day(1), month(1), year(2000) {}

    // Hàm nhập ngày tháng năm
    void input() {
        cout << "Nhap ngay (dd mm yyyy): ";
        cin >> day >> month >> year;
    }

    // Hàm xuất ngày tháng năm
    void output() const {
        cout << day << "/" << month << "/" << year << endl;
    }
};


class CANBO : public DATE {
    private:
        string maCanBo;
        string tenCanBo;
        double luongCoBan;
        static double tienPhuCapChucVu; // Thuộc tính tĩnh
    
    public:
        // Hàm khởi tạo mặc định
        CANBO() : maCanBo(""), tenCanBo(""), luongCoBan(0) {}
    
        // Hàm nhập thông tin cán bộ
        void input() {
            cout << "Nhap ma can bo: ";
            cin >> maCanBo;
            cout << "Nhap ten can bo: ";
            cin.ignore();
            getline(cin, tenCanBo);
            cout << "Nhap luong co ban: ";
            cin >> luongCoBan;
            DATE::input(); // Nhập ngày tháng năm sinh kế thừa từ lớp DATE
        }
    
        // Hàm xuất thông tin cán bộ
        void output() const {
            cout << "Ma can bo: " << maCanBo << endl;
            cout << "Ten can bo: " << tenCanBo << endl;
            cout << "Luong co ban: " << luongCoBan << endl;
            cout << "Ngay sinh: ";
            DATE::output(); // Xuất ngày tháng năm sinh kế thừa từ lớp DATE
        }
    
        // Hàm tính lương (lương cơ bản + phụ cấp chức vụ)
        double tinhLuong() const {
            return luongCoBan + tienPhuCapChucVu;
        }
    
        // Hàm thiết lập tiền phụ cấp chức vụ
        static void setTienPhuCapChucVu(double phuCap) {
            tienPhuCapChucVu = phuCap;
        }
    
        // Hàm lấy tiền phụ cấp chức vụ
        static double getTienPhuCapChucVu() {
            return tienPhuCapChucVu;
        }
    
        // Hàm lấy tên cán bộ
        string getTenCanBo() const {
            return tenCanBo;
        }
    
        // Hàm lấy lương cơ bản
        double getLuongCoBan() const {
            return luongCoBan;
        }
    };
    
    // Khởi tạo thuộc tính tĩnh
    double CANBO::tienPhuCapChucVu = 0;
    
    int main() {
        int n;
        cout << "Nhap so luong can bo: ";
        cin >> n;
        cin.ignore(); // Để bỏ qua ký tự newline còn lại trong buffer
    
        vector<CANBO> canBoList(n);
        
        // Nhập thông tin cho n cán bộ
        for (int i = 0; i < n; ++i) {
            cout << "\nNhap thong tin can bo " << i + 1 << ":\n";
            canBoList[i].input();
        }
    
        // Nhập thông tin phụ cấp chức vụ cho tất cả cán bộ
        double phuCap;
        cout << "Nhap tien phu cap chuc vu: ";
        cin >> phuCap;
        CANBO::setTienPhuCapChucVu(phuCap);
    
        // In ra thông tin của tất cả các cán bộ
        cout << "\nThong tin cua tat ca cac can bo:\n";
        for (const auto& canBo : canBoList) {
            canBo.output();
            cout << "Luong: " << canBo.tinhLuong() << endl;
        }
    
        // Tìm và in ra tên các cán bộ có lương thấp nhất
        double minLuong = canBoList[0].tinhLuong();
        vector<string> lowSalaryNames;
    
        for (const auto& canBo : canBoList) {
            double luong = canBo.tinhLuong();
            if (luong < minLuong) {
                minLuong = luong;
                lowSalaryNames.clear();
                lowSalaryNames.push_back(canBo.getTenCanBo());
            } else if (luong == minLuong) {
                lowSalaryNames.push_back(canBo.getTenCanBo());
            }
        }
    
        cout << "\nCac can bo co luong thap nhat:\n";
        for (const string& name : lowSalaryNames) {
            cout << name << endl;
        }
    
        return 0;
    }
    