//2023/04/01 kerong
/*
   Data_Structure : Queue
    isEmpty(): O(1)
     isFull(): O(1)
    enQueue(): O(1)
    enQueue(): O(1)
*/
#include <iostream>
#define MAX_QUEUE_SIZE 100
using namespace std;
template <class T, int MAXSIZE>

class CQueue{
private:
    T elems[MAXSIZE];
    int front;
    int rear;
public:
    CQueue(){
        front = -1;
        rear = -1;
    }
    bool isEmpty(){
        return (front == rear);
    }
    bool isFull(){
        return (rear >= MAXSIZE-1);
    }
    void enQueue(T q){
         if (isFull()) {
            cout << "full" << endl;
            exit(-1);
        }
        elems[++rear] = q;
    }
    T deQueue(){
        if (isEmpty()) {
            cout << "empty" << endl;
            exit(-1);
        }
        return elems[++front];
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
    ShowQueue(q1);

    CQueue<char, 10> q2;
    q2.enQueue('D');
    q2.enQueue('C');
    q2.enQueue('B');
    q2.enQueue('A');
    ShowQueue(q2);
    return 0;
}
