// t.c : O(n)
// s.c : O(h)

/* Structure of a Binary Search Tree node
class Node {
public:
    int data;
    Node* left;
    Node* right;

    Node(int val) {
        data = val;
        left = right = nullptr;
    }
}; */

class Solution {
    private:
    bool solve(Node* root , int mini , int maxi) {
        if(root == NULL) return true;
        if(root->data > mini && root->data < maxi) {
            bool left = solve(root->left,mini ,root->data);
            bool right = solve(root->right , root->data , maxi);
            return left&&right;
        }
        else {
            return false;
        }
    }
  public:
    bool isBST(Node* root) {
        int mini = INT_MIN;
        int maxi = INT_MAX;
        return solve(root , mini , maxi);
        
    }
};
