#include <cmath>
#include <iostream>
#include <stdexcept>
using namespace std;
class Complex {
    double re,im;
public:
    Complex():re(0),im(0){}
    Complex(double r):re(r),im(0){}
    Complex(double r,double i):re(r),im(i){}
    Complex operator+(const Complex& z)const{return Complex(re+z.re,im+z.im);}
    Complex operator-(const Complex& z)const{return Complex(re-z.re,im-z.im);}
    Complex operator*(const Complex& z)const{return Complex(re*z.re-im*z.im,re*z.im+im*z.re);}
    Complex operator/(const Complex& z)const{
        double d=z.re*z.re+z.im*z.im;
        if(d==0.0)throw domain_error("Division by zero impedance");
        return Complex((re*z.re+im*z.im)/d,(im*z.re-re*z.im)/d);
    }
    bool operator==(const Complex& z)const{return fabs(re-z.re)<1e-9&&fabs(im-z.im)<1e-9;}
    double magnitude()const{return sqrt(re*re+im*im);}
    friend ostream& operator<<(ostream& out,const Complex& z){out<<z.re;if(z.im>=0)out<<" + j"<<z.im;else out<<" - j"<<-z.im;return out;}
};
int main(){
    try{
        Complex r(10,0),l(0,5),c(0,-2),series=r+l+c;
        cout<<"Series impedance: "<<series<<"\nSeries magnitude: "<<series.magnitude()<<'\n';
        Complex z1(10,5),z2(20,-5),parallel=(z1*z2)/(z1+z2);
        cout<<"Parallel impedance: "<<parallel<<"\nParallel magnitude: "<<parallel.magnitude()<<'\n';
        Complex zero;cout<<(z1/zero)<<'\n';
    }catch(const domain_error& e){cout<<"Safe error handling: "<<e.what()<<'\n';}
}
