//2023/05/03 kerong
/*
   Data_Structure : Stack Linked List
     push(): O(1)
      pop(): O(1)
      top(): O(1)
    empty(): O(1)
*/
#include <iostream>

using namespace std;

template <class T, int MAXSIZE>
class CStack {
private:
    struct node{
        T val;
        node *next;
    };
    node *head;
    int stack_ammount;
public:
    CStack() { head = nullptr;
              stack_ammount = 0;
             }
    ~CStack(){
        while(head){
            node * temp = head;
            head = head->next;
            delete temp;
        }
    }
    bool empty() {
        return (head == nullptr);
    }
    bool full() {
        return (stack_ammount==MAXSIZE-1);
    }
    void push(T e) {
        if (full()) {
            cout << "full" << endl;
            return;
        }
        node *temp = new node;
        temp->val = e;
        temp->next = head;
        head = temp;
        return;
    }
    T pop() {
        if (empty()) {
            cout << "empty" << endl;
            exit(-1);
        }
        node *temp = head;
        head = head->next;
        T data = temp->val;
        delete temp;
        return data;
    }
    T s_top(){
        if (empty()) {
            cout << "empty" << endl;
            exit(-1);
        }
        return head->val;
    }
    void ShowStack() {
        node *temp = head;
        while (temp){
            cout << temp->val << " ";
            temp = temp->next;
        }
        cout << endl;
    }

};



int main(){
    CStack<int, 25> cs1;
    for (int idx=1; idx<10; ++idx){
        cs1.push(idx);
    }
    cs1.ShowStack();

    CStack<char, 10> cs2;
    for (int jdx=65; jdx<70; ++jdx){
        cs2.push(jdx);
    }
    cs2.ShowStack();

    return 0;
}
