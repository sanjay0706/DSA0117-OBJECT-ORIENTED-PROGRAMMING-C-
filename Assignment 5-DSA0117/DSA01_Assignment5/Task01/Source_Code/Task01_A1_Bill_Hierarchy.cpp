#include <iostream>
#include <memory>
#include <vector>
using namespace std;
class Bill{public: virtual double total()const=0; virtual const char* type()const=0; virtual ~Bill()=default;};
class OP:public Bill{double c,t;public:OP(double a,double b):c(a),t(b){} double total()const override{return c+t;}const char* type()const override{return "OP";}};
class IP:public Bill{int d;double r,s,m;public:IP(int x,double y,double z,double q):d(x),r(y),s(z),m(q){}double total()const override{return d*r+s+m;}const char* type()const override{return "IP";}};
class DayCare:public Bill{double p;public:DayCare(double x):p(x){}double total()const override{return p;}const char* type()const override{return "DayCare";}};
class Emergency:public Bill{double b,r;int h;public:Emergency(double x,double y,int z):b(x),r(y),h(z){}double total()const override{return b+r*h;}const char* type()const override{return "Emergency";}};
int main(){vector<unique_ptr<Bill>> v;v.push_back(make_unique<OP>(500,1200));v.push_back(make_unique<IP>(3,2500,40000,2500));v.push_back(make_unique<DayCare>(18000));v.push_back(make_unique<Emergency>(1000,750,2));double s=0;for(auto&b:v){cout<<b->type()<<": "<<b->total()<<'\n';s+=b->total();}cout<<"Day total: "<<s<<'\n';}
