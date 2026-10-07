// time complexity : O(n^2)
// space complexity : O(h)
// Brute Force Approach

/* Structure of binary tree node
class Node {
  public:
    int data;
    Node* left;
    Node* right;

    Node(int val) {
        data = val;
        left = right = nullptr;
    }
};*/

class Solution {
    private:
    int height(Node* root) {
        if(root == NULL) return 0;
        else {
            int l = height(root->left);
            int r = height(root->right);
            return max(l,r)+1;
        }
    }
  public:
    bool isBalanced(Node* root) {
        
        if(root == NULL) {
            return true;
        }
        
        int lh = height(root->left);
        int rh = height(root->right);
        
        if(abs(lh-rh) > 1) return false;
        
        bool l = isBalanced(root -> left);
        bool r = isBalanced(root -> right);
        
        if(!l || !r) return false;
        return true;
        
    }
};
