// time complexity : O(n)
// space complexity : O(1)

/* Structure of a doubly link list node
class Node
{
public:
    int data;
    Node *prev;
    Node *next;

    Node(int x)
    {
        data = x;
        prev = nullptr;
        next = nullptr;
    }
};
*/

class Solution {
  public:
    Node *rotateDLL(Node *head, int k) {
        
        if(head -> next == NULL || head == NULL) {
            return head;
        }
        Node* newHead;
        Node* curr = head;
        Node* tail;
        int cnt = 1;
        while(curr != NULL) {
            if(cnt == k) {
                if(curr -> next == NULL) return head;
                    newHead = curr -> next;
                    curr -> next = NULL;
                    newHead -> prev = NULL;
                    curr = newHead; 
            }
            if(curr -> next == NULL) tail = curr; 
                curr = curr -> next;
                cnt++;
        }
            tail -> next = head;
            head -> prev = tail; 
        return newHead;
    }
};
