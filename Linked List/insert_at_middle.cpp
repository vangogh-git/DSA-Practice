/* Strucutre of a link list node
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
    Node *insertInMiddle(Node *head, int x) {
        
        if(head == NULL) return new Node(x);
        
        int n = 0;
        Node* temp = head;
        while(temp != NULL) {
            n++;
            temp = temp -> next;
        }
        
        temp = head;
        // we find middle pos
        int pos = (n+1)/2;
        for(int i=1 ; i<pos ; i++) {
            temp = temp -> next;
        }
        
        Node* insertNode = new Node(x);
        insertNode -> next = temp -> next;
        temp -> next = insertNode;
        
        return head;
    }
};
