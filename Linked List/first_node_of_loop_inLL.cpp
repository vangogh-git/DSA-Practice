// t.c : O(n)
// s.c : O(1)
// Using Floyd's Algorithm

/*
class Node {
public:
    int data;
    Node *next;

    Node(int x) {
        data = x;
        next = NULL;
    }
};
*/

class Solution {
  public:
    int cycleStart(Node* head) {
        
        if(head == NULL || head -> next == NULL) return -1;
        if(head -> next == head) return head -> data;
        
        Node* slow = head;
        Node* fast = head;
        
        while(fast != NULL && fast->next != NULL) {
            slow = slow -> next;
            fast = fast -> next -> next;
            if(slow == fast) break;
        }
        
        if(fast == NULL || fast -> next == NULL) return -1;
        
        slow = head;
        
        while(slow != fast) {
            slow = slow -> next;
            fast = fast -> next;
        }
        
        return fast -> data;
        
    }
};
