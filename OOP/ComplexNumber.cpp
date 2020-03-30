#include <iostream>
using namespace std;

class ComplexNumbers {
    private:
    int real,imaginary;
    public:
    ComplexNumbers(int real,int imaginary){
        this->real=real;
        this->imaginary=imaginary;
    }
    void plus(ComplexNumbers const &c2){
        this->real+=c2.real;
        this->imaginary+=c2.imaginary;
    }
    void print(){
        cout<<this->real<<" + i"<<this->imaginary;
    }
    void multiply(ComplexNumbers const &c2){
        int x=this->real;
        int y=this->imaginary;
        int a=c2.real;
        int b=c2.imaginary;
        this->real=(a*x)-(y*b);
        this->imaginary=(x*b)+(a*y);
    }
    
};

int main() {
    int real1, imaginary1, real2, imaginary2;
    
    cin >> real1 >> imaginary1;
    cin >> real2 >> imaginary2;
    
    ComplexNumbers c1(real1, imaginary1);
    ComplexNumbers c2(real2, imaginary2);
    
    int choice;
    cin >> choice;
    
    if(choice == 1) {
        c1.plus(c2);
        c1.print();
    }
    else if(choice == 2) {
        c1.multiply(c2);
        c1.print();
    }
    else {
        return 0;
    }   
}