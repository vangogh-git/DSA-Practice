// time complexity : O(n^2)
// space complexity : O(1)

#include <bits/stdc++.h> 
/***********************************************

    Following is the class structure of the Node class:

    class DLLNode
    {
        public:
        int data;
        DLLNode *next;
        DLLNode *prev;
    };

***********************************************/

int countTriplets(DLLNode* head, int x)
{


    DLLNode* tail = head;
    while(tail -> next != NULL) {
        tail = tail -> next;
    }

    int cnt = 0;
    DLLNode* curr = head;

    while(curr != NULL) {

        int val = x - curr -> data;
        DLLNode* left = curr->next;
        DLLNode* right = tail;

        while(left != NULL && right != NULL && left != right && left -> prev != right) {

            if(left->data + right->data == val) {
                cnt++;
                left = left -> next;
                right = right -> prev;
            }
            else if(left->data + right->data > val) {
                right = right -> prev;
            }
            else {
                left = left -> next;
            }
        } 
        curr = curr -> next;
    }

    return cnt;
}  
