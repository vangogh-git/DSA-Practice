// t.c : O(n)
// s.c : O(h)

/* A binary tree node has data, pointer to left child
   and a pointer to right child
struct Node
{
    int data;
    Node* left;
    Node* right;
}; */

// Class Solution
class Solution {
    private: 
    void solve(Node* root , int &cnt) {
        if(root == NULL) {
            return ;
        }
        else {
            solve(root->left,cnt);
            solve(root->right,cnt);
            
            if(root->left == NULL && root->right == NULL) {
                cnt++;
            }
        }
    }
  public:
    // Function to count the number of leaf nodes in a binary tree.
    int countLeaves(Node* root) {
        
        int cnt = 0;
        solve(root,cnt);
        return cnt;
    }
};
