// time complexity : O(nlogn)
// space complexity : O(log n)

/* Structure of linked list Node
class Node {
public:
    int data;
    Node* next;

    Node(int x) {
        data = x;
        next = nullptr;
    }
};*/
class Solution {
    private:
    void findPartition(Node* &pivot , Node* &head) {
        
        Node* prev = head;
        Node* curr = head -> next;
        
        while(curr != NULL) {
            Node* next = curr -> next;
            if(curr -> data >= pivot -> data){
                prev = curr;
                curr = next;
            }
            else {
                prev -> next = curr -> next;
                curr -> next = head;
                head = curr;
                curr = next;
            }
        }
    }
    
    Node* merge(Node* head1 , Node* head2) {
        Node* newN = new Node(-1);
        Node* temp = newN;

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

        return newN -> next;
    }
  public:
    Node* quickSort(Node* head) {
        
        if(head == NULL || head -> next == NULL) return head;
        
        Node* pivot = head;
        findPartition(pivot , head);
        
        Node* leftHead = head;
        Node* rightHead = pivot -> next;
        pivot -> next = NULL;
        
        leftHead = quickSort(leftHead);
        rightHead = quickSort(rightHead);
        
        // connect leftPart -> rightPart
        return merge(leftHead , rightHead);
    }
};
