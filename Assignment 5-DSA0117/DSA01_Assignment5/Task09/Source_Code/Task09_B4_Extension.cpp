#include <iostream>
#include <memory>
#include <vector>
using namespace std;
class Bill{public:virtual double total()const=0;virtual const char*type()const=0;virtual ~Bill()=default;};
class OP:public Bill{double c,t;public:OP(double a,double b):c(a),t(b){}double total()const override{return c+t;}const char*type()const override{return "OP";}};
class Maternity:public Bill{double package,extras;public:Maternity(double p,double e):package(p),extras(e){}double total()const override{return package+extras;}const char*type()const override{return "Maternity";}};
class Payer{public:virtual double cover(double)const=0;virtual const char*name()const=0;virtual ~Payer()=default;};
class Corporate:public Payer{double pct;public:Corporate(double p):pct(p){}double cover(double x)const override{return x*pct/100;}const char*name()const override{return "Corporate";}};
class SelfPay:public Payer{public:double cover(double x)const override{return x;}const char*name()const override{return "SelfPay";}};
int main(){vector<unique_ptr<Bill>>b;b.push_back(make_unique<OP>(500,1200));b.push_back(make_unique<Maternity>(60000,5000));vector<unique_ptr<Payer>>p;p.push_back(make_unique<SelfPay>());p.push_back(make_unique<Corporate>(80));for(auto&x:b)for(auto&y:p)cout<<x->type()<<'/'<<y->name()<<" = "<<y->cover(x->total())<<'\n';}
