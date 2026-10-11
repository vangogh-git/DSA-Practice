/* Node Structure
class Node {
  public:
    int data;
    Node* left, *right;
    Node(int val) {
        data = val;
        left = right = nullptr;
    }
}; */

class Solution {
    private:
    void leftmost(Node* root, vector<int> &ans) {
        if(root == NULL || (root->left == NULL && root->right == NULL)) {
            return ;
        }
        else {
            ans.push_back(root->data);
            if(root->left) {
                leftmost(root->left,ans);
            }
            else {
                leftmost(root->right,ans);
            }
        }
    }
    
    void leafNode(Node* root , vector<int> &ans) {
        if(root == NULL) {
            return ;
        }
        if(root->left == NULL && root->right== NULL) {
                ans.push_back(root->data);
                return ;
            }
        else {
            leafNode(root->left,ans);
            leafNode(root->right,ans);
        }
    }
    
    void rightmost(Node* root , vector<int> &ans) {
        if(root== NULL || (root->left == NULL && root->right==NULL)) {
            return ;
        }
        else {
            if(root->right){
                rightmost(root->right,ans);
            }
            else {
                rightmost(root->left,ans);
            }
            ans.push_back(root->data);
        }
    }
  public:
    vector<int> boundaryTraversal(Node *root) {
        
        vector<int> ans;
        
        if(root == NULL) return ans; 
        
        if(root->left || root->right) {
            ans.push_back(root->data);
        }
        
        leftmost(root->left,ans);
        leafNode(root,ans);
        rightmost(root->right,ans);
        
        return ans;
    }
};
