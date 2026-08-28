// Time Complexity : O(n)
// Space Complexity : O(n)

/* Structure of linked list Node
class Node {
public:
    int data;
    Node *next;
    Node(int x) {
        data = x;
        next = nullptr;
    }
};*/
class Solution {
  public:
    Node* removeDuplicates(Node* head) {
        
        if(head == NULL) return NULL;
        if(head -> next == NULL) return head;
        
        unordered_map<int,bool> found;
        
        Node* prev = NULL;
        Node* curr = head;
        
        while(curr != NULL) {
            if(found[curr->data] == true) {
                prev ->next = curr -> next;
                curr = curr -> next;
            }
            else{
                found[curr -> data] = true;
                prev = curr;
                curr = curr -> next;
            }
        }
        
        return head;
        
    }
};
