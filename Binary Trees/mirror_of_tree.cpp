// time complexity : O(n)
// space complexity : O(h) recursive call stack h is the height of the tree


/* Structure of Binary Tree Node
class Node {
  public:
    int data;
    Node *left;
    Node *right;
    Node(int val) {
        data = val;
        left = right = nullptr;
    }
};*/

class Solution {
  public:
    void mirror(Node* root) {
            if(root == NULL) {
                return ;
            }
            
            mirror(root->left);
            mirror(root->right);
            
            Node* temp = root -> left;
            root -> left = root -> right;
            root -> right = temp;
    }
};
