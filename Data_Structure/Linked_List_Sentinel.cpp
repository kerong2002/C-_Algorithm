//2023/05/03 kerong
/*
   Data_Structure : Linked List Sentinel
            Insert => O(n)
            Remove => O(n)
           Display => O(n)
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
    Node* head;
    int NodeAmount;

public:
    Linked_List_Sentinel(){
        sentinel = new Node(0);
        sentinel->next = sentinel;
        head = nullptr;
        NodeAmount = 0;
    }


    void Insert(T data){
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

    void Remove(T data){
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
            head = currNode->next;
        }
        delete currNode;
        NodeAmount -= 1;
        return;
    }

    void Display(){
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
    list.Insert(1);
    list.Insert(2);
    list.Insert(3);
    list.Insert(4);

    cout << "Number of nodes: " << list.countNodes() << endl;
    list.Display();

    list.Remove(2);

    cout << "Number of nodes: " << list.countNodes() << endl;
    list.Display();

    list.Remove(4);

    cout << "Number of nodes: " << list.countNodes() << endl;
    list.Display();


    return 0;
}
