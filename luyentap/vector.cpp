#include<bits/stdc++.h>
#include<iostream>

using namespace std;

//khai báo
// vector<data_type> vector_name;

// size() : Trả về số lượng phần tử trong vector. Độ phức tạp O(1)

// length() : Trả về số lượng phần tử trong vector. Độ phức tạp O(1)

// push_back() : Thêm phần tử vào cuối vector. Độ phức tạp O(1)

// pop_back() : Xóa phần tử cuối cùng trong vector. Độ phức tạp O(1)

// Để duyệt vector bạn có thể duyệt thông qua chỉ số, dùng ranged-base for loop.
// int main(){
//      //Khai báo vector rỗng
//      vector<int> v1;
//      //Khai báo vector với các phần tử
//      vector<int> v2 = {1, 2, 3, 4, 5};
//      //Khai báo vector có sẵn n phần tử
//      int n = 20;
//      vector<int> v3(n);
//      //Khai báo vector có sẵn n phần tử có cùng giá trị val
//      int val = 0;
//      vector<int> v4(n, val);
//      return 0;
// }

int main(){
    vector<int> v;
    v.push_back(1); // {1}
    v.push_back(2); // {1, 2}
    v.push_back(3); // {1, 2, 3}
    v.push_back(4); // {1, 2, 3, 4}
    cout << "Kich thuoc vector : " << v.size() << endl; // v.length()
    cout << "Duyet vector bang chi so : \n";
    for(int i = 0; i < v.size(); i++){
        cout << v[i] << ' ';
    }  
    cout << "\nDuyet vector bang ranged-base for loop :\n";
    for(int x : v){
        cout << x << ' ';
    }
    return 0;
}