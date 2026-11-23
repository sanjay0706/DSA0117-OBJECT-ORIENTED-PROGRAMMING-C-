#include <iostream>
#include <memory>
#include <vector>
using namespace std;
class Bill{public:virtual double total()const=0;virtual ~Bill()=default;};
class OP:public Bill{double amount;public:OP(double x):amount(x){}double total()const override{return amount;}};
class Payer{public:virtual double amountCovered(const Bill&)const=0;virtual const char*name()const=0;virtual ~Payer()=default;};
class SelfPay:public Payer{public:double amountCovered(const Bill&b)const override{return b.total();}const char*name()const override{return "SelfPay";}};
class Insurance:public Payer{double limit,copay;public:Insurance(double l,double c):limit(l),copay(c){}double amountCovered(const Bill&b)const override{return (b.total()<limit?b.total():limit)*(1-copay/100);}const char*name()const override{return "Insurance";}};
class Government:public Payer{double package;public:Government(double p):package(p){}double amountCovered(const Bill&)const override{return package;}const char*name()const override{return "Government";}};
class Corporate:public Payer{double percent;public:Corporate(double p):percent(p){}double amountCovered(const Bill&b)const override{return b.total()*percent/100;}const char*name()const override{return "Corporate";}};
int main(){OP b(50000);vector<unique_ptr<Payer>>p;p.push_back(make_unique<SelfPay>());p.push_back(make_unique<Insurance>(40000,10));p.push_back(make_unique<Government>(35000));p.push_back(make_unique<Corporate>(80));for(auto&x:p)cout<<x->name()<<" covers "<<x->amountCovered(b)<<'\n';}
