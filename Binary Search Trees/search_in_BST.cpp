// t.c : O(n)
// s.c : O(h)
// using recursion

class Solution {
  public:
    bool search(Node* root, int key) {
        
        if(root == NULL) {
            return false;
        }
        if(root->data == key) {
            return true;
        }
        else {
            if(key < root->data) {
                return search(root->left,key);
            }
            if(key > root->data) {
                return search(root->right,key);
            }
        }
        
    }
};
