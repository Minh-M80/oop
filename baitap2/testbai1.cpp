#include <iostream>
#include <vector>
#include <string>
using namespace std;

class NGUOI {
protected:
    string maSV;
    string hoTen;
public:
    NGUOI() {}
    NGUOI(string ma, string ten) : maSV(ma), hoTen(ten) {}
    virtual ~NGUOI() {}
    virtual void nhap() {
        getline(cin, maSV);
        getline(cin, hoTen);
    }
    virtual void xuat() const {
        cout << maSV << " " << hoTen;
    }
    string getMaSV() const {
        return maSV;
    }
};

class SINHVIEN : public NGUOI {
private:
    string lop;
    string email;
public:
    SINHVIEN() {}
    SINHVIEN(string ma, string ten, string l, string e) : NGUOI(ma, ten), lop(l), email(e) {}
    void nhap() override {
        NGUOI::nhap();
        cin >> lop >> email;
        cin.ignore();
    }
    void xuat() const override {
        cout << maSV << " " << hoTen << " " << lop << " " << email << endl;
    }
};

int main() {
    int n;
    cin >> n;
    cin.ignore();
    vector<SINHVIEN> dsSV(n);
    for (int i = 0; i < n; i++) {
        dsSV[i].nhap();
    }
    
    int Q;
    cin >> Q;
    cin.ignore();
    vector<string> queries(Q);
    for (int i = 0; i < Q; i++) {
        getline(cin, queries[i]);
    }
    
    for (const string& query : queries) {
        string keyword;
        if (query == "Ke Toan") keyword = "DCKT";
        else if (query == "Cong nghe thong tin") keyword = "DCCN";
        else if (query == "An toan thong tin") keyword = "DCAT";
        else if (query == "Vien thong") keyword = "DCVT";
        else if (query == "Dien tu") keyword = "DCDT";
        
        cout << "DANH SACH SINH VIEN NGANH " << query << ":" << endl;
        for (const auto& sv : dsSV) {
            if (sv.getMaSV().find(keyword) != string::npos) {
                sv.xuat();
            }
        }
    }
    
    return 0;
}
