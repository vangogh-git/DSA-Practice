// t.c : O(n)
// s.c : O(h)

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
    private:
    TreeNode* minVal(TreeNode* root) {
        if(root == NULL) return NULL;
        if(root -> left == NULL) return root;
        else {
            return minVal(root->left);
        }
    }
public:
    TreeNode* deleteNode(TreeNode* root, int key) {
        if(root == NULL) {
            return NULL;
        }
        if(root->val == key) {
            // 0 child
            if(root->left == NULL && root->right == NULL) {
                delete root;
                return nullptr;
            }
            // 1 child
            if(root->left != NULL && root->right == NULL) {
                TreeNode* temp = root -> left;
                delete root;
                return temp;
            }
            if(root->left == NULL && root->right != NULL) {
                TreeNode* temp = root -> right;
                delete root;
                return temp;
            }
            // 2 child
            if(root->left != NULL && root->right != NULL) {
                int mini = (minVal(root->right))->val;
                root -> val = mini;
                root -> right = deleteNode(root->right , mini);
                return root;
            }
        }
        else if(root->val < key) {
            // move right of the tree
            root->right = deleteNode(root->right,key);
            return root;
        }
        else if(root->val > key) {
            // move to the left of the tree
            root->left = deleteNode(root->left,key);
            return root;
        }
        return root;
    }
};
