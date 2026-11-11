#include <iostream>
using namespace std;

int& highestMark(int marks[], int size) {
    int highestIndex = 0;

    for (int i = 1; i < size; ++i) {
        if (marks[i] > marks[highestIndex]) {
            highestIndex = i;
        }
    }

    return marks[highestIndex];
}

int highestMarkIndex(const int marks[], int size) {
    int highestIndex = 0;

    for (int i = 1; i < size; ++i) {
        if (marks[i] > marks[highestIndex]) {
            highestIndex = i;
        }
    }

    return highestIndex;
}

int main() {
    int marks[] = {76, 91, 84, 88};
    const int size = 4;

    cout << "Highest mark before moderation: "
         << highestMark(marks, size) << '\n';

    highestMark(marks, size) += 2;

    cout << "Highest mark after moderation: "
         << highestMark(marks, size) << '\n';

    int index = highestMarkIndex(marks, size);

    cout << "Index-based result: marks[" << index
         << "] = " << marks[index] << '\n';

    cout << "A reference to a local variable must not be returned,"
         << " because it becomes dangling after the function ends."
         << '\n';

    return 0;
}
