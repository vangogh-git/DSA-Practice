// time complexity : O(n+m)
// space complexity : O(n)
// brute force Approach --- Using hashmap


/* Structure of Linked List Node
class Node {
public:
    int data;
    Node* next;

    Node(int x) {
        data = x;
        next = nullptr;
    }
};*/

class Solution {
  public:
    Node* intersectPoint(Node* head1, Node* head2) {
        
        if(head1 == NULL || head2 == NULL) return NULL;
        
        unordered_map<Node*,int> freq;
        
        Node* c1 = head1;
        Node* c2 = head2;
        while(c1 != nullptr) {
            freq[c1]++;
            c1 = c1 -> next;
        }
        while(c2 != nullptr) {
            freq[c2]++;
            if(freq[c2] > 1) {
                return c2;
            }
            c2 = c2 -> next;
        }
        return NULL;
    }
};

// time complexity: O(n+m)
// space complexity : O(1)
// Optimized Approach

/* Structure of Linked List Node
class Node {
public:
    int data;
    Node* next;

    Node(int x) {
        data = x;
        next = nullptr;
    }
};*/

class Solution {
  public:
    Node* intersectPoint(Node* head1, Node* head2) {
        
        if(head1 == NULL || head2 == NULL) NULL;
        
        Node* t1 = head1;
        Node* t2 = head2;
        int n1 = 0;
        int n2 = 0;
        
        while(t1 != NULL) {
            t1 = t1 -> next;
            n1++;
        }
        
        while(t2 != NULL) {
            t2 = t2 -> next;
            n2++;
        }
        
        t1 = head1;
        t2 = head2;
        
        int d = abs(n1 - n2);
        
        if(n1 > n2) {
            while(d != 0) {
                t1 = t1 -> next;
                d--;
            }
        }
        else {
            while(d != 0) {
                t2 = t2 -> next;
                d--;
            }
        }
        
        while(t1 != NULL && t2 != NULL) {
            if(t1 == t2) {
                return t1;
            }
            
            t1 = t1 -> next;
            t2 = t2 -> next;
        }
        
        return NULL;
    }
};
