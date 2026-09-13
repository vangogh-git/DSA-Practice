// time complexity:  O(max(n,m))
// space complexity : O(1)
// Brute Force Approach

/* Node Structure
class Node {
  public:
    int data;
    Node* next;
    Node(int key) {
        data = key;
        next = nullptr;
    }
};
*/
class Solution {
  public:
    int multiplyTwoLists(Node* first, Node* second) {
        
        long long int num1 = 0;
        long long int num2 = 0;
        
        long long int mod = 1000000007;
        
        Node* temp1 = first;
        Node* temp2 = second;
        
        while(temp1 != NULL) {
            num1 = ((num1 * 10) + temp1 -> data) % mod;
            temp1 = temp1 -> next;
        }
        
        while(temp2 != NULL) {
            num2 = ((num2 * 10) + temp2 -> data) % mod;
            temp2 = temp2 -> next;
        }
        
        return (num1 * num2) % mod;
    }
};
