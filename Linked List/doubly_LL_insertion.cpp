#include <iostream>
using namespace std;

class Node{
    public:
        int data;
        Node* next;
        Node* prev;

        Node(int data) {
            this -> data = data;
            this -> next = NULL;
            this -> prev = NULL;
        }
};

void insertAtHead(Node* &head , int data) {

    Node* node2 = new Node(data);
    node2 -> next = head;
    head -> prev = node2;
    head = node2;
    
}

void insertAtTail(Node* head , int data) {

    Node* node3 = new Node(data);
    Node* tail = head;
    while(tail -> next != NULL) {
        tail = tail -> next;
    }
    tail -> next = node3;
    node3 -> prev = tail;
    tail = node3;

}

void insertAtPosition(Node* &head , int pos , int data) {
    Node* node1 = new Node(data);
    Node* temp = head;
    int cnt = 1;
    while(cnt < pos) {
        temp = temp -> next;
        cnt++;
    }
    temp -> next -> prev = node1;
    node1 -> prev = temp;
    node1 -> next = temp -> next;
    temp -> next = node1;
    return ;
}

int main() {
    // create a new node
    Node* node1 = new Node(5);
    Node* head = node1;

    insertAtHead(head , 10);
    insertAtHead(head , 15);
    insertAtHead(head , 20);

    // print 
    Node* temp = head;
    while(temp != NULL) {
        cout << temp -> data << " ";
        temp = temp -> next;
    }
    cout << endl;

    insertAtTail(head , 22);

    temp = head;
    while(temp != NULL) {
        cout << temp -> data << " ";
        temp = temp -> next;
    }
    cout << endl;
    
    insertAtPosition(head , 3 , 9999);

    temp = head;
    while(temp != NULL) {
        cout << temp -> data << " ";
        temp = temp -> next;
    }

}
