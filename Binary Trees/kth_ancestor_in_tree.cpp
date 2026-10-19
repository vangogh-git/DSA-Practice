// t.c : O(n)
// s.c : O(h)

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
    Node* solve(Node* root , int &k , int node , int &ans) {
        if(root == NULL) {
            return root;
        }
        if(root->data == node) {
            return root;
        }
        
        else {
            Node* left = solve(root->left,k,node,ans);
            Node* right = solve(root->right,k,node,ans);
            
            if(left != NULL || right != NULL) {
                k--;
                if(k == 0) {
                    ans = root->data;
                }
                return root;
            }
            return NULL;
        }
    }
  public:
    int kthAncestor(Node *root, int k, int node) {
        
        int ans = -1;
        Node* temp = solve(root,k,node,ans);
        return ans;
    }
};
