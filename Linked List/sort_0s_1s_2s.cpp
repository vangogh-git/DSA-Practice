/* Node is defined as
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
    Node* segregate(Node* head) {
        
        Node* head0 = NULL;
        Node* head1 = NULL;
        Node* head2 = NULL;
        Node* temp = head;
        bool found0 = false , found1 = false , found2 = false;
        while(temp != NULL) {
            if(temp -> data == 1 && !found1) {
                head1 = temp;
                found1 = true;
            }
            else if(temp -> data == 2 && !found2) {
                head2 = temp;
                found2 = true;
            }
            else if(temp -> data == 0 && !found0) {
                head0 = temp;
                found0 = true;
            }
            temp = temp -> next;
        }
        
        Node* prev = head1;
        Node* curr = head1 -> next;
        
        while(curr != NULL) {
            if(curr -> data == 1) {
                prev -> next = curr;
                prev = curr;
                curr = curr -> next;
            }
            else {
                curr = curr -> next;
            }
        }
        if(curr == NULL) prev -> next = NULL;
        Node* tail1 = prev;
        
        prev = head2;
        curr = head2 -> next;
        
        while(curr != NULL) {
            if(curr -> data == 2) {
                prev -> next = curr;
                prev = curr;
                curr = curr -> next;
            }
            else {
                curr = curr -> next;
            }
        }
        if(curr == NULL) prev -> next = NULL;
        Node* tail2 = prev;
        
        prev = head0;
        curr = head0 -> next;
        
        while(curr != NULL) {
            if(curr -> data == 0) {
                prev -> next = curr;
                prev = curr;
                curr = curr -> next;
            }
            else {
                curr = curr -> next;
            }
        }
        if(curr == NULL) prev -> next = NULL;
        Node* tail0 = prev;
        
        tail0 -> next = head1;
        tail1 -> next = head2;
        return head0;
        
        
    }
};
