// t.c : O(n)
// s.c : O(h)

/* Structure of a Binary Tree Node
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
    void inorder(Node* root , vector<int> &arr) {
        if(root == NULL) {
            return ;
        }
        
        inorder(root->left , arr);
        arr.push_back(root->data);
        inorder(root->right,arr);
    }
  public:
    int kthLargest(Node *root, int k) {
        
        vector<int> arr;
        inorder(root,arr);
        
        return arr[arr.size()-k];
    }
};
