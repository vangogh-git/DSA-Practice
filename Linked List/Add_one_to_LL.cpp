// time complexity: O(n)
// space complexity : O(1)
// brute force approach

/* Structure of linked list Node
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
    Node* addOne(Node* head) {
        
        // first we reverse the LL
        reverse(head);
        
        // now we apply the Add +1 logic
        Node* curr = head;
        
        while(curr != NULL) {
            if(curr -> data != 9) {
                curr -> data += 1;
                break;
            }
            else {
                // equal to 9
                curr -> data = 0;
                if(curr -> next == NULL) {
                    Node* node1 = new Node(1);
                    curr -> next = node1;
                    break;
                }
                else {
                   curr = curr -> next; 
                }
            }
        }
        
        // reverse again
        reverse(head);
        return head;
        
    }
};
