// t.c : O(n)
// s.c : O(h) where h is the recursive stack height

/*
class Node {
  public:
    int data;
    Node *left;
    Node *right;

    Node(int x) {
        data = x;
        left = NULL;
        right = NULL;
    }
}; */

class Solution {
    private:
    pair<int,int> solve(Node* root) {
        if(root == NULL) return {0,0};
        if(root->left== NULL && root->right == NULL) {
            return {1,root->data};
        }
        else {
            pair<int,int> ans;
            pair<int,int> left = solve(root->left);
            pair<int,int> right = solve(root->right);
            if(left.first > right.first) {
                ans.second = root->data + left.second;
            }
            else if(left.first == right.first) {
                ans.second = max(left.second , right.second) + root->data;
            }
            else {
                ans.second = root->data + right.second;
            }
            ans.first = max(left.first , right.first)+1;
            return ans;
        }
    }
  public:
    int sumOfLongRootToLeafPath(Node *root) {
        
        int sum = solve(root).second;
        return sum;
    }
};
