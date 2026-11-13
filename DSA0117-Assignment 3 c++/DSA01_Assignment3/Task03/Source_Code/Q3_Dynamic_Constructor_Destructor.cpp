#include <iostream>
using namespace std;
class Auditorium {
    int rows, seatsPerRow; bool** seats; int booked;
public:
    Auditorium(int r,int s):rows(r>0?r:0),seatsPerRow(s>0?s:0),seats(nullptr),booked(0){
        if(rows&&seatsPerRow){seats=new bool*[rows];for(int i=0;i<rows;++i)seats[i]=new bool[seatsPerRow]{};}
        cout<<"Auditorium created: "<<rows<<" x "<<seatsPerRow<<'\n';
    }
    bool book(int r,int s){if(r<0||r>=rows||s<0||s>=seatsPerRow||seats[r][s])return false;seats[r][s]=true;++booked;return true;}
    bool cancel(int r,int s){if(r<0||r>=rows||s<0||s>=seatsPerRow||!seats[r][s])return false;seats[r][s]=false;--booked;return true;}
    ~Auditorium(){for(int i=0;i<rows;++i)delete[] seats[i];delete[] seats;cout<<"Auditorium closed. Booked seats: "<<booked<<'\n';}
};
int main(){
    cout<<"Stack object:\n"; Auditorium morning(2,3);morning.book(0,0);morning.book(1,2);morning.cancel(0,0);
    cout<<"\nBlock-scope object:\n";{Auditorium special(1,2);special.book(0,1);}
    cout<<"\nHeap object:\n";Auditorium* evening=new Auditorium(2,2);evening->book(1,1);delete evening;
    cout<<"\nZero-row object:\n";Auditorium empty(0,5);
}
