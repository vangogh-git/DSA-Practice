// time complexity : O(n+m log(n+m))
// space complexity : O(n+m)
// brute force approach

/*
class Node {
 public:
    int data;
    Node *next;

    Node(int x) {
        data = x;
        next = NULL;
    }
};
*/

class Solution {
  public:
    Node* sortedMerge(Node* head1, Node* head2) {
        vector<int> arr;
        Node* temp1 = head1;
        while(temp1 != NULL) {
            arr.push_back(temp1->data);
            temp1 = temp1 -> next;
        }
        temp1 = head1;
        Node* temp2 = head2;
        while(temp2 != NULL) {
            arr.push_back(temp2->data);
            temp2 = temp2 -> next;
        }
        temp2 = head2;
        
        sort(arr.begin(),arr.end());
        
        Node* last;
        int i=0;
        while(temp1 != NULL) {
            temp1 -> data = arr[i];
            i++;
            if(temp1 -> next == NULL) last = temp1;
            temp1 = temp1 -> next;
        }
        
        while(temp2 != NULL) {
            temp2 -> data = arr[i];
            i++;
            temp2 = temp2 -> next;
        }
        
        last -> next = head2;
        return head1;
    }
};

// time complexity : O(n+m)
// space complexity:  O(1)
// Optimized Approach


/*
class Node {
 public:
    int data;
    Node *next;

    Node(int x) {
        data = x;
        next = NULL;
    }
};
*/

class Solution {
  public:
    Node* sortedMerge(Node* head1, Node* head2) {
        
        
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
};
