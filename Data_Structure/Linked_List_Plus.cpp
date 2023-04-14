//2023/04/14 kerong
/*
   Data_Structure : Linked List Plus
    MyLinkedList() => O(1)
             get() => O(n)
       addAtHead() => O(1)
       addAtTail() => O(n)
      addAtIndex() => O(n)
   deleteAtIndex() => O(n)

*/
#include <iostream>

using namespace std;
struct node{
    int val;
    node *next;
};

class MyLinkedList {
private:
    node *head;
    int node_amount;
public:
    MyLinkedList() {
       head = nullptr;
       node_amount = -1;
    }

    int get(int index) {
        if(node_amount < index){
            return -1;
        }
        else{
            int cnt = 0;
            node *startNode = head;
            while(cnt < index){
                cnt += 1;
                startNode = startNode->next;
            }
            return startNode->val;
        }
    }

    void addAtHead(int val) {
        node *newNode = new node;
        newNode->val = val;
        newNode->next = nullptr;
        node_amount += 1;
        if(head == nullptr){
            head = newNode;
            return;
        }
        else{
            newNode->next = head;
            head = newNode;
            return;
        }
    }

    void addAtTail(int val) {
        node *newNode = new node;
        newNode->val = val;
        newNode->next = nullptr;
        node_amount += 1;
        if(head == nullptr){
            head = newNode;
            return;
        }
        else{
            node *startNode = head;
            while(startNode->next != nullptr){
                startNode = startNode->next;
            }
            startNode->next = newNode;
            return;
        }
    }

    void addAtIndex(int index, int val) {
        if(index < 0 || node_amount+1 < index){
            return;
        }
        else if(index == 0){
            addAtHead(val);
        }
        else if(index == node_amount+1){
            addAtTail(val);
        }
        else{
            int cnt = 0;
            node *startNode = head;
            node *newNode = new node;
            newNode->val = val;
            newNode->next = nullptr;
            node_amount += 1;
            while(cnt < index-1){
                startNode = startNode->next;
                cnt += 1;
            }

            node *endNode = startNode->next;
            startNode->next = newNode;
            newNode->next = endNode;
        }
    }

    void deleteAtIndex(int index) {
        if(index < 0 || node_amount < index){
            return;
        }
        else if(index == 0){
            node *pre = head;
            head = head->next;
            node_amount -= 1;
            delete pre;
            return;
        }
        else{
            int cnt = 0;
            node *preNode = nullptr;
            node *startNode = head;
            node_amount -= 1;
            while(cnt < index){

                preNode = startNode;
                startNode = startNode->next;
                cnt += 1;
            }
            if(startNode->next == nullptr){
                preNode->next = nullptr;
            }
            else{
                preNode->next = startNode->next;
            }
            delete startNode;
            return;
        }
    }
};

/**
 * Your MyLinkedList object will be instantiated and called as such:
 * MyLinkedList* obj = new MyLinkedList();
 * int param_1 = obj->get(index);
 * obj->addAtHead(val);
 * obj->addAtTail(val);
 * obj->addAtIndex(index,val);
 * obj->deleteAtIndex(index);
 */
int main() {
    MyLinkedList* obj = new MyLinkedList();
    obj->addAtHead(7);
    obj->addAtHead(2);
    obj->addAtHead(1);

    obj->addAtIndex(3, 0);
    cout << obj->get(0) << endl;
    cout << obj->get(1) << endl;
    cout << obj->get(2) << endl;
    cout << obj->get(3) << endl;
    cout << obj->get(4) << endl;
    obj->deleteAtIndex(2);
    obj->addAtHead(6);

    obj->addAtTail(4);

    obj->addAtHead(4);

    obj->addAtIndex(5, 0);
    obj->addAtHead(6);

    return 0;
}
