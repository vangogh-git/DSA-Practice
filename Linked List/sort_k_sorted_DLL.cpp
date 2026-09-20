// t.c : O(n log k) since pop and push operation take log k time
// s.c : O(k)
// optimized approach

/* Structure of a Node of the Doubly Linked List
class Node {
public:
    int data;
    Node *next;
    Node *prev;
    Node(int val)
    {
        data = val;
        this->next = nullptr;
        this->prev = nullptr;
    }
};
*/



class Solution {
    
    class compare {
    public:
    bool operator()(Node* a , Node* b) {
        return a->data > b -> data;
    }
    
};
  public:
    Node* sortKSortedDLL(Node* head, int k) {
        
        if(head == NULL || head -> next == NULL) return head;
        
        
        priority_queue<Node* , vector<Node*> , compare> minheap;
        
        Node* curr = head;
        for(int i=0 ; i<k+1 && curr != NULL ; i++) {
            minheap.push(curr);
            curr = curr -> next;
        }
        
        Node* newNode = new Node(-1);
        Node* temp = newNode;
        while(!minheap.empty()) {
            Node* smallest = minheap.top();
            minheap.pop();
            temp -> next = smallest;
            smallest -> prev = temp;
            temp = temp -> next;
            
            if(curr != NULL) {
                minheap.push(curr);
                curr = curr -> next;
            }
        }
        temp -> next = NULL;
        return newNode -> next;
    }
};
