// time complexity : O(n+m)
// space complexity : O(1)
// Optimal in-place LinkedList Modification Solution

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
        if(head1 -> next == NULL && head1 -> data == 0) return head2;
        if(head2 -> next == NULL && head2 -> data == 0) return head1;

        while(head1->data == 0 && head1->next != NULL) {
            head1 = head1 -> next;
        }
        
        while(head2->data == 0 && head2->next != NULL) {
            head2 = head2 -> next;
        }
        
        reverse(head1);
        reverse(head2);
        
        Node* prev1 = NULL;
        Node* curr1 = head1;
        Node* curr2 = head2;
        
        int carry = 0;
        while(curr1 != NULL && curr2 != NULL) {
            int sum = curr1 -> data + curr2 -> data + carry;
            curr1 -> data = sum % 10;
            carry = sum / 10;
            
            prev1 = curr1;
            curr1 = curr1 -> next;
            curr2 = curr2 -> next;
        } 
        
        while(curr1 != NULL) {
            int sum = curr1 -> data + carry;
            curr1 -> data = sum % 10;
            carry = sum / 10;
            
            prev1 = curr1;
            curr1 = curr1 -> next;
        }
        
        while(curr2 != NULL) {
            int sum = curr2 -> data + carry;
            prev1 -> next = new Node(sum % 10);
            carry = sum / 10;
            
            prev1 = prev1 -> next;
            curr2 = curr2 -> next;
        }
        
        if(carry != 0) {
            prev1 -> next = new Node(carry);
        }
        
        reverse(head1);
        
        // remove starting zeros
        while(head1->data == 0 && head1->next != NULL) {
            head1 = head1 -> next;
        }
        
        return head1;
    }
};
