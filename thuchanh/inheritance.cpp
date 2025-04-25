#include<bits/stdc++.h>
using namespace std;


class Person{
    private:
    string name;
    string address;
    public:
    string getName(){
        return name;
    }
    string getAddress(){
        return address;
    }
    void setName(string name){
        this->name = name;
    }
    void setAddress(string address){
        this->address = address;
    }
};

class Student : public Person{
    private:
        float gpa;
    public:
        float getGpa(){
            
            return gpa;
        }

        void setGpa(float gpa){
            this->gpa = gpa;
        }
        
};

class GiaoVien :public Person {
    private:
        string khoa;
        float luong;
    public:
    void nhap();
    void xuat();
};


int main(){
    Student x;
    x.setName("Nguyen Duc Minh");
    x.setAddress("123 Thai Ha");
    x.setGpa(3.8);
    cout<<x.getName()<<" "<<x.getAddress()<<" "<<x.getGpa()<<endl;
    return 0;
}