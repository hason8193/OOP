#include<iostream>
#include<vector>

using namespace std;
static int tongDS = 0, tongCN  = 0, tongTC = 0, idx = 0;
class Tuong{
    protected:
    int tien;
    int attack;
    int defend;
    public:
    Tuong(int tien){
        this->tien = tien;
    }
    virtual void tangToc() = 0;
    virtual void tangHe() = 0;
    virtual void skill() = 0;
    virtual void nhap(){
        cin >> attack >> defend;
    }
    void xuat(){
        cout << " - sat thuong gay ra: " << attack;
    }
};

class Jarvan: public Tuong{
    public:
    Jarvan(int tien): Tuong(tien){}
    void nhap(){
        Tuong::nhap();
        tongCN++;
        tongDS++;
    }
    void skill()override{
        attack = defend * 2;
    }
    void tangToc()override{
        if(tongCN >= 2){
            attack += 15;
            defend += 15;
        }
    }
    void tangHe()override{
        if(tongDS == 2){
            defend += 15;
        }
        else if(tongDS >= 3){
            defend += 30;
        }
    }
    void xuat(){
        cout << "Jarvan";
        Tuong::xuat();
    }
};

class Reksai: public Tuong{
    public:
    Reksai(int tien): Tuong(tien){}
    void skill()override{
        if(idx % 4 == 0){
            attack *= 2;
        }
    }
    void tangToc()override{
        if(tongTC == 2){
            attack += 30;
        }
    }
    void tangHe()override{
        if(tongDS == 2){
            defend += 15;
        }
        else if(tongDS == 2){
            defend += 30;
        }
    }
    void xuat(){
        cout << "Reksai";
        Tuong::xuat();
    }
};

class Sivir: public Tuong{
    public:
    Sivir(int tien): Tuong(tien){}
    void skill() override{
        attack *= 2;
    }
    void tangToc() override{
        if(tongCN == 2){
            attack += 15;
            defend += 15;
        }
    }
    void tangHe()override{
        attack = attack;
    }
    void xuat(){
        cout << "Sivir";
        Tuong::xuat();
    }
};

class Illaoi: public Tuong{
    public:
    Illaoi(int tien): Tuong(tien){}
    void skill() override{
        attack = (attack + defend) / 2;
    }
    void tangToc() override{
        if(tongTC == 2){
            attack += 30;
        }
    }
    void tangHe()override{
        if(tongDS == 2){
            defend += 15;
        }
        else if(tongDS == 2){
            defend += 30;
        }
    }
    void xuat(){
        cout << "Illaoi";
        Tuong::xuat();
    }
};

int main(){
    int n, luot,type;
    cin >> n >> luot;
    vector<Tuong*> tuong(n);
    for(int i = 0; i < n; i++){
        cin >> type;
        idx++;
        if(type == 1){
            tuong[i] = new Jarvan(1);
            tongCN++;
            tongDS++;
        }
        if(type == 2){
            tuong[i] = new Reksai(2);
            tongTC++;
            tongDS++;
            idx++;
        }
        if(type == 3){
            tuong[i] = new Sivir(4);
            tongCN++;
        }
        if(type == 2){
            tuong[i] = new Illaoi(1);
            tongTC++;
            tongDS++;
        }
        tuong[i]->nhap();
        tuong[i]->tangHe();
        tuong[i]->tangToc();
        tuong[i]->skill();
        
    }
    
}