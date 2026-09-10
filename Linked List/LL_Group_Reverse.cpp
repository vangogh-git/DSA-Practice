// time complexity : O(n)
// space complexity : O(1)
// optimized Approach --- v.imp question

/* Structure of linked list Node
class Node {
  public:
    int data;
    Node* next;

    Node(int x){
        data = x;
        next = nullptr;
    }
};*/

class Solution {
    Node* prev = NULL;
    private: Node* findkthNode(Node* &temp , int k) {
        int cnt = 1;
        Node* kthNode = temp;
        while(cnt != k && kthNode != NULL) {
            kthNode = kthNode -> next;
            cnt++;
        }
        return kthNode;
    }
    
    void reverse(Node* &temp) {
        
        prev = NULL;
        Node* curr = temp;
        while(curr != NULL) {
            Node* next = curr -> next;
            curr -> next = prev;
            prev = curr;
            curr = next;
        }
    }
  public:
    Node *reverseKGroup(Node *head, int k) {
        
        Node* temp = head;
        Node* prevNode = NULL;
        while(temp != NULL) {
            Node* kthNode = findkthNode(temp , k);
            if(kthNode == NULL) {
                reverse(temp);
                if(prevNode) prevNode -> next = prev;
                else head = prev;
                break;
            }
            Node* nextNode = kthNode -> next;
            kthNode -> next = NULL;
            reverse(temp);
            if(temp == head) {
                head = kthNode;
            }
            else {
                prevNode -> next = kthNode;
            }
            prevNode = temp;
            temp = nextNode;
        }
        
        return head;
    }
};
