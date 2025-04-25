#include <iostream>
#include <algorithm>
using namespace std;

class Fraction {
private:
    int numerator, denominator;

public:
    Fraction(int num = 0, int den = 1) {
        numerator = num;
        denominator = (den == 0) ? 1 : den;
    }

    // Hàm rút gọn phân số
    void simplify() {
        int gcd = __gcd(numerator, denominator);
        numerator /= gcd;
        denominator /= gcd;
    }

    // Nạp chồng toán tử +
    Fraction operator+(const Fraction& other) {
        int num = numerator * other.denominator + other.numerator * denominator;
        int den = denominator * other.denominator;
        Fraction result(num, den);
        result.simplify();
        return result;
    }

    // Nạp chồng toán tử < để so sánh hai phân số
    bool operator<(const Fraction& other)  {
        return numerator * other.denominator < other.numerator * denominator;
    }

    // Nạp chồng toán tử > để so sánh hai phân số
    bool operator>(const Fraction& other)  {
        return numerator * other.denominator > other.numerator * denominator;
    }

    // Hàm xuất phân số
    void display() {
        cout << numerator << "/" << denominator << endl;
    }
};

int main() {
    Fraction f1(1, 2), f2(1, 3);
    Fraction sum = f1 + f2;
    cout << "Tong hai phan so: ";
    sum.display();

    // Kiểm tra toán tử so sánh
    if (f1 < f2)
        cout << "f1 nho hon f2" << endl;
    else
        cout << "f1 khong nho hon f2" << endl;

    return 0;
}
