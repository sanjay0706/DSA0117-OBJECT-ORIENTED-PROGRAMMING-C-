#include <iostream>
#include <string>
using namespace std;
class Book {
    string title, author;
    int copies;
    static int valid(int n) { return n < 0 ? 0 : n; }
public:
    Book() : Book("Untitled", "Unknown", 0) {}
    explicit Book(const string& t) : Book(t, "Unknown", 0) {}
    Book(const string& t, const string& a) : Book(t, a, 0) {}
    Book(const string& t, const string& a, int n)
        : title(t), author(a), copies(valid(n)) {}
    void display() const {
        cout << "Title: " << title << "\nAuthor: " << author
             << "\nCopies: " << copies << "\n\n";
    }
};
int main() {
    Book a, b("The Alchemist"), c("Wings of Fire","A. P. J. Abdul Kalam");
    Book d("C++ Programming","Bjarne Stroustrup",5), e("Invalid","Unknown",-4);
    cout << "Default constructor:\n"; a.display();
    cout << "Title-only constructor:\n"; b.display();
    cout << "Title and author constructor:\n"; c.display();
    cout << "Parameterized constructor:\n"; d.display();
    cout << "Negative copies validation:\n"; e.display();
}
