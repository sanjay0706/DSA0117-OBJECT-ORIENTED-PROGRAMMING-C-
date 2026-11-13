#include <iostream>
#include <stdexcept>
#include <string>
using namespace std;
class Time {
    int seconds;
public:
    explicit Time(int s=0):seconds(s<0?0:s){}
    Time& operator++(){++seconds;return *this;}
    Time operator++(int){Time old=*this;++seconds;return old;}
    bool operator==(const Time& o)const{return seconds==o.seconds;}
    bool operator<(const Time& o)const{return seconds<o.seconds;}
    void display()const{int h=seconds/3600,m=(seconds%3600)/60,s=seconds%60;
        cout<<h<<':'<<(m<10?"0":"")<<m<<':'<<(s<10?"0":"")<<s;}
};
class Playlist {
    string tracks[3]={"Track One","Track Two","Track Three"};
public:
    string& operator[](int i){if(i<0||i>=3)throw out_of_range("Playlist index out of range");return tracks[i];}
    const string& operator[](int i)const{if(i<0||i>=3)throw out_of_range("Playlist index out of range");return tracks[i];}
};
int main(){
    Time t(3599);Time a=t++;Time b=++t;
    cout<<"Postfix result: ";a.display();cout<<"\nPrefix result: ";b.display();
    cout<<"\nCurrent time: ";t.display();cout<<'\n';
    Time next(3601);cout<<boolalpha<<"Current time is less than next: "<<(t<next)<<'\n';
    Playlist p;cout<<"Playlist:\n";for(int i=0;i<3;++i)cout<<i<<": "<<p[i]<<'\n';
    try{cout<<p[3]<<'\n';}catch(const out_of_range& e){cout<<"Range check: "<<e.what()<<'\n';}
}
