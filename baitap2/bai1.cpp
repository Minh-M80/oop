#include<bits/stdc++.h>
#include<iostream>

using namespace std;

class NGUOI{
    private:
    string msv,hoTen;
    public:
    NGUOI();
    NGUOI(string msv,string hoTen);
    ~NGUOI();
    void nhap();
    void xuat();
    string getMaSV()  {
        return msv;
    }

};
void NGUOI::nhap(){
    getline(cin,this->msv);
    getline(cin,this->hoTen);
}
void NGUOI::xuat(){
    cout<<this->msv<<" "<<this->hoTen;
}
NGUOI::NGUOI(){};
NGUOI::~NGUOI(){};
NGUOI::NGUOI(string msv,string hoTen){
    this->msv=msv;
    this->hoTen=hoTen;
}
class SINHVIEN:public NGUOI{
    private:
    string lop,email;
    public:
    SINHVIEN();
    SINHVIEN(string msv,string hoTen,string lop,string email);
	
    ~SINHVIEN();
    void nhap();
    void xuat();
};

SINHVIEN::SINHVIEN(){};
SINHVIEN::SINHVIEN(string msv,string hoTen,string lop,string email):NGUOI( msv, hoTen){
  
    this->lop=lop;
    this->email=email;
}

SINHVIEN::~SINHVIEN(){};
 void SINHVIEN::nhap(){
    NGUOI::nhap();
    getline(cin,this->lop);
    getline(cin,this->email);
}
void SINHVIEN::xuat(){
    NGUOI::xuat();
    cout<<" "<<this->lop<<" "<<this->email<<endl;
}


int main() {
    int n;
    
    do
    {
        cin >> n;
    } while (n>100 || n<=0);
    cin.ignore(); 
    SINHVIEN a[n];
    for (int  i = 0; i < n; i++)
    {
        a[i].nhap();
    }
    int Q;
    cin >> Q;
    cin.ignore();

    vector<string> queries(Q);
    for (int i = 0; i < Q; i++) {
        getline(cin, queries[i]);
    }
    for ( string query : queries) {
        string keyword;
        if (query == "Ke Toan") keyword = "DCKT";
        else if (query == "Cong nghe thong tin") keyword = "DCCN";
        else if (query == "An toan thong tin") keyword = "DCAT";
        else if (query == "Vien thong") keyword = "DCVT";
        else if (query == "Dien tu") keyword = "DCDT";

        if (!keyword.empty()) { //  Chỉ in nếu có ngành hợp lệ
            cout << "DANH SACH SINH VIEN NGANH " << query << ":" << endl;
            for (SINHVIEN sv : a) {
                if (sv.getMaSV().find(keyword) != string::npos) {
                    sv.xuat();
                }
            }
        }
    }
  
    return 0;
}
