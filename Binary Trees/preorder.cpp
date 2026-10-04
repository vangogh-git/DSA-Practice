// time complexity : O(n)
// space complexity : O(h) // recursive call stack where h is the height of the tree

/* Structure of Tree Node
class Node {
  public:
    int data;
    Node* left;
    Node* right;

    Node(int val) {
        data = val;
        left = nullptr;
        right = nullptr;
    }
};*/

class Solution {
    private:
    void solve(Node* &root , vector<int> &ans) {
        if(root == NULL) {
            return ;
        }
        else {
            ans.push_back(root->data);
            solve(root->left,ans);
            solve(root->right,ans);
        }
    }
  public:
    vector<int> preOrder(Node* root) {
        
        vector<int> ans;
        solve(root,ans);
        return ans;
        
    }
};
