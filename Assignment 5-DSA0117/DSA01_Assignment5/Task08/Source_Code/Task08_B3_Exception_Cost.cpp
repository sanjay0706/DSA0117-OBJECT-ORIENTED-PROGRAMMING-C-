#include <chrono>
#include <iostream>
#include <stdexcept>
#include <vector>
using namespace std;using C=chrono::steady_clock;
bool valid(double x){return x>=0;}void check(double x){if(x<0)throw invalid_argument("negative");}
int main(){const int n=1000000;for(int pct:{0,1,50}){vector<double>v(n,10);for(int i=0;i<n*pct/100;++i)v[i]=-1;long aCount=0,bCount=0;auto a=C::now();for(double x:v)if(valid(x))++aCount;auto b=C::now();for(double x:v)try{check(x);++bCount;}catch(const exception&){}auto d=C::now();cout<<pct<<"% invalid | return "<<chrono::duration<double>(b-a).count()<<" s | exception "<<chrono::duration<double>(d-b).count()<<" s | valid "<<aCount<<'/'<<bCount<<'\n';}}
