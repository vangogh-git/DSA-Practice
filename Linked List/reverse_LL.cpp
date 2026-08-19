// time complexity  : O(n)
// space complexity : O(1)
// iterative approach

/* Structure of Linked List Node
class Node {
 public:
    int data ;
    Node *next ;

    Node(int x) {
        data = x ;
        next = nullptr ;
    }
};
*/

class Solution {
  public:
    Node* reverseList(Node* head) {
        
        // iterative 
        Node* prev = NULL;
        Node* next = NULL;
        Node* curr = head;
        while(curr != NULL) {
            next = curr -> next;
            curr -> next = prev;
            prev = curr;
            curr = next;
        }
        
        return prev;
        
    }
};
