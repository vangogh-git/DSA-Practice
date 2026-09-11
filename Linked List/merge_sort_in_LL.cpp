// time complexity : O(n logn)
// space complexity : O(n)
// Brute Force Approach


/* Structure of linked list Node
class Node {
public:
    int data;
    Node* next;
    Node(int x){
        data = x;
        next = nullptr;
    }
};*/
class Solution {
  public:
    Node* mergeSort(Node* head) {
        
        vector<int> arr;
        Node* temp = head;
        while(temp != NULL) {
            arr.push_back(temp->data);
            temp = temp -> next;
        }
        temp = head;
        sort(arr.begin() , arr.end());
        for(int i=0 ; i<arr.size() ; i++) {
            temp -> data = arr[i];
            temp = temp -> next;
        }
        return head;
    }
};
