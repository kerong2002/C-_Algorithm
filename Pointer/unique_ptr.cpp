//2023/05/04 kerong
#include <iostream>
#include <memory>

#define SIZE 10

using namespace std;

void printUniquePtr(unique_ptr<bool[]> &b_ptr) {
    for (int x = 0; x < SIZE; x++) {
        cout << b_ptr[x] << " ";

    }
    cout << "\n";
    return;
}

int main(){
    unique_ptr<int> p1(new int(10));
    unique_ptr<int> p2 = move(p1);

    cout << (p1 ? "P1 is not NULL.\n" : "P1 is NULL.\n");
    cout << (p2 ? "P2 is not NULL.\n" : "P2 is NULL.\n");
    cout << *p2 << endl;

    int* take_ptr = p2.release();
    cout << *take_ptr << endl;

    p2.reset(new int(20));
    cout << *p2 << endl;

    p2.reset();

    cout << (p2 ? "P2 is not NULL.\n" : "P2 is NULL.\n");

    unique_ptr<bool[]> b1(new bool[SIZE]);

    for (int x = 0; x < SIZE; x++) {
        b1[x] = x & 1;
    }

    printUniquePtr(b1);

    for (int x = 0; x < SIZE; x++) {
        b1[x] = b1[x] ^ 1;
    }

    printUniquePtr(b1);


    return 0;
}
