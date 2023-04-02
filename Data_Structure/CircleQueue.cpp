//2023/04/01 kerong
/*
   Data_Structure : Circle Queue
    isEmpty(): O(1)
     isFull(): O(1)
    enQueue(): O(1)
    enQueue(): O(1)
*/
#include <iostream>

using namespace std;
template <class T, int MAXSIZE>

class CQueue{
private:
    T elems[MAXSIZE];
    int front;
    int rear;
public:
    CQueue(){
        front = 0;
        rear = 0;
    }
    bool isEmpty(){
        return (front == rear);
    }
    bool isFull(){
        return ((rear+1)%MAXSIZE==front);
    }
    void enQueue(T q){
        if(isFull()){
            cout << "full" << endl;
            exit(-1);
        }
        rear = (rear+1) % MAXSIZE;
        elems[rear] = q;
    }
    T deQueue(){
        if(isEmpty()){
            cout << "empty" << endl;
            exit(-1);
        }
        front = (front+1) % MAXSIZE;
        return elems[front];
    }
};

template <class T, int MAXSIZE>
void ShowQueue(CQueue<T,MAXSIZE> &q) {
    while (!q.isEmpty()){
        cout << q.deQueue();
    }
    cout << endl;
}

int main(){
    CQueue<int, 5> q1;
    q1.enQueue(1);
    q1.enQueue(2);
    q1.enQueue(3);
    q1.enQueue(4);
    q1.deQueue();
    q1.deQueue();
    q1.enQueue(5);
    q1.enQueue(6);
    ShowQueue(q1);
    return 0;
}
