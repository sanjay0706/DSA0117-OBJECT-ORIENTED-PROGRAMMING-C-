#include <iostream>
#include <memory>
using namespace std;
class Bill{protected:string patient;public:Bill(string p):patient(p){}virtual ~Bill()=default;virtual double total()const=0;virtual string type()const{return "Bill";}void print()const{cout<<type()<<' '<<patient<<": "<<total()<<'\n';}};
class OutPatient:public Bill{double c,t;public:OutPatient(string p,double a,double b):Bill(p),c(a),t(b){}double total()const override{return c+t;}string type()const override{return "OP";}};
class InPatient:public Bill{int days;double rate,surgery;public:InPatient(string p,int d,double r,double s):Bill(p),days(d),rate(r),surgery(s){}double total()const override{return days*rate+surgery;}string type()const override{return "IP";}};
int main(){unique_ptr<Bill>b[]={make_unique<OutPatient>("Ravi",500,1200),make_unique<InPatient>("Meena",3,2500,40000)};double s=0;for(auto&x:b){x->print();s+=x->total();}cout<<"Total "<<s<<'\n';}
