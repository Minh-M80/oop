#include<bits/stdc++.h>
#include<iostream>
using namespace std;
class MonHoc{
    private:
        int MaMH;
        string TenMH;
        float DTB;
        int SoTC;
        string TenLop;
    public:
        MonHoc();
        MonHoc(int MaMH,string TenMH,float DTB,int SoTC,string TenLop);
        ~MonHoc();
        void nhap();
        void xuat();
        int getSoTinChi(){
            return this->SoTC;
        }
        void setSoTinChi(int SoTC){
            this->SoTC=SoTC;
        }

};

MonHoc::MonHoc(){

}
MonHoc::MonHoc(int MaMH,string TenMH,float DTB,int SoTC,string TenLop){
    this->MaMH=MaMH;
    this->TenMH=TenMH;
    this->DTB=DTB;
    this->SoTC=SoTC;
    this->TenLop=TenLop;
}
MonHoc::~MonHoc(){
    MaMH=0;
    TenMH="";
    DTB=0;
    SoTC=0;
    TenLop="";
}
void MonHoc::nhap(){
    cout<<"Nhap Ma mh"<<endl;
    cin>>this->MaMH;
    cin.ignore();
    cout<<"Nhap ten MH"<<endl;
    getline(cin,this->TenMH);
    cout<<"Nhap dtb"<<endl;
    cin>>this->DTB;
    cout<<"Nhap so tin chi"<<endl;
    cin>>this->SoTC;
    cin.ignore();
    cout<<"Nhap ten lop"<<endl;
    getline(cin,this->TenLop);
}
void MonHoc::xuat(){
    cout<<"Ma MH:"<<this->MaMH<<endl;
    cout<<"Ten MH:"<<this->TenMH<<endl;
    cout<<"ĐTB:"<<this->DTB<<endl;
    cout<<"So TC"<<this->SoTC<<endl;
    cout<<"Ten lop"<<this->TenLop<<endl;
}

int main(){
    int n;
    do
    {
        cout<<"Nhap so doi tuong"<<endl;
        cin>>n;
    } while (n<=0);
    MonHoc a[n];
    //goi phuong thuc nhap cua tung doi tuong
    for (int  i = 0; i < n; i++)
    {
       cout<<"Nhap do tuong thu "<<i+1  <<endl;
       a[i].nhap();
    }
    cout<<endl;
    for (int  i = 0; i < n; i++)
    {
       cout<<"Xuat do tuong thu "<<i+1  <<endl;
       a[i].xuat();
    }

}