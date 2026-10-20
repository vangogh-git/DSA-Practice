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
  public:
    bool isIsomorphic(Node *root1, Node *root2) {
        
        if(root1 == NULL && root2 == NULL) return true;
        if(root1 == NULL || root2 == NULL) return false;
        if(root1->data != root2 -> data) return false;
        
        bool a = isIsomorphic(root1->left, root2->left) && 
        isIsomorphic(root1->right , root2->right);
        bool b = isIsomorphic(root1->right, root2->left) &&
        isIsomorphic(root1->left,root2->right);
        return a || b;
    }
};
