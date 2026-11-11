// t.c : O(n+m log n+m)
// s.c : O(n+m)

/* Structure of a Binary Search Tree node
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
}; */

class Solution {
    private:
    void solve(Node* root , vector<int> &inorder) {
        if(root == NULL) return ;
        
        solve(root->left , inorder);
        inorder.push_back(root->data);
        solve(root->right , inorder);
    }
    
  public:
    vector<int> merge(Node *r1, Node *r2) {
        
        vector<int> inorder1;
        vector<int> inorder2;
        
        solve(r1 , inorder1);
        solve(r2 , inorder2);
        
        vector<int> ans = inorder1;
        for(int i=0 ; i<inorder2.size() ; i++) {
            ans.push_back(inorder2[i]);
        }
        
        sort(ans.begin() , ans.end());
        return ans;
        
    }
};
