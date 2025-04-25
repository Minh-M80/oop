#include<bits/stdc++.h>
#include<iostream>

using namespace std;

class TaiKhoan{
    private:
    string hoTen;
    int soTien;
    public:
    void xuat();
    TaiKhoan();
    TaiKhoan(string hoTen,int soTien);
    TaiKhoan(int soTien);
    ~TaiKhoan();
};

void TaiKhoan::xuat(){
    cout<<this->hoTen<<"\t";
    cout<<this->soTien<<"\n";
}

TaiKhoan::TaiKhoan(){
    cout<<"Khoi tao khong tham so\n";
    hoTen="";
    soTien=0;
}
TaiKhoan::TaiKhoan(string hoTen,int soTien){
    cout<<"Khoi tao co tham so\n";
    this->hoTen=hoTen;
    this->soTien=soTien;
}


TaiKhoan::TaiKhoan(int soTien){
    cout<<"Khoi tao co 1 tham so\n";
    this->soTien=soTien;
    hoTen="Nguyen";
}

//destructor
// k đc truyền tham số vào hàm hủy
TaiKhoan::~TaiKhoan(){
    cout<<"Huy doi tuong"<<endl;
    hoTen="";
    soTien=0;
}



int main(){
    // TaiKhoan t1,t2,t3;
    TaiKhoan t1(100),t2(200),t3(300);
    cout<<"hoTen\tSoTien"<<endl;
    t1.xuat();
    t2.xuat();
    t3.xuat();
}