// t.c : O(n)
// s.c : O(h)
// brute force approach

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
};
*/

class Solution {
  public:
    Node* findLCA(Node* root, Node* n1, Node* n2) {
        
        if(root == NULL) return NULL;
        else {
            Node* left = findLCA(root->left,n1,n2);
            Node* right = findLCA(root->right , n1,n2);
            
            if(root->data == n1->data || root->data == n2->data) {
                return root;
            }
            
            if(left != NULL && right != NULL) {
                return root;
            }
            else if(left == NULL && right !=NULL) {
                return right;
            }
            else if(left != NULL && right == NULL) {
                return left;
            }
            else {
                return NULL;
            }
        }
        
    }
};
