// Time Complexity : O(n)
// Space Complexity : O(1)

/*
class Node {
public:
    int data;
    Node* next;

    Node(int x) {
        data = x;
        next = nullptr;
    }
};

*/
class Solution {
  public:
    Node *moveToFront(Node *head) {
        
        if(head == NULL) return NULL;
        if(head -> next == NULL) return head;
        
        Node* prev = head;
        Node* curr = head->next;
        
        while(curr -> next != NULL) {
            curr = curr -> next;
            prev = prev -> next;
        }
        
        curr -> next = head;
        prev -> next = NULL;
        head = curr;
        return head;
        
    }
};
