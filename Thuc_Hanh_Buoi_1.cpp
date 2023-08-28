#include<iostream>
using namespace std;

class Animal{
    private:
    int conNon;
    int conTT;
    int sua;
    public:
    Animal(int conNon,int conTT, int sua){
        this->conNon = conNon;
        this->conTT = conTT;
        this->sua = sua;
    }
    virtual void soLuong() = 0;
    virtual void soSua() = 0;
    virtual void keu() = 0;
    void update(){
        soLuong();
        soSua();
    };
    void getSL(){
        return conNon + conTT;
    }
    void getSua(){
        return sua;
    }
};

class Bo: public Animal{
    private:
    int conNon;
    int conTT;
    int sua=0;
    public:
    Bo(int conNon, int conTT, int sua): Animal(conNon, conTT, sua){};
    int soLuong(){
        conTT = (conTT + conNon) / 2;
        return conNon + conTT;
    }
    void themSaubaluot(){
        
    }
    int soSua(){
        return sua;
    }
};

int main(){
    
}