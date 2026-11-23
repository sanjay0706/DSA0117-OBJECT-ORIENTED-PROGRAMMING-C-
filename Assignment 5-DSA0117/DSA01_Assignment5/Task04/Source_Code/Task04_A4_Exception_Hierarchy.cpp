#include <iostream>
#include <stdexcept>
using namespace std;
class BillingError:public runtime_error{public:using runtime_error::runtime_error;};
class ClaimError:public BillingError{public:using BillingError::BillingError;};
double validate(double x){if(x<0)throw BillingError("negative charge");if(x>100000)throw ClaimError("claim exceeds limit");return x;}
int main(){for(double x:{2500.0,-10.0,120000.0})try{cout<<"Approved "<<validate(x)<<'\n';}catch(const BillingError&e){cout<<"Billing error: "<<e.what()<<'\n';}}
