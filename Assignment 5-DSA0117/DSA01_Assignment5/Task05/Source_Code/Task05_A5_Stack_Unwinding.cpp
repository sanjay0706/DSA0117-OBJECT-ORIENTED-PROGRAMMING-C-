#include <iostream>
#include <string>
using namespace std;
struct Guard{string n;Guard(string s):n(s){}~Guard(){cout<<'~'<<n<<' ';}};
void f(){Guard g("f");throw 42;}
int main(){try{Guard m("main");f();cout<<"not printed ";}catch(int x){cout<<"caught "<<x;}cout<<'\n';}
