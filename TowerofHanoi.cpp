#include <iostream>
#include <string>
using namespace std;

void printMove(string fr, string to) {
    cout << "move from " << fr << " to " << to << endl;
}

void Towers(int n, string fr, string to, string spare) {
    if (n == 1)
        printMove(fr, to);
    else {
        Towers(n - 1, fr, spare, to);
        Towers(1, fr, to, spare);
        Towers(n - 1, spare, to, fr);
    }
}


int main() {
    Towers(4, "P1", "P2", "P3");
    return 0;
}