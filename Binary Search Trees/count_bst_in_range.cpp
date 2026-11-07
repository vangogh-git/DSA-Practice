//t.c : O(n)
// s.c : O(h)

/* Binary Tree Node Structure
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
    void solve(Node* root , int l , int h , int &cnt) {
        if(root == NULL) {
            return ;
        }
        if(root->data >= l && root->data <= h) {
            cnt++;
        }
        
        solve(root->left,l,h,cnt);
        solve(root->right,l,h,cnt);
    }
  public:
    int getCount(Node *root, int l, int h) {
        
        int cnt = 0;
        solve(root,l,h,cnt);
        return cnt;
    }
};
