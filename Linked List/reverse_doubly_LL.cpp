// Time Complexity : O(n)
// Space Complexityb:b O(1)

/* Structure of Doubly Linked List Node
class Node {
  public:
    int data;
    Node *next;
    Node *prev;

    Node(int val) {
        data = val;
        next = nullptr;
        prev = nullptr;
    }
};

*/
class Solution {
  public:
    Node *reverse(Node *head) {
        
        Node* prev = NULL;
        Node* curr = head;
        while(curr != NULL) {
            Node* next = curr -> next;
            curr -> next = curr -> prev;
            curr -> prev = next;
            prev = curr;
            curr = next;
        }
        return prev;
    }
};
