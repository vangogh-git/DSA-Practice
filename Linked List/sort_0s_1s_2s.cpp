// brute force approach --- will hit TLE
// time complexity : O(2n)
// space complexity : O(1)


/* Node is defined as
  class Node {
  public:
    int data;
    Node* next;

    Node(int x) {
        data = x;
        next = nullptr;
    }
};
*/
class Solution {
  public:
    Node* segregate(Node* head) {
        
        int cnt1 = 0 , cnt2 = 0 , cnt0 = 0;
        Node* temp = head;
        while(temp != NULL) {
            if(temp -> data == 0) {
                cnt0++;
            }
            else if(temp -> data == 1) {
                cnt1++;
            }
            else {
                cnt2++;
            }
        }
        
        temp = head;
        while(temp != nullptr) {
            if(cnt0 != 0) {
                temp -> data = 0;
                cnt0--;
            }
            else if(cnt1 != 0) {
                temp -> data = 1;
                cnt1--;
            }
            else {
                temp -> data = 2;
                cnt2--;
            }
            temp = temp -> next;
        }
        
        return head;
        
    }
};

// time complexity : O(n)
// space complexity : O(1)
// optimized approach

/* Node is defined as
  class Node {
  public:
    int data;
    Node* next;

    Node(int x) {
        data = x;
        next = nullptr;
    }
};
*/
class Solution {
  public:
    Node* segregate(Node* head) {
        
        if(head == nullptr || head -> next == nullptr) {
            return head;
        } 
        
        Node* zerohead = new Node(-1);
        Node* zero = zerohead;
        Node* onehead = new Node(-1);
        Node* one = onehead;
        Node* twohead = new Node(-1);
        Node* two = twohead;
        
        Node* temp = head;
        while(temp != NULL) {
            if(temp -> data == 1){
                one -> next = temp;
                one = one -> next;
                
            }
            if(temp -> data == 2){
                two -> next = temp;
                two = two -> next;
            } 
            if(temp -> data == 0){
                zero -> next = temp;
                zero = zero -> next;
            }
            temp = temp -> next;
        }
        
        zero -> next = (onehead -> next) ? onehead -> next : twohead -> next;
        one -> next = twohead -> next;
        two -> next = NULL;
        
        return zerohead->next;
    }
};
