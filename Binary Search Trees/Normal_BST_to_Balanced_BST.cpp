// t.c : O(n)
// s.c : O(n)
// my approach

/* BST Node Structure
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
    
    Node* findTree(vector<Node*> &arr , int start , int end) {
        if(start > end) {
            return NULL;
        }
        
        int mid = (start + end)/2;
        Node* root = arr[mid];
        
        root -> left = findTree(arr , start , mid-1);
        root -> right = findTree(arr , mid+1 , end);
        
        return root;
    }
    void inorder(Node* root , vector<Node*> &arr) {
        if(root == NULL) return ;
        
        inorder(root->left , arr);
        arr.push_back(root);
        inorder(root->right,arr);
    }
  public:
    Node* balanceBST(Node* root) {
        
        vector<Node*> arr;
        inorder(root,arr);
        
        Node* ans = findTree(arr , 0 , arr.size()-1);
        return ans;
    }
};
