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
