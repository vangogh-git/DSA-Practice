// t.c : O(n)
// s.c : O(h) -> recursive stack calls where h is the height of the tree

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
    void solve(Node* &root , vector<int> &ans) {
        if(root == NULL) {
            return ;
        }
        else {
            solve(root->left,ans);
            solve(root->right,ans);
            ans.push_back(root->data);
        }
    }
  public:
    vector<int> postOrder(Node* root) {
        
        vector<int> ans;
        solve(root,ans);
        return ans;
    }
};
