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


class B;

class A {
public:
//    shared_ptr<B> ptrA_B;   //shared_ptr (X)
    weak_ptr<B> ptrA_B;     //weak_ptr (V)
public:
    A() {
        cout << "class A constructor\n";
    }
    ~A() {
        cout << "class A destructor\n";
    }
};

class B {
public:
//    shared_ptr<A> ptrB_A;   //shared_ptr (X)
    weak_ptr<A> ptrB_A;     //weak_ptr (V)
public:
    B() {
        cout << "class B constructor\n";
    }
    ~B() {
        cout << "class B destructor\n";
    }
};

int main(){

    shared_ptr<B> ptrB(new B);
    shared_ptr<A> ptrA(new A);
    ptrA->ptrA_B = ptrB;
    ptrB->ptrB_A = ptrA;


    shared_ptr<bool[]> b1(new bool[SIZE]);

    for (int x = 0; x < SIZE; x++) {
        b1[x] = ! (x & 1);
    }

    printSharedPtr(b1);

    weak_ptr<bool[]> w_ptr(b1);

    if (shared_ptr<bool[]> b2 = w_ptr.lock()) {
        cout << "Got shared_ptr: ";
        cout << *b2 << "\n";
    }
    else {
        cout << "Expired\n";
    }

    if(w_ptr.expired()){
        cout << "Pointer is expired\n";
    }

    b1.reset();

    if(w_ptr.expired()){
        cout << "Pointer is expired\n";
    }


    return 0;
}
