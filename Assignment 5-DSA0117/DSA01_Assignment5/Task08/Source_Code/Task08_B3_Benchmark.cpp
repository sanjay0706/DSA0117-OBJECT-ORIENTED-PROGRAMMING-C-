#include <chrono>
#include <iostream>
#include <memory>
#include <vector>
using namespace std;using C=chrono::steady_clock;
struct B{virtual double total()const=0;virtual ~B()=default;};struct OP:B{double a,b;OP(double x,double y):a(x),b(y){}double total()const override{return a+b;}};
struct R{int type;double a,b;};double sw(R x){return x.type?x.a*3:x.a+x.b;}
int main(){for(int n:{1000,1000000,10000000}){vector<unique_ptr<B>>v;vector<R>r;v.reserve(n);r.reserve(n);for(int i=0;i<n;++i){if(i%2){v.push_back(make_unique<OP>(2500,0));r.push_back({1,2500,0});}else{v.push_back(make_unique<OP>(500,1200));r.push_back({0,500,1200});}}volatile double sum=0;auto a=C::now();for(auto&x:v)sum+=x->total();auto b=C::now();for(auto&x:r)sum+=sw(x);auto d=C::now();cout<<n<<" bills | virtual "<<chrono::duration<double>(b-a).count()<<" s | switch "<<chrono::duration<double>(d-b).count()<<" s | checksum "<<sum<<'\n';}}
