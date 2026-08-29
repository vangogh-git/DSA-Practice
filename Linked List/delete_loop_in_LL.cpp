// time complexity : O(n)
// space complexity : O(1)


/* Structure of Linked List Node
class Node {
  public:
    int data;
    Node* next;

    Node(int val) {
        data = val;
        next = nullptr;
    }
};
*/
class Solution {
  public:
    void removeLoop(Node* head) {
        
        if(head == NULL || head -> next == NULL) return ;
        if(head -> next == head){
            head -> next = NULL;
            return ;
        } 
        
        Node* slow = head;
        Node* fast = head;
        
        while(fast != NULL && fast -> next != NULL) {
            slow = slow -> next;
            fast = fast -> next -> next;
            if(slow == fast) break;
        }
        
        if(fast == NULL || fast -> next == NULL) {
            return ;
        }
        
        if(slow == head) {
            while(fast -> next != head) {
                fast = fast -> next;
            }
            fast -> next = NULL;
            return ;
        }
        
        slow = head;
        
        while(slow->next != fast->next) {
            slow = slow -> next;
            fast = fast -> next;
        }
        
        fast -> next = NULL;
        return ;
        
    }
};
