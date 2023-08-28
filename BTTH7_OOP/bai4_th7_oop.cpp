#include<bits/stdc++.h>

using namespace std;

class Diem {
public:
    double x, y;
    Diem(double x=0, double y=0) {
        this->x = x;
        this->y = y;
    }
};

class Shape {
public:
    virtual ~Shape() {}
};

class Circle : public Shape {
public:
    Diem tam;
    double bk;
    Circle(Diem c, double r) : tam(c), bk(r) {}
    ~Circle() {}
};

class Ellipse : public Shape {
public:
    Diem tam;
    double bantruc_lon, bantruc_nho;
    Ellipse(Diem c, double lon, double nho) : tam(c), bantruc_lon(lon), bantruc_nho(nho) {}
    ~Ellipse() {}
};

int main() {
    int so_luong;
    vector<Shape*> shapes;
    cout << "Nhap so luong hinh can in: ";
    cin >> so_luong;
    for (int i = 0; i < so_luong; i++) {
        Diem tam;
        double bantruc_lon, bantruc_nho;
        char type;
        cout << "Nhap loai hinh (c: tron, e: ellipse) va tam(x,y) " << i+1 << ":";
        cin >> type >> tam.x >> tam.y;
        if (type == 'c') {
            double bk;
            cout << "Nhap ban kinh cua hinh " << i+1 <<":";
            cin >> bk;
            Circle* circle = new Circle(tam, bk);
            shapes.push_back(circle);
        } else {
            cout << "Nhap truc lon va truc nho cua hinh " << i+1 << ":";
            cin >> bantruc_lon >> bantruc_nho;
            Ellipse* ellipse = new Ellipse(tam, bantruc_lon, bantruc_nho);
            shapes.push_back(ellipse);
        }
    }
    for (int i = 0; i < shapes.size(); i++) {
        Shape* shape = shapes[i];
        cout << "Hinh " << i+1 << ": ";
        if (dynamic_cast<Circle*>(shape) != NULL) {
            Circle* circle = dynamic_cast<Circle*>(shape);
            cout << "Tron(tam = (" << circle->tam.x << ", " << circle->tam.y << "), Ban kinh = " << circle->bk << ")" << endl;
        } else {
            Ellipse* ellipse = dynamic_cast<Ellipse*>(shape);
            cout << "Ellipse(tam = (" << ellipse->tam.x << ", " << ellipse->tam.y << "), Ban truc lon = " << ellipse->bantruc_lon << ", Ban truc nho = " << ellipse->bantruc_nho << ")" << endl;
        }
    }
    for (int i = 0; i < shapes.size(); i++) {
        delete shapes[i];
    }
    return 0;
}

