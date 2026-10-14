// t.c : O(n)
// s.c : O(h) where h is the height of the recursive stack
// brute force - my approach
/* Structure for Tree Node
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
    private:
    int solve(Node* root , int &sum) {
        if(root == NULL) {
            return 0;
        }
            else {
                int left = solve(root->left , sum);
                int right = solve(root->right , sum);
                sum = root->data + left + right;
                root->data = left+right;
                return sum;
            }
    }
  public:
    void toSumTree(Node *root) {
        
        int sum = 0;
        int res = solve(root , sum);
        return ;
    }
};
