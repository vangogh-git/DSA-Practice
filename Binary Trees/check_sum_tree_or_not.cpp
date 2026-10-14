// t.c : O(n)
// s.c : O(h) where h is the height of the recursive stack

/* Definition for Node
class Node {
public:
    int data;
    Node *left;
    Node *right;

    Node(int val) {
        data = val;
        left = right = nullptr;
    }
};
*/

class Solution {
    private: 
    pair<bool,int> solve(Node* root) {
        if(root == NULL) {
            return make_pair(true,0);
        }
        if(root->left==NULL && root->right==NULL) {
            return make_pair(true,root->data);
        }
        
        else {
            pair<bool,int> ans;
            pair<bool,int> left = solve(root->left);
            pair<bool,int> right = solve(root->right);

            bool check = (left.second + right.second == root->data);
            if(left.first && right.first && check) {
                ans.first = true;
            }
            else {
                ans.first = false;
            }
            int sum = left.second + right.second + root->data;
            ans.second = sum;
            return ans;
        }
    }
  public:
    bool isSumTree(Node* node) {
        if(node == NULL) return true;
        if(node -> left == NULL && node -> right == NULL) {
            return true;
        }
        return solve(node).first;
    }
};
