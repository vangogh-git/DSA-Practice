// t.c : O(n)
// s.c : O(h)

/* Structure of a Binary Search Tree node
class Node {
public:
    int data;
    Node* left;
    Node* right;

    Node(int val) {
        data = val;
        left = right = nullptr;
    }
}; */

class Solution {
    private:
    void inorder(Node* root , Node* &temp) {
        if(root == NULL) return ;
        
        inorder(root->left , temp);
        temp -> right = root;
        root -> left = NULL;
        temp = root;
        inorder(root->right , temp);
    }
  public:
    Node *flattenBST(Node *root) {
        
        Node* newNode = new Node(-1);
        Node* temp = newNode;
        inorder(root,temp);
        temp -> right = NULL;
        return newNode->right;

    }
};
