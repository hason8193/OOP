#include<iostream>

using namespace std;

class IntArr{
private:
    int count;
    int* values;
public:
    IntArr(){
        count = 0;
        values = NULL;
    }
    IntArr(int size){
        count = size;
        values = new int[count];
        for(int i = 0; i < count; i++){
            values[i] = 0;
        }
    }
    IntArr(int size, int init){
        count = size;
        values = new int[count];
        for(int i = 0; i < count; i++){
            values[i] = init;
        }
    }

    friend istream& operator >>(istream& is, IntArr& IA){
        is >> IA.count;
        IA.values = new int[IA.count];
        for(int i = 0; i < IA.count; i++)
            is >> IA.values[i];
        return is;
    }
    friend ostream& operator << (ostream& os, const IntArr& IA){
        for(int i = 0; i < IA.count; i++){
            os << IA.values[i] << " ";
        }
        os << endl;
        return os;
    }
    IntArr concat(const IntArr& other){
        IntArr IA;
        IA.count = this->count + other.count;
        IA.values = new int[IA.count];
        for(int i = 0; i < this->count; i++)
            IA.values[i] = this->values[i];
        for(int j = this->count; j < IA.count; j++)
            IA.values[j] = other.values[j - this->count];
        return IA;
    }
    void push(int x){
        IntArr temp(1,x);
        *this = this->concat(temp);
    }
};

int main(){
    IntArr l1; // tạo mảng không chứa bất kì phần tử nào
    cout << l1;
    IntArr l2(3, 2); /* tạo một mảng với 3 phần tử, tất cả phần tử đều có giá trị
    là 2 */
    cout << "l2: " << l2;
    IntArr l3(2);//tạo một mảng với 2 phần tử, tất cả phần tử đều có giá trị là 0
    cout << "l3: " << l3;
    IntArr l4 = l2.concat(l3); /* tạo ra một IntArr mới có nội dung là kết quả
    của việc nối các phần tử l3 vào cuối các phần tử của l2 theo thứ tự */
    cout << "l4: " << l4;
    l2.push(3); // thêm số 3 vào cuối danh sách trong đối tượng l2
    cout << l2;
    cin >> l2; /* Xoá các giá trị hiện có trong l2 và cho phép người dùng nhập
    số lượng phần tử mới và giá trị các phần tử mới vào l2 (cần xoá các vùng nhớ
    không sử dụng nếu có) */
    cout << l2; // in ra các số nguyên có trong danh sách
    /* Khi vượt quá phạm vi sử dụng cần huỷ tất cả các vùng nhớ được cấp phát cho
    các values của IntArr */
    return 0;
}