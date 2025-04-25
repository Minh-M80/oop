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
        Fraction result(num, den);// tạo ra một đối tượng mới
        result.simplify();
        return result;
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
    return 0;
}
