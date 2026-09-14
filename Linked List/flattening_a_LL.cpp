// t.c : 
// s.c :
// brute force approach -> Time Limit Exceeded

/* Structure of Linked List Node
class Node {
public:
    int data;
    Node* next;
    Node* bottom;

    Node(int x) {
        data = x;
        next = nullptr;
        bottom = nullptr;
    }
};*/

class Solution {
    private:
    Node* merge(Node* &head1 , Node* &head2) {
        Node* t1 = head1;
        Node* t2 = head2;
        
        Node* newNode = new Node(-1);
        Node* t = newNode;
        while(t1 != NULL && t2 != NULL) {
            if(t1 -> data <= t2 -> data) {
                t -> bottom = t1;
                t1 = t1 -> bottom;
            }
            else {
                t -> bottom = t2;
                t2 = t2 -> bottom;
            }
            t = t -> bottom;
        }
        
        while(t1 != NULL) {
            t -> bottom = t1;
            t1 = t1 -> bottom;
            t = t -> bottom;
        }
        
        while(t2 != NULL) {
            t -> bottom = t2;
            t2 = t2 -> bottom;
            t = t -> bottom;
        }
        
        return newNode -> bottom;
    }
  public:
    Node* flatten(Node* head) {
        
        if(head == NULL || head -> next == NULL) return head;
        
        Node* prev = head;
        Node* curr = head -> next;
        
        while(curr != NULL) {
            Node* nextNode = curr -> next;
            prev -> next = NULL;
            curr -> next = NULL;
            head = merge(prev , curr);
            head -> next = nextNode;
            prev = head;
            curr = head -> next;
        }
        
        return head;
    }
};
