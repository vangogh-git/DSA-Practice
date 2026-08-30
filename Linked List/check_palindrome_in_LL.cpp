// time complexity : O(n)
// space complexity : O(1)
// Brute Force Approach

/*
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
    bool isPalindrome(Node *head) {
        
        if(head == NULL) return false;
        if(head -> next == head || head -> next == NULL) return true;
        
        int n = 0;
        Node* temp = head;
        while(temp != nullptr) {
            temp = temp -> next;
            n++;
        }
        
        temp = head;
        int cnt = 1;
        while(cnt != n/2) {
            temp = temp -> next;
            cnt++;
        }
        
        Node* head2 = NULL;
        if(n&1) {
            // odd
            head2 = temp -> next -> next;
            temp -> next -> next = NULL;
            temp -> next = NULL;
        }
        
        else {
            // even
            head2 = temp -> next;
            temp -> next = NULL;
        }
        
        Node* prev = NULL;
        Node* curr = head2;
        while(curr != NULL) {
            Node* next = curr -> next;
            curr -> next = prev;
            prev = curr;
            curr = next;
        }
        
        head2 = prev;
        
        // now we compare
        Node* p1 = head;
        Node* p2 = head2;
        while(p1 != NULL && p2 != NULL) {
            if(p1 -> data != p2 -> data) {
                return false;
            }
            p1 = p1 -> next;
            p2 = p2 -> next;
        }
          
        return true;
    }
};

// time complexity : O(n)
// space complexity : O(1)
// Optimal Approach : fast and slow pointer

/*
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
    bool isPalindrome(Node *head) {
        
        if(head == NULL) return false;
        if(head -> next == NULL) return true;
        
        Node* slow = head;
        Node* fast = head;
        
        while(fast != NULL && fast -> next != NULL) {
            slow = slow -> next;
            fast = fast -> next -> next;
        }
        
        Node* head2 = NULL;
        
        if(fast == NULL) {
            //even wala case
            head2 = slow;
        }
        else {
            // odd wala case
            head2 = slow -> next;
        }
        
        
        Node* prev = NULL;
        Node* curr = head2;
        while(curr != NULL) {
            Node* next = curr -> next;
            curr -> next = prev;
            prev = curr;
            curr = next;
        }
        
        head2 = prev;
        
        // now we compare
        Node* p1 = head;
        Node* p2 = head2;
        while(p1 != NULL && p2 != NULL) {
            if(p1 -> data != p2 -> data) {
                return false;
            }
            p1 = p1 -> next;
            p2 = p2 -> next;
        }
          
        return true;
    }
};
