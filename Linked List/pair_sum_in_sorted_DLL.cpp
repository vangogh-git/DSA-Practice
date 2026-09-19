// Brute Force Approach
// Time complexity : O(n)
// space complexity : O(1)

/* Structure of Doubly Linked List Node
class Node {
  public:
    int data;
    Node *next;
    Node *prev;

    Node(int val) {
        data = val;
        next = nullptr;
        prev = nullptr;
    }
}; */

class Solution {
    Node* findVal(int val , Node* &head) {
        
        Node* temp = head;
        while(temp != NULL) {
            if(temp -> data == val) {
                break;
            }
            temp = temp -> next;
        }
        return temp;
    }
  public:
    vector<vector<int>> givenSumPairs(Node* head, int target) {
        
        vector<vector<int>> output;
        Node* curr = head;
        
        while(curr != NULL && curr->data <= target) {
            
            if(target - curr->data < curr -> data) break;
            
            Node* val = findVal(target - curr->data , curr->next);
            
            if(val != NULL) {
                vector<int> pair;
                pair.push_back(curr->data);
                pair.push_back(val->data);
                output.push_back(pair);
            }
            
            curr = curr -> next;
        }
        
        return output;
        
    }
};

// time complexity : O(n)
// space complexity : O(1)
// Optimized Approach

/* Structure of Doubly Linked List Node
class Node {
  public:
    int data;
    Node *next;
    Node *prev;

    Node(int val) {
        data = val;
        next = nullptr;
        prev = nullptr;
    }
}; */

class Solution {
  public:
    vector<vector<int>> givenSumPairs(Node* head, int target) {
       
        vector<vector<int>> output;
        Node* tail = head;
        while(tail -> next != NULL) {
            tail = tail -> next;
        }
        
        Node* left = head;
        Node* right = tail;
        
        while(left != right && left->prev != right) {
            
            if(left->data + right -> data == target) {
                output.push_back({left->data,right->data});
                left = left -> next;
                right = right -> prev;
            }
            else if(left->data + right -> data > target) {
                right = right -> prev;
            }
            else {
                left = left -> next;
            }
        }
        
        return output;
        
    }
};
