// time complexity : O(n)
// space complexity : O(h) // recursive call stack where h is the height of the tree

/* Structure of Binary Tree Node
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
    void inorder(Node* &root , vector<int> &ans) {
        if(root == nullptr) {
            return ;
        }
        else {
            inorder(root->left , ans);
            ans.push_back(root->data);
            inorder(root->right , ans);
        }
    }
  public:
    vector<int> inOrder(Node* root) {
        
        vector<int> ans;
        inorder(root , ans);
        return ans;
    }
};
