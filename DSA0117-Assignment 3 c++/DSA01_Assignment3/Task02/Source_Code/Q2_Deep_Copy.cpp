#include <iostream>
#include <string>
using namespace std;
class Prescription {
    int n;
    string* medicines;
public:
    explicit Prescription(int count):n(count),medicines(new string[count>0?count:0]){}
    Prescription(const Prescription& o):n(o.n),medicines(new string[o.n>0?o.n:0]) {
        for(int i=0;i<n;++i) medicines[i]=o.medicines[i];
        cout << "Copy constructor called\n";
    }
    Prescription& operator=(const Prescription& o) {
        if(this!=&o) {
            string* fresh=new string[o.n>0?o.n:0];
            for(int i=0;i<o.n;++i) fresh[i]=o.medicines[i];
            delete[] medicines; medicines=fresh; n=o.n;
        }
        return *this;
    }
    ~Prescription(){delete[] medicines;}
    void set(int i,const string& m){if(i>=0&&i<n)medicines[i]=m;}
    string get(int i)const{return (i>=0&&i<n)?medicines[i]:"";}
};
int main(){
    Prescription p(2); p.set(0,"Paracetamol"); p.set(1,"ORS");
    Prescription q=p; q.set(1,"Cetirizine");
    Prescription r(1); r=p; p.set(0,"Ibuprofen");
    cout<<p.get(0)<<' '<<p.get(1)<<" | "<<q.get(0)<<' '<<q.get(1)
        <<" | "<<r.get(0)<<' '<<r.get(1)<<'\n';
    r=r; cout<<"Self-assignment completed safely\n";
}
