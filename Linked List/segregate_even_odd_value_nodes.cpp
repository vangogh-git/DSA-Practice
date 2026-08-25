// time complexity : O(n)
// space complexity : O(n)
// using extra space not optimal -> brute force solution

/* Structure of Linked List Node
class Node {
  public:
    int data;
    Node* next;

    Node(int val) {
        data = val;
        next = nullptr;
    }
}; */
class Solution {
  public:
    Node* divide(Node* head) {
        
        if(head == NULL || head -> next == NULL) return head;
        
        Node* temp = head;
        vector<int> evens;
        vector<int> odds;
        
        while(temp != NULL) {
            if(temp -> data % 2 == 0) {
                evens.push_back(temp -> data);
            }
            else {
                odds.push_back(temp -> data);
            }
            temp = temp -> next;
        }
        
        temp = head;
        for(int i=0 ; i<evens.size() ; i++) {
            temp -> data = evens[i];
            temp = temp -> next;
        }
        for(int i=0 ; i<odds.size() ; i++) {
            temp -> data = odds[i];
            temp = temp -> next;
        }
        
        return head;
        
    }
};
