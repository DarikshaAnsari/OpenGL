#include<bits/stdc++.h>
using namespace std;

class Animal{
    public:
    virtual void speak(){
        cout<<"M janwar hu"<<endl;
    }
};
class Dog : public Animal{
     public:
     void speak(){
        cout<<"M kutta hu"<<endl;
     }
};
class Complex{
    private:
    int real;
    int imag;
    public:
    Complex(int real,int imag){
        this->real=real;
        this->imag=imag;
    }
    Complex operator+(Complex const& obj){
        Complex ans(0,0);
        ans.real=real+obj.real;
        ans.imag=imag+obj.imag;
        return ans;
    }
    void print() { cout << real << " + i" << imag << '\n'; }
};
int main(){
    Complex a(4,5), b(4,5);
    Complex c=a+b;
    c.print();
    return 0;
}