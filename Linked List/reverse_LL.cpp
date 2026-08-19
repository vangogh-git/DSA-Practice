// time complexity  : O(n)
// space complexity : O(1)
// iterative approach

/* Structure of Linked List Node
class Node {
 public:
    int data ;
    Node *next ;

    Node(int x) {
        data = x ;
        next = nullptr ;
    }
};
*/

class Solution {
  public:
    Node* reverseList(Node* head) {
        
        // iterative 
        Node* prev = NULL;
        Node* next = NULL;
        Node* curr = head;
        while(curr != NULL) {
            next = curr -> next;
            curr -> next = prev;
            prev = curr;
            curr = next;
        }
        
        return prev;
        
    }
};

/* Structure of Linked List Node
class Node {
 public:
    int data ;
    Node *next ;

    Node(int x) {
        data = x ;
        next = nullptr ;
    }
};
*/

// time complexity  : O(n)
// space complexity : O(n) // recursion call stack storage
// recursive approach

class Solution {
    private: 
    Node* solve(Node* prev , Node* curr) {
        // first we create base case
        if(curr == nullptr) {
            return prev;
        }
        else {
            Node* temp = curr -> next;
            curr -> next = prev;
            return solve(curr , temp);
        }
    }
  public:
    Node* reverseList(Node* head) {
        
        // iterative 
        Node* prev = NULL;
        Node* curr = head;
        // while(curr != NULL) {
        //     next = curr -> next;
        //     curr -> next = prev;
        //     prev = curr;
        //     curr = next;
        // }
        
        return solve(prev , curr);
        
        //return prev;
        
    }
};
