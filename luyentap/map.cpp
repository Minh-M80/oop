#include <map>
#include<iostream>
using namespace std;
// map<key_data_type, value_data_type> map_name;
// insert() : Thêm phần tử vào trong map với độ phức tạp 
// size() : Trả về số phần tử trong map 
// clear() : Xóa toàn bộ phần tử trong map
// empty() : Kiểm tra vector rỗng

int main(){
    map<int, int> mp;
    mp.insert(make_pair(1, 2)); // ok
    mp.insert(make_pair(1, 5)); // not ok
    mp.insert(make_pair(2, 4)); // ok
    mp.insert(make_pair(2, 5)); // not ok
    mp.insert(make_pair(2, 1)); // not ok
    mp.insert(make_pair(3, 1)); // ok
    cout << mp.size() << endl; // 3
}