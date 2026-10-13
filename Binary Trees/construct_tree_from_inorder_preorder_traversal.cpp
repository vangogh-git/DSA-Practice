// t.c : O(n)
// s.c : O(n) where h is the height of the recursive stack

/* Structure of a Tree Node
class Node {
public:
    int data;
    Node *left;
    Node *right;

    Node(int val) {
        data = val;
        left = right = nullptr;
    }
}; */

class Solution {
    private:
    int findPos(vector<int> &inorder , int &element) {
        for(int i=0 ; i<inorder.size() ; i++) {
            if(inorder[i] == element) {
                return i;
            }
        }
        return -1;
    } 
    Node* solve(vector<int> &inorder, vector<int> &preorder , int &preIndex , int instart , int inend) {
        if(preIndex > preorder.size() || instart > inend) {
            return NULL;
        }
        else {
            int element = preorder[preIndex++];
            Node* root = new Node(element);
            int pos = findPos(inorder , element);
            root->left = solve(inorder , preorder , preIndex , instart , pos-1);
            root->right = solve(inorder , preorder , preIndex , pos+1 , inend);
            return root;
        }
    }
  public:
    Node *buildTree(vector<int> &inorder, vector<int> &preorder) {
        int preindex = 0;
        return solve(inorder, preorder , preindex , 0 , inorder.size()-1);
        
    }
};
