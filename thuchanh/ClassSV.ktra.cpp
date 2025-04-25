#include<bits/stdc++.h>
#include<iostream>
using namespace std;





class SinhVien{
    private:
       string MaSV,
        HoTen,
        NgaySinh;
        double gpa;

    public:
    SinhVien();
    SinhVien(string MaSV, string HoTen, string NgaySinh, double gpa);
    ~SinhVien();
    // void nhap();
    // void xuat();
    double getgpa(){
        return this->gpa;
    }
    friend void nhapthongtin(SinhVien &);
    friend void inthongtin(SinhVien);

    friend bool cmp(SinhVien a, SinhVien b);
    friend istream& operator >> (istream &in,SinhVien &a);
    friend ostream& operator << (istream &os,SinhVien a);
    friend bool operator < (const SinhVien &a, const SinhVien &b){
        return a.gpa < b.gpa;
    }
    
};

SinhVien::SinhVien(){
}

SinhVien::SinhVien(string MaSV, string HoTen, string NgaySinh, double gpa){
    this->MaSV = MaSV;
    this->HoTen = HoTen;
    this->NgaySinh = NgaySinh;
    this->gpa = gpa;
}

SinhVien::~SinhVien(){
    MaSV = "";
    HoTen = "";
    NgaySinh = "";
    gpa = 0;
}

// void SinhVien::nhap(){
//     cout << "Nhap MaSV: ";
//     cin.ignore();
//     getline(cin,this->MaSV);
    
//     cout << "Nhap HoTen: ";
    
//     getline(cin, this->HoTen);
//     cout << "Nhap NgaySinh: ";
//     cin.ignore();
//     getline(cin, this->NgaySinh);
//     cout << "Nhap GPA: ";
//     cin >> this->gpa;
// }

void nhapthongtin(SinhVien &a){
    cout << "Nhap MaSV: ";
    cin.ignore();
    getline(cin, a.MaSV);
    
    cout << "Nhap HoTen: ";
    
    getline(cin, a.HoTen);
    cout << "Nhap NgaySinh: ";
    cin.ignore();
    getline(cin, a.NgaySinh);
    cout << "Nhap GPA: ";
    cin >> a.gpa;
}
//void SinhVien::xuat(){
//    cout << "MaSV: " << this->MaSV << endl;
//    cout << "HoTen: " << this->HoTen << endl;
//    cout << "NgaySinh: " << this->NgaySinh << endl;
//    cout << "GPA: " << this->gpa << endl;
//}

void sapxeptangdantheogpa(int n,SinhVien *a){
    for (int i = 0; i < n-1; i++)
    {
        {
            for (int j = i+1; j < n; j++)
            {
                if (a[i].getgpa() < a[j].getgpa())
                {
                    SinhVien temp = a[i];
                    a[i] = a[j];
                    a[j] = temp;
                }
            }
            
        }
    }
}

bool cmp(SinhVien a, SinhVien b){
    return a.getgpa() > b.getgpa();
}
void inthongtin(SinhVien a){
    cout<<a.MaSV<<" "<<a.HoTen<<endl;
}











int main(){
    int n;
    do
    {
        cout<<"Nhap so sinh vien"<<endl;
        cin>>n;
    } while (n<=0);
    SinhVien a[n];
    //goi phuong thuc nhap cua tung doi tuong
    for (int  i = 0; i < n; i++)
    {
       cout<<"Nhap do tuong thu "<<i+1  <<endl;
    //    a[i].nhap();
    nhapthongtin(a[i]);
    }
    
    
    cout<<endl;
    // for (int  i = 0; i < n; i++)
    // {
    //    cout<<"Xuat do tuong thu "<<i+1  <<endl;
    //    a[i].xuat();
    // }
    // sapxeptangdantheogpa(n,a);

    
    // for (int  i = 0; i < n; i++)
    // {
    //    cout<<"Xuat do tuong thu "<<i+1  <<endl;
    //    a[i].xuat();
    // }
    for (int i = 0; i < n; i++)
    {
        inthongtin(a[i]);
    }
    sort(a,a+n,cmp);
    for (int i = 0; i < n; i++)
    {
        inthongtin(a[i]);
    }
    return 0;
}