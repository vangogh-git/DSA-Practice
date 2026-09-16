// time complexity : O(n)
// space complexity : O(n)
// Using HashMap Approach

/* Structure of Linked List Node
class Node {
  public:
    int data;
    Node* next;
    Node* random;

    Node(int x) {
        data = x;
        next = random = nullptr;
    }
};*/

class Solution {
  public:
    Node* cloneLinkedList(Node* head) {
        
        unordered_map<Node*, Node*> clone;
        Node* temp = head;
        while(temp != NULL) {
            Node* newNode = new Node(temp->data);
            clone[temp] = newNode;
            temp = temp -> next;
        }
        
        temp = head;
        while(temp!= NULL) {
            clone[temp] -> next = clone[temp -> next];
            clone[temp] -> random = clone[temp -> random];
            temp = temp -> next;
        }
        
    return clone[head];
    }
};

// time complexity : O(n)
// space complexity : O(1)
// Optimized Solution

/* Structure of Linked List Node
class Node {
  public:
    int data;
    Node* next;
    Node* random;

    Node(int x) {
        data = x;
        next = random = nullptr;
    }
};*/

class Solution {
  public:
    Node* cloneLinkedList(Node* head) {
        
        Node* temp = head;
        while(temp != NULL) {
            Node* next = temp -> next;
            temp -> next = new Node(temp -> data);
            temp -> next -> next = next;
            temp = next;
        }
        
        temp = head;
        while(temp != NULL) {
           if(temp->random == NULL) temp -> next -> random = NULL;
           else temp -> next -> random = temp -> random -> next;
            temp = temp -> next -> next;
        }
        
        temp = head;
        Node* cloneHead = head -> next;
        while(temp != NULL) {
            Node* clone = temp -> next;
            temp -> next = clone -> next;
            if(clone -> next != NULL) {
                clone -> next = clone -> next -> next;
            }
            
            temp = temp -> next;
        }
        
        return cloneHead;
    }
};
