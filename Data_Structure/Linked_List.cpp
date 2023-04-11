//2023/04/11 kerong
/*
   Data_Structure : Linked List
            InsertNode => O(n)
    Insert_to_headNode => O(1)
            DeleteNode => O(n)
            SearchNode => O(n)
*/
#include <iostream>
using namespace std;

template <class T>
struct Node{
    T data;
    Node *next;
};

template <class T>
class Linked_List{
private:
    Node<T> *head;
    int NodeAmount;
public:
    Linked_List(){
        head = nullptr;
        NodeAmount = 0;
    }

    void Insert_to_headNode(T data){
        Node<T> *newNode = new Node<T>;
        newNode->data = data;
        newNode->next = head;
        head = newNode;
        NodeAmount += 1;
        return;
    }


    void InsertNode(T data){
        Node<T> *newNode = new Node<T>;
        newNode->data = data;
        newNode->next = nullptr;
        NodeAmount += 1;
        if(head == nullptr){
            head = newNode;
            return;
        }
        Node<T> *currNode = head;
        while(currNode->next != nullptr){
            currNode = currNode->next;
        }
        currNode->next = newNode;
        return;
    }

    void DeleteNode(T data){
        Node<T> *currNode = head;
        Node<T> *prevNode = nullptr;
        while(currNode != nullptr && currNode->data != data){
            prevNode = currNode;
            currNode = currNode->next;
        }
        if(currNode != nullptr){
            if(prevNode != nullptr){
                prevNode->next = currNode->next;
            }
            else{
                head = currNode->next;
            }
            delete currNode;
            NodeAmount -= 1;
        }
    }

    bool SearchNode(T data){
        Node<T> *currNode = head;
        while(currNode != nullptr && currNode->data != data){
            currNode = currNode->next;
        }
        return (currNode != nullptr);
    }

    int countNodes(){
        return NodeAmount;
    }
};

int main(){
    Linked_List<int> list;
    list.InsertNode(1);
    list.InsertNode(2);
    list.InsertNode(3);
    list.Insert_to_headNode(4);
    cout << "Number of nodes: " << list.countNodes() << endl;

    if (list.SearchNode(2)) {
        cout << "Node found" << endl;
    } else {
        cout << "Node not found" << endl;
    }

    list.DeleteNode(2);

    cout << "Number of nodes: " << list.countNodes() << endl;

    if (list.SearchNode(2)) {
        cout << "Node found" << endl;
    } else {
        cout << "Node not found" << endl;
    }

    return 0;
}
