// time complexity : O(n)
// space complexity : O(1)

/* Structure of a Linked List node
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
    private:
    void reverse(Node* &head) {
        Node* prev = NULL;
        Node* curr = head;
        while(curr != NULL) {
            Node* next = curr -> next;
            curr -> next = prev;
            prev = curr;
            curr = next;
        }
        
        head = prev;
    }
  public:
    Node *compute(Node *head) {
        
        reverse(head);
        
        Node* prev = head;
        Node* curr = head -> next;
        int maxi = head->data;
        
        while(curr != NULL) {
            if(curr -> data >= maxi ) {
                maxi = curr -> data;
                prev = curr;
                curr = curr -> next;
            }
            else {
                prev -> next = curr -> next;
                curr = curr -> next;
            }
        }
        
        reverse(head);
        return head;
        
    }
};
