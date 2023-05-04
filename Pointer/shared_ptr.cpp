//2023/05/04 kerong
#include <iostream>
#include <memory>

#define SIZE 10

using namespace std;

void printSharedPtr(shared_ptr<bool[]> b_ptr) {
    for (int x = 0; x < SIZE; x++) {
        cout << b_ptr[x] << " ";
    }
    cout << "\n";
    return;
}

int main(){
    shared_ptr<int> p1(new int(15));
    cout << p1.use_count() << endl;

    shared_ptr<int> p2 = p1;
    cout << p1.use_count() << endl;

    p1.reset();
    cout << (p1 ? "P1 is not NULL.\n" : "P1 is NULL.\n");
    cout << (p2 ? "P2 is not NULL.\n" : "P2 is NULL.\n");

    cout << *p2 << endl;


    p1.reset(new int(20));
    cout << *p1 << endl;


    shared_ptr<int> p3(p1);     //copy
    cout << *p3 << endl;

    shared_ptr<bool[]> b1(new bool[SIZE]);

    for (int x = 0; x < SIZE; x++) {
        b1[x] = x & 1;
    }

    printSharedPtr(b1);

    for (int x = 0; x < SIZE; x++) {
        b1[x] = b1[x] ^ 1;
    }

    printSharedPtr(b1);


    return 0;
}
