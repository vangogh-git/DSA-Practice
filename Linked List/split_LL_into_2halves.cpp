// time complexity:  O(n)
// space complexity : O(1)


/* The structure of linked list Node
struct Node
{
  int data;
  struct Node *next;

  Node(int x){
      data = x;
      next = nullptr;
  }
};
*/

class Solution {
  public:
    pair<Node *, Node *> splitList(struct Node *head) {
        Node* slow = head;
        Node* fast = head -> next;
        Node* tail = NULL;
        while(fast != head && fast -> next != head) {
            slow = slow -> next;
            if(fast -> next -> next == head) {
                tail = fast -> next;
            }
            fast = fast -> next -> next;
        }
        
        Node* nextHead = slow -> next;
        slow -> next = NULL;
        if(fast -> next == head) {
            slow -> next = fast -> next;
            fast -> next = nextHead;
        }
        if(fast == head) {
            slow -> next = fast;
            tail -> next = nextHead;
        }
        
        return {head,nextHead};
        
    }
};
