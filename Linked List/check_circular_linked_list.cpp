// Time Complexity : O(n)
// Space Complexity : O(1)

/* Link list Node
struct Node
{
    int data;
    struct Node* next;

    Node(int x){
        data = x;
        next = NULL;
    }

};
*/
class Solution {
  public:
    bool isCircular(Node *head) {
        
        if(head == NULL || head -> next == head) return true;
        
        Node* temp = head;
        while(temp -> next != head) {
            if(temp -> next == NULL) return false;
            temp = temp -> next;
        }
        return true;
        
    }
};
