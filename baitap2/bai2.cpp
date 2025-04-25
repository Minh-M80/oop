#include<bits/stdc++.h>
#include<iostream>
// 3
// Nguyen Manh Son
// Cong nghe phan mem
// Vu Hoai Nam
// Khoa hoc may tinh
// Dang Minh Tuan
// An toan thong tin
using namespace std;

class NGUOI{
    private:
    string maGV,hoTen;
    static int counter;
    public:
    NGUOI();
    NGUOI(string maGV,string hoTen);
    ~NGUOI();
    void nhap();
    void xuat();
    string getTen();
    string getMaGV();

};
int NGUOI::counter=11;
NGUOI::NGUOI(){};
NGUOI::NGUOI(string maGV,string hoTen){
    this->maGV=maGV;
    this->hoTen=hoTen;
};
NGUOI::~NGUOI(){
    maGV="";
    hoTen="";
};
void NGUOI::nhap(){
    
    getline(cin,this->hoTen);
    this->maGV="GV"+string(2-to_string(++counter).length(),'0')+to_string(counter);
}
void NGUOI::xuat(){
    cout<<this->maGV<<" "<<this->hoTen;
}
string NGUOI::getTen(){
    stringstream ss(hoTen);// vu minh thanh
    string word,last;
    while (ss>>word)
    {
       last=word;
    }
    return last;
}
string NGUOI::getMaGV(){
    return maGV;
}
class GIANGVIEN:public NGUOI{
    private:
    string boMon;
    public:
    GIANGVIEN();
    GIANGVIEN(string maGV,string hoTen,string boMon);
    ~GIANGVIEN();
    void nhap();
    void xuat();
    string getBoMon();
    string vietTat(string);
};
string GIANGVIEN::vietTat(string s){
    stringstream ss(s);
    string word,res="";
    while(ss>>word){
        res +=toupper(word[0]);
    }
    return res;
}
GIANGVIEN::GIANGVIEN(){
}
GIANGVIEN::GIANGVIEN(string maGV,string hoTen,string boMon):NGUOI( maGV, hoTen){
    this->boMon=boMon;
};
void GIANGVIEN::nhap(){
    NGUOI::nhap();
    getline(cin,boMon);
    this->boMon=vietTat(boMon);
}
void GIANGVIEN::xuat(){
    NGUOI::xuat();
    cout<<" "<<this->boMon<<endl;
}
GIANGVIEN::~GIANGVIEN() {}  // Thêm dòng này để tránh lỗi

string GIANGVIEN::getBoMon(){
    return boMon;
}
bool cmp(GIANGVIEN &a,GIANGVIEN &b){
    if(a.getTen() !=b.getTen()){
        return a.getTen()<b.getTen();

    }
    return a.getMaGV()<b.getMaGV();
}
int main(){
    int n;
    cin>>n;
    cin.ignore();
    GIANGVIEN a[n];
    for (int i = 0; i < n; i++)
    {
        a[i].nhap();
    }
    sort(a,a+n,cmp);
    for(int i=0;i<n;i++){
        a[i].xuat();
    }
    return 0;
    
}

