#include <iostream>
using namespace std;

class Node {
    public :
    int data;
    Node* next = NULL;

    Node(int data) {
        this -> data = data;
        this -> next = NULL;
    }
};

void InsertAtHead(Node* &head , int d) {
    // we insert
    Node* temp = new Node(d);
    temp -> next = head;
    head = temp;
}

void InsertAtTail(Node* &tail , int d) {
    Node* temp = new Node(d);
    tail -> next = temp;
    tail = temp;
}

void printNodes(Node* &head) {
    
    Node* temp = head;
    while(temp != NULL) {
        cout << temp -> data << " ";
        temp = temp -> next;
    }
}

int main() {
    
    // we create the node first
    Node* node1 = new Node(10);

    Node* head = node1;

    Node* tail = node1;

    InsertAtTail(tail , 12);
    InsertAtTail(tail , 15);
    printNodes(head);
}
