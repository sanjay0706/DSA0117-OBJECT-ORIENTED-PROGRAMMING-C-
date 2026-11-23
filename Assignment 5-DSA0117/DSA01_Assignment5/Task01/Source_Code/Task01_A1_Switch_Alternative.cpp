#include <iostream>
using namespace std;
enum class Kind{OP,IP,DayCare,Emergency};
struct Bill{Kind k;double a,b,c;int n;};
double total(const Bill&x){switch(x.k){case Kind::OP:return x.a+x.b;case Kind::IP:return x.n*x.a+x.b+x.c;case Kind::DayCare:return x.a;case Kind::Emergency:return x.a+x.b*x.n;}return 0;}
int main(){Bill a[]={{Kind::OP,500,1200,0,0},{Kind::IP,2500,40000,2500,3},{Kind::DayCare,18000,0,0,0},{Kind::Emergency,1000,750,0,2}};double s=0;for(auto&b:a){cout<<total(b)<<'\n';s+=total(b);}cout<<"Day total: "<<s<<'\n';}
