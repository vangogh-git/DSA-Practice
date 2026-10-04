// time complexity : O(n)
// space complexity : O(h) recursive call stack

/* Structrue of Binary Tree Node
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
    void solve(Node* root , int height , int &maxi) {
        if(root == NULL) {
            if(height > maxi) {
                maxi = height;
            }
            return ;
        }
        else {   
            solve(root->left, height+1, maxi);
            solve(root->right, height+1, maxi);
        }
    }
  public:
    int height(Node* root) {
        int maxi = ;
        solve(root, 0 , maxi);
        return maxi-1;
    }
};
