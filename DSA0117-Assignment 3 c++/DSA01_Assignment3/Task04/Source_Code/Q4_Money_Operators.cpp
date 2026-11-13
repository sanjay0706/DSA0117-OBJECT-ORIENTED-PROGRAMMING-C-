#include <iomanip>
#include <iostream>
using namespace std;
class Money {
    long long paise;
public:
    Money(long long rupees=0,int p=0):paise(rupees*100+p){}
    Money operator+(const Money& other)const{Money result;result.paise=paise+other.paise;return result;}
    bool operator==(const Money& other)const{return paise==other.paise;}
    friend ostream& operator<<(ostream& out,const Money& m){
        long long p=m.paise<0?-m.paise:m.paise;
        if(m.paise<0)out<<"-Rs ";else out<<"Rs ";
        return out<<p/100<<'.'<<setw(2)<<setfill('0')<<p%100<<setfill(' ');
    }
};
int main(){
    Money a(120,75),b(79,25),c=a+b;
    cout<<"First amount: "<<a<<"\nSecond amount: "<<b<<"\nTotal amount: "<<c<<'\n';
    cout<<boolalpha<<"Is total Rs 200.00? "<<(c==Money(200))<<'\n';
    cout<<"Paise carry test: "<<Money(0,75)+Money(0,50)<<'\n';
}
