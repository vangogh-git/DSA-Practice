// time complexity : O(n)
// space complexity : O(1)

/* Structure of Linked List Node
class Node {
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
    Node* deleteNode(Node* head, int key) {
        
        Node* prev = head;
        Node* curr = head -> next;
        
        bool keyFound = false;
        
        if(head -> data == key) {
            while(curr != head) {
                prev = curr;
                curr = curr -> next;
            }
            prev -> next = curr -> next;
            curr = curr -> next;
            head = curr;
            keyFound = true;
        }
        
        while(curr != head) {
            if(curr -> data == key && keyFound == false) {
                prev -> next = curr -> next;
                curr = curr -> next;
                keyFound = true;
            }
            else {
                prev = curr;
                curr = curr -> next;
            }
        }
        return head;
    }
};
