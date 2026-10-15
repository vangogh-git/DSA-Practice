// t.c : O(n)
// s.c : O(h)

/* structure of binary tree node
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
};
*/
class Solution {
    int maxi = INT_MIN;
    private:
    int solve(Node* root) {
        if(root == NULL) {
            return 0;
        }
        else {
            int left = solve(root->left);
            int right = solve(root->right);
            int sum = left + right + root->data;
            if(sum > maxi) {
                maxi = sum;
            }
            return sum;
        }
    }
  public:
    int maxSubtreeSum(Node* root) {
        int ans = solve(root);
        return maxi;
    }
};
