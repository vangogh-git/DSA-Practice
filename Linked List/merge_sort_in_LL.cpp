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


// time complexity : O(n logn)
// space complexity : O(1)
// optimized Approach

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
    private:
    Node* findMiddle(Node* &head) {
        Node* slow = head;
        Node* fast = head -> next;
        while(fast != NULL && fast-> next != NULL) {
            slow = slow -> next;
            fast = fast -> next -> next;
        }
        return slow;
    }
    
    Node* merge(Node* &head1 , Node* &head2) {
        Node* newNode = new Node(-1);
        Node* temp = newNode;

        Node* temp1 = head1;
        Node* temp2 = head2;
        while(temp1 != NULL && temp2 != NULL) {
            if(temp1 -> data <= temp2 -> data){
                temp -> next = temp1;
                temp1 = temp1 -> next;
            } 
            else {
                temp -> next = temp2;
                temp2 = temp2 -> next;
            }
            temp = temp -> next;
        }

        while(temp1 != NULL) {
            temp -> next = temp1;
            temp = temp -> next;
            temp1 = temp1 -> next;
        }

        while(temp2 != NULL) {
            temp -> next = temp2;
            temp = temp -> next;
            temp2 = temp2 -> next;
        }
        
        return newNode -> next;
    }
  public:
    Node* mergeSort(Node* head) {
        
        if(head == NULL || head-> next == NULL) return head;
        
        Node* middle = findMiddle(head);
        Node* leftHead = head;
        Node* rightHead = middle -> next;
        middle -> next = NULL;
        leftHead = mergeSort(leftHead);
        rightHead = mergeSort(rightHead);
        return merge(leftHead , rightHead);
        
    }
};
