#include<bits/stdc++.h>

using namespace std;
class SinhVien
{
private:
    string id,ten,ns;
    double gpa;
public:
   void xinchao(/* args */);
    void dihoc();
};

void SinhVien::xinchao(/* args */)
{
    cout<<"Hello\n";
}

void SinhVien::dihoc()
{
    cout<<"Di hoc\n";
}


int main(){
    SinhVien sv;
    sv.xinchao();
    sv.dihoc();
    return 0;
}