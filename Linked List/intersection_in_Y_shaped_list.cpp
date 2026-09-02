// time complexity : O(n+m)
// space complexity : O(n+m)
// brute force Approach --- Using hashmap


/* Structure of Linked List Node
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
  public:
    Node* intersectPoint(Node* head1, Node* head2) {
        
        if(head1 == NULL || head2 == NULL) return NULL;
        
        unordered_map<Node*,int> freq;
        
        Node* c1 = head1;
        Node* c2 = head2;
        while(c1 != nullptr) {
            freq[c1]++;
            c1 = c1 -> next;
        }
        while(c2 != nullptr) {
            freq[c2]++;
            if(freq[c2] > 1) {
                return c2;
            }
            c2 = c2 -> next;
        }
        return NULL;
    }
};
