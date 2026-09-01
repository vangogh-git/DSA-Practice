// time complexity:  O(n+m)
// space complexity : O(1)
// brute force solution although optimized .... code can be cleaned further
/* Structure of a Linked list Node 
class Node {
  public:
    int data;
    Node* next;

    Node(int x) {
        data = x;
        next = nullptr;
    }
}; */

class Solution {
  public:
    Node* findIntersection(Node* head1, Node* head2) {
        
        if(head1 == NULL || head2 == NULL) return NULL;
        
        Node* c1 = head1;
        Node* c2 = head2;
        Node* p1 = NULL;
        
        // find the first occurence of head
        while(c1 != NULL && c2 != NULL) {
            if(c1-> data < c2 -> data) {
                p1 = c1;
                c1 = c1 -> next;
            }   
            else if(c2 -> data < c1 -> data) {
                c2 = c2 -> next;
            }
            else {
                break;
            }
        }
        if(c1 == NULL || c2 == NULL) return NULL;
        
        head1 = c1;
        
        while(c1 != NULL && c2 != NULL) {
            if(c1->data == c2 -> data) {
                p1 = c1;
                c1 = c1 -> next;
                c2 = c2 -> next;
            }
            else if(c2->data < c1->data) {
                c2 = c2 -> next;
            }
            else {
                // c1 -> data < c2 -> data
                p1 -> next = c1 -> next;
                c1 = c1 -> next;
            }
        }
        
        if(c2 == NULL) p1 -> next = NULL;
        
        return head1;
        
        
    }
};


// t.c : O(n+m)
// s.c : O(1)
// clean code + optimized Solution


/* Structure of a Linked list Node 
class Node {
  public:
    int data;
    Node* next;

    Node(int x) {
        data = x;
        next = nullptr;
    }
}; */

class Solution {
  public:
    Node* findIntersection(Node* head1, Node* head2) {
        
        if(head1 == NULL || head2 == NULL) return NULL;
        
        Node* c1 = head1;
        Node* c2 = head2;
        Node* head = NULL;
        Node* tail = NULL;
        
        while(c1 != NULL && c2 != NULL) {
            if(c1 -> data == c2 -> data) {
                if(head == NULL) {
                    head = c1;
                    tail = c1;
                }
                else {
                    tail -> next = c1;
                    tail = c1;
                }
                
                c1 = c1 -> next;
                c2 = c2 -> next;
            }
            else if(c1 -> data < c2 -> data) {
                c1 = c1 -> next;
            }
            else {
                c2 = c2 -> next;
            }
        }
        
        if(tail != NULL) {
            tail -> next = NULL;
        }
        
        return head;        
    }
};
