//2023/05/03 kerong
/*
   Data_Structure : Queue Linked List
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
    struct node{
        int val;
        node *next;
    };
    node *front;
    node *rear;
    int node_amount;
public:
    CQueue(){
        front = nullptr;
        rear  = nullptr;
        node_amount = 0;
    }
    bool isEmpty(){
        return (node_amount == 0);
    }
    bool isFull(){
        return (node_amount >= MAXSIZE-1);
    }
    void enQueue(T q){
         if (isFull()) {
            cout << "full" << endl;
            exit(-1);
        }
        else if(isEmpty()){
            node *temp = new node;
            temp->val = q;
            temp->next = nullptr;
            front = temp;
            rear = temp;
            node_amount++;
            return;
        }
        else{
            node *temp = new node;
            temp->val = q;
            temp->next = nullptr;
            rear->next = temp;
            rear = temp;
            node_amount++;
            return;
        }
    }
    T deQueue(){
        if (isEmpty()) {
            cout << "empty" << endl;
            exit(-1);
        }
        else{
            node *temp = front;
            T data = temp->val;
            front = front->next;
            node_amount--;
            delete temp;
            return data;
        }
    }
    void ShowQueue() {
        node *temp = front;
        while (temp){
            cout << temp->val << " ";
            temp = temp->next;
        }
        cout << endl;
    }
};



int main(){
    CQueue<int, 5> q1;
    q1.enQueue(1);
    q1.enQueue(2);
    q1.enQueue(3);
    q1.enQueue(4);
    q1.ShowQueue();

    CQueue<char, 10> q2;
    q2.enQueue('D');
    q2.enQueue('C');
    q2.enQueue('B');
    q2.enQueue('A');
    q2.ShowQueue();
    return 0;
}
