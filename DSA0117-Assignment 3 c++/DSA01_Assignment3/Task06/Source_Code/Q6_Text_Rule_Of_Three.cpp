#include <cstring>
#include <iostream>
using namespace std;
class Text {
    char* data;
public:
    Text(const char* s=""){data=new char[strlen(s)+1];strcpy(data,s);}
    Text(const Text& o){data=new char[strlen(o.data)+1];strcpy(data,o.data);cout<<"Copy constructor called\n";}
    Text& operator=(const Text& o){if(this!=&o){char* p=new char[strlen(o.data)+1];strcpy(p,o.data);delete[] data;data=p;}return *this;}
    ~Text(){delete[] data;}
    Text operator+(const Text& o)const{char* p=new char[strlen(data)+strlen(o.data)+1];strcpy(p,data);strcat(p,o.data);Text result(p);delete[] p;return result;}
    bool operator==(const Text& o)const{return strcmp(data,o.data)==0;}
    bool operator!=(const Text& o)const{return !(*this==o);}
    friend ostream& operator<<(ostream& out,const Text& t){return out<<t.data;}
};
int main(){
    Text a("Hello "),b("World"),c=a+b;cout<<"Concatenated text: "<<c<<'\n';
    Text copy=c;cout<<"Copied text: "<<copy<<'\n'<<boolalpha<<"Copy equals original: "<<(copy==c)<<'\n';
    copy=copy;cout<<"After self-assignment: "<<copy<<'\n';
    Text empty;cout<<"Empty text: ["<<empty<<"]\nEmpty differs from message: "<<(empty!=c)<<'\n';
}
