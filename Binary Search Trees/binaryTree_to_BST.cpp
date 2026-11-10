// t.c : O(n log n)
// s.c : O(n)
// my approach

/* The Node structure is
struct Node
{
    int data;
    struct Node *left;
    struct Node *right;

    Node(int val) {
        data = val;
        left = right = NULL;
    }
};
*/
class Solution {
    private:
    void findAns(Node* root , vector<int> arr , int &i) {
        if(root == NULL) return ;
        if(i > arr.size()) return ;
        findAns(root->left,arr,i);
        root-> data = arr[i];
        i++;
        findAns(root->right,arr,i);
    }
    
    void inorder(Node* root , vector<int> &arr) {
        if(root == NULL) return ;
        
        inorder(root->left,arr);
        arr.push_back(root->data);
        inorder(root->right,arr);
    }
  public:
    Node *binaryTreeToBST(Node *root) {
        
        vector<int> arr;
        inorder(root , arr);
        sort(arr.begin(),arr.end());
        int i = 0;
        findAns(root,arr,i);
        return root;
    }
};
