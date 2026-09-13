// time complexity : O(n*k) where k is the number of linked list and n = total number of nodes in a Linked List
// space complexity : O(k) // recursion stack
// Brute Force Approach

/* Linked List Node Structure
class Node {
  public:
    int data;
    Node* next;
    Node(int x){
        data = x;
        next = nullptr;
    }
};
*/
class Solution {
    private: 
    Node* merge(Node* &head1 , Node* &head2) {
        Node* temp1 = head1;
        Node* temp2 = head2;
        
        Node* newNode = new Node(-1);
        Node* t = newNode;
        
        while(temp1 != NULL && temp2 != NULL) {
           if(temp1 -> data <= temp2 -> data) {
               t -> next = temp1;
               temp1 = temp1 -> next;
           } 
           else {
                t -> next = temp2;
                temp2 = temp2 -> next;   
           }
           t = t -> next;
        }
        
        while(temp1 != NULL) {
            t -> next = temp1;
            temp1 = temp1 -> next;
            t = t -> next;
        }
        
        while(temp2 != NULL) {
            t -> next = temp2;
            temp2 = temp2 -> next;
            t = t -> next;
        }
        
        return newNode -> next;
    }
    void solve(vector<Node*>& arr) {
        if(arr.size() == 1) {
            return ;
        }
        else {
            Node* second = arr.back();
            arr.pop_back();
            Node* first = arr.back();
            arr.pop_back();
            Node* head = merge(first , second);
            arr.push_back(head);
            solve(arr);
        }
    }
  public:
    Node* mergeKLists(vector<Node*>& arr) {
        
        solve(arr);
        return arr[0];
        
    }
};

// time complexity : O(n log k) where k is the number of linked list and n = total number of nodes in a Linked List
// space complexity : O(log k) // recursion stack
// Better Approach


/* Linked List Node Structure
class Node {
  public:
    int data;
    Node* next;
    Node(int x){
        data = x;
        next = nullptr;
    }
};
*/
class Solution {
    private: 
    Node* merge(Node* &head1 , Node* &head2) {
        Node* temp1 = head1;
        Node* temp2 = head2;
        
        Node* newNode = new Node(-1);
        Node* t = newNode;
        
        while(temp1 != NULL && temp2 != NULL) {
           if(temp1 -> data <= temp2 -> data) {
               t -> next = temp1;
               temp1 = temp1 -> next;
           } 
           else {
                t -> next = temp2;
                temp2 = temp2 -> next;   
           }
           t = t -> next;
        }
        
        while(temp1 != NULL) {
            t -> next = temp1;
            temp1 = temp1 -> next;
            t = t -> next;
        }
        
        while(temp2 != NULL) {
            t -> next = temp2;
            temp2 = temp2 -> next;
            t = t -> next;
        }
        
        return newNode -> next;
    }
    void solve(vector<Node*>& arr) {
        if(arr.size() == 1) {
            return ;
        }
        else {
            Node* head = merge(arr[0] , arr[1]);
            arr.erase(arr.begin());
            arr.erase(arr.begin());
            arr.push_back(head);
            solve(arr);
        }
    }
  public:
    Node* mergeKLists(vector<Node*>& arr) {
        
        solve(arr);
        return arr[0];
        
    }
};
