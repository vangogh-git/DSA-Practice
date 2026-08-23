// Time Complexity : O(n)
// Space Complexity : O(1)

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */

class Solution {
public:
    ListNode* middleNode(ListNode* head) {
        
        if(head == NULL) return NULL;
        if(head -> next == NULL) return head;

        ListNode* curr = head;
        int n = 0;
        while(curr != nullptr) {
            n++;
            curr = curr -> next;
        }

        int pos;
        if(n & 1) {
            // odd
            pos = (n+1)/2;
        }
        else{
            // even
            pos = (n/2)+1;
        }

        int cnt = 1;
        curr = head;
        while(cnt < pos) {
            curr = curr -> next;
            cnt++;
        }

        return curr;
    }
};
