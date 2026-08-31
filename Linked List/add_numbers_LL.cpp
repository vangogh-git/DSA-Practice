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
    Node* addTwoLists(Node* head1, Node* head2) {
        
        reverse(head1);
        reverse(head2);
        
        Node* prev1 = NULL;
        Node* curr1 = head1;
        Node* curr2 = head2;
        
        int carry = 0;
        while(curr1 != NULL && curr2 != NULL) {
            int temp = curr1->data + curr2->data + carry;
            curr1->data = temp % 10;
            carry = temp / 10;
            
            if(curr1 -> next == NULL && curr2 -> next == NULL && carry != 0) {
                Node* node1 = new Node(carry);
                curr1 -> next = node1;
            }
            
            prev1 = curr1;
            curr1 = curr1 -> next;
            curr2 = curr2 -> next;
        }
        
        while(curr1 != NULL) {
            int temp = curr1->data + carry;
            curr1 -> data = temp % 10;
            carry = temp / 10;
            
            if(curr1 -> next == NULL && carry != 0) {
                Node* node1 = new Node(carry);
                curr1 -> next = node1;
            }
            
            curr1 = curr1 -> next;
        }
        
        while(curr2 != NULL) {
            int temp = curr2 -> data + carry;
            prev1 -> next = new Node(temp % 10);
            carry = temp / 10;
            
            if(curr2 -> next == NULL && carry != 0) {
                prev1 -> next = new Node(carry);
            }
            
            prev1 = prev1 -> next;
            curr2 = curr2 -> next;
        }
        
        reverse(head1);
        
        while(head1 -> data == 0) {
            head1 = head1 -> next;
        }
        return head1;
    }
};
