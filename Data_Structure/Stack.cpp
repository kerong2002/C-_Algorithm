//2023/04/01 kerong
/*
   Data_Structure : Stack
     push(): O(1)
      pop(): O(1)
      top(): O(1)
    empty(): O(1)
*/
#include <iostream>

using namespace std;

template <class T, int MAXSIZE>
class CStack {
    T elems[MAXSIZE];
    int top;
public:
    CStack() { top=-1; }
    bool empty() {
        return (top==-1);
    }
    bool full() {
        return (top==MAXSIZE-1);
    }
    void push(T e) {
        if (top>=MAXSIZE-1) {
            cout << "full" << endl;
            return;
        }
        elems[++top] = e;
    }
    T pop() {
        if (top<0) {
            cout << "empty" << endl;
            exit(-1);
        }
        return elems[top--];
    }
    T s_top(){
        if (top<0) {
            cout << "empty" << endl;
            exit(-1);
        }
        return elems[top];
    }

};

template <class T, int MAXSIZE>
void ShowStack(CStack<T,MAXSIZE> &s) {
    while (!s.empty()){
        cout << s.pop();
    }
    cout << endl;
}

int main(){
    CStack<int, 25> cs1;
    for (int idx=1; idx<10; ++idx){
        cs1.push(idx);
    }
    ShowStack(cs1);

    CStack<char, 10> cs2;
    for (int jdx=65; jdx<70; ++jdx){
        cs2.push(jdx);
    }
    ShowStack(cs2);

    return 0;
}
