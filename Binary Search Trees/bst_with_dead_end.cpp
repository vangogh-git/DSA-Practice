// t.c : O(n)
// s.c : O(h)

/* Tree Node structure
class Node
{
    int data;
    struct Node *left;
    struct Node *right;

    Node(int x){
        data = x;
        left = right = nullptr;
    }
};*/

class Solution {
    private:
    bool solve(Node* root , int mini , int maxi) {
        if(root == NULL) return false;
        
        if(mini == maxi && root->left == NULL && root->right == NULL)
            return true;
        
        bool left = solve(root->left , mini , root->data-1);
        bool right = solve(root->right , root->data+1 , maxi);
        
        return left or right;
    }
  public:
    bool isDeadEnd(Node *root) {
        
        int maxi = INT_MAX;
        int mini = 1;
        
        return solve(root , mini , maxi);
        
    }
};
