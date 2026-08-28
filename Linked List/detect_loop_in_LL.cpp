// time complexity : O(n)
// space complexity : O(1)
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
} */

class Solution {
  public:
    bool detectLoop(Node* head) {
        
        if(head == NULL || head -> next == NULL) return false;
        if(head -> next == head) return true;
        
        Node* slow = head;
        Node* fast = head;
        
        while(fast != NULL) {
            slow = slow -> next;
            if(fast -> next == NULL) return false;
            fast = fast -> next -> next;
            if(slow == fast) return true;
        }
        return false;
        
    }
};
