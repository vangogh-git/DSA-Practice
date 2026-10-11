// t.c : O(n)
// s.c : O(n)

/* Definition for Node
class Node {
public:
    int data;
    Node* left;
    Node* right;

    Node(int val) {
        data = val;
        left = right = nullptr;
    }
};
*/

class Solution {
    private:
    void solve(Node* root , int level , unordered_map<int,Node*> &mp) {
        if(root == NULL) {
            return ;
        }
        
        solve(root->left , level+1, mp);
        solve(root->right , level+1, mp);
        if(root->left == NULL && root->right == NULL) {
            mp[level] = root;
        }
    }
  public:
    bool check(Node* root) {
        unordered_map<int,Node*> mp;
        solve(root,0,mp);
        if(mp.size() > 1) return false;
        else return true;
    }
};
