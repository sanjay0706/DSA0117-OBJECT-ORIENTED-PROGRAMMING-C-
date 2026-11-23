#include <iostream>
#include <stdexcept>
using namespace std;
void validate(double x){if(x<0)throw invalid_argument("negative");if(x>1e6)throw out_of_range("too large");cout<<"ok ";}
void process(double x){try{validate(x);}catch(const out_of_range&e){cout<<"[log "<<e.what()<<"] ";throw;}}
int main(){for(double x:{100.0,-5.0,2e6})try{process(x);cout<<"done ";}catch(const exception&e){cout<<"caught "<<e.what()<<' ';}cout<<'\n';}
