//2023/05/03 kerong
/*
   Data_Structure : Linked List Circle
            Insert => O(n)
            Remove => O(n)
           Display => O(n)
        countNodes => O(1)
*/
#include <iostream>
using namespace std;

template <class T>
class Linked_List_Circle{
private:
    struct Node{
        T val;
        Node *next;
    };
    Node *head;
    int NodeAmount;
public:
    Linked_List_Circle(){
        head = nullptr;
        NodeAmount = 0;
    }


    void Insert(T data){
        Node *newNode = new Node;
        newNode->val= data;
        NodeAmount += 1;
        if(head == nullptr){
            head = newNode;
            head->next = head;
            return;
        }
        else{
            Node *currNode = head;
            while(currNode->next != head){
                currNode = currNode->next;
            }
            currNode->next = newNode;
            currNode = currNode->next;
            currNode->next = head;
            return;
        }
    }

    void Remove(T data){
        Node *currNode = head->next;
        Node *prevNode = head;
        if(prevNode->val == data){
            head = currNode;
            delete prevNode;
            NodeAmount -= 1;
            return;
        }
        else{
            while(currNode != nullptr && currNode->val != data && currNode != head){
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
            return;
        }
    }

    void Display(){
        Node *currnode = head;

        if(currnode){
            cout << currnode->val << " ";
            currnode = currnode->next;
        }

        while(currnode != head){
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
    Linked_List_Circle<int> list;
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
