#include<bits/stdc++.h>
#include<iostream>

using namespace std;
//cout:ostream
//cin: istream

class SinhVien(){
    private:
    string id,ten,ns;
    double gpa;
    public:
    SinhVien();
    friend istream& operator >> (istream &in,SinhVien& a);
    friend ostream& operator << (ostream &out,SinhVien a);
}

istream& operator >> (istream &in,SinhVien& a){
    cout<<"Nhap id:";
    in >> a.id;
    cout<<"Nhap ten:";in.ignore();
    getline(in,a.ten);
    in>>
}


int main(){
    SinhVien x;
    
}