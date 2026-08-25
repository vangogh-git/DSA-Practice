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

// Time Complexity : O(n)
// Space Complexity : O(1)
// Optimized Solution

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
        
        Node* odd = new Node(-1);
        Node* even = new Node(-1);
        
        Node* oddhead = odd;
        Node* evenhead = even;
        
        Node* pointer = head;
        while(pointer != NULL) {
            if(pointer->data % 2 != 0) {
                odd -> next = pointer;
                odd = odd -> next;
            }
            else {
                even -> next = pointer;
                even = even -> next;
            }
            pointer = pointer -> next;
        }
        
        even -> next = NULL;
        odd -> next = NULL;
        
        even -> next = oddhead -> next;
        return evenhead -> next;
        
    }
};
