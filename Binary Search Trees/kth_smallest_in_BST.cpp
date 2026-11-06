// t.c : O(n)
// s.c : O(h)

/*
Definition for Node
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
    void inorder(Node* root , int &cnt , int k , int &ans) {
        if(root == NULL) {
            return ;
        }
        else {
            inorder(root->left,cnt,k,ans);
            cnt++;
            if(cnt == k) {
                ans = root->data;
            }
            inorder(root->right,cnt,k,ans);
        }
    }
  public:
    int kthSmallest(Node *root, int k) {
        
        int cnt = 0;
        int ans = -1;
        inorder(root,cnt,k,ans);
        return ans;
    }
};
