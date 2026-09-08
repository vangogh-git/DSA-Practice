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
