// Time Complexity : O(n)
// Space Complexity : O(1)
// Brute Force Approach

/* Structure of Linked List Node
class Node {
  public:
    int data;
    Node* next;
    Node(int x) {
        data = x;
        next = nullptr;
    }
}; */

class Solution {
  public:
    int getKthFromLast(Node* head, int k) {
        
        if(head == NULL) return -1;
        
        int n = 0;
        Node* temp = head;
        while(temp != NULL) {
            n++;
            temp = temp -> next;
        }
        
        if(k > n) return -1;
        
        // total length of Ll
        temp = head;
        int pos = n-k+1;
        int cnt = 1;
        while(cnt < pos) {
            temp = temp -> next;
            cnt++;
        }
        return temp->data;
    }
};

// Optimal Solution
// Time Complexity : O(n)
// Space Complexity: O(1)

/* Structure of Linked List Node
class Node {
  public:
    int data;
    Node* next;
    Node(int x) {
        data = x;
        next = nullptr;
    }
}; */

class Solution {
  public:
    int getKthFromLast(Node* head, int k) {
        
        if(head == NULL) return NULL;
        if(head -> next == NULL && k != 1) return -1;
        
        Node* curr = head;
        Node* prev = head;
        int cnt = 1;
        while(cnt <= k) {
            if(curr == NULL) return -1;
            curr = curr -> next;
            cnt++;
        }
        
        while(curr != NULL) {
            prev = prev -> next;
            curr = curr -> next;
        }
        return prev->data;
        
    }
};
