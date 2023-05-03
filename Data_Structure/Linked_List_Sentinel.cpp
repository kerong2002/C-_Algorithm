//2023/05/03 kerong
/*
   Data_Structure : Linked List Sentinel
        insertNode => O(n)
        removeNode => O(n)
       displayNode => O(n)
        countNodes => O(1)
*/
#include <iostream>
using namespace std;

template <class T>
class Linked_List_Sentinel{
private:
    struct Node{
        T val;
        Node *next;
        Node(T data){
            val = data;
            next = nullptr;
        }
    };
    Node* sentinel;
    int NodeAmount;

public:
    Linked_List_Sentinel(){
        sentinel = new Node(0);
        sentinel->next = sentinel;
        NodeAmount = 0;
    }


    void insertNode(T data){
        Node* newNode = new Node(data);
        Node* currNode = sentinel->next;
        NodeAmount += 1;
        while(currNode->next != sentinel){
            currNode = currNode->next;
        }
        currNode->next = newNode;
        currNode = currNode->next;
        currNode->next = sentinel;
        return;
    }

    void removeNode(T data){
        Node *currNode = sentinel->next;
        Node *prevNode = sentinel;
        while(currNode != sentinel && currNode->val != data){
            prevNode = currNode;
            currNode = currNode->next;
        }
        if(prevNode != nullptr){
            prevNode->next = currNode->next;
        }
        else{
            sentinel = currNode->next;
        }
        delete currNode;
        NodeAmount -= 1;
        return;
    }

    void displayNode(){
        Node *currnode = sentinel->next;

        while(currnode != sentinel){
            cout << currnode->val << " ";
            currnode = currnode->next;
        }

        cout << endl;
    }

    int countNodes(){
        return NodeAmount;
    }
};

int main(){
    Linked_List_Sentinel<int> list;
    list.insertNode(1);
    list.insertNode(2);
    list.insertNode(3);
    list.insertNode(4);

    cout << "Number of nodes: " << list.countNodes() << endl;
    list.displayNode();

    list.removeNode(2);

    cout << "Number of nodes: " << list.countNodes() << endl;
    list.displayNode();

    list.removeNode(4);

    cout << "Number of nodes: " << list.countNodes() << endl;
    list.displayNode();


    return 0;
}
